#include "../GuiInstanceHelperTypes.h"
#include "../WorkflowCodegen/GuiInstanceLoader_WorkflowCodegen.h"

#ifndef VCZH_PRESENTATION_REFLECTION_INSTANCELOADERS_GUIINSTANCELOADER_TEMPLATECONTROL
#define VCZH_PRESENTATION_REFLECTION_INSTANCELOADERS_GUIINSTANCELOADER_TEMPLATECONTROL

namespace vl
{
	namespace presentation
	{
		namespace instance_loaders
		{
			using namespace collections;
			using namespace reflection::description;
			using namespace controls;
			using namespace compositions;
			using namespace theme;
			using namespace helper_types;

			using namespace elements;
			using namespace compositions;
			using namespace controls;
			using namespace templates;

			using namespace workflow;
			using namespace workflow::analyzer;

#ifndef VCZH_DEBUG_NO_REFLECTION

/***********************************************************************
GuiVrtualTypeInstanceLoader
***********************************************************************/

			template<typename TControl>
			class GuiTemplateControlInstanceLoader : public Object, public IGuiInstanceLoader
			{
				typedef typename TControl::ControlTemplateType		TTemplate;
				typedef Ptr<WfExpression>							ArgumentRawFunctionType(ArgumentMap&);
				typedef void										InitRawFunctionType(const WString&, Ptr<WfBlockStatement>);
				typedef Func<ArgumentRawFunctionType>				ArgumentFunctionType;
				typedef Func<InitRawFunctionType>					InitFunctionType;

			protected:
				GlobalStringKey								typeName;
				theme::ThemeName							themeName;
				ArgumentFunctionType						argumentFunction;
				InitFunctionType							initFunction;

				virtual void AddAdditionalArguments(types::ResolvingResult& resolvingResult, const TypeInfo& typeInfo, GlobalStringKey variableName, ArgumentMap& arguments, GuiResourceError::List& errors, Ptr<WfNewClassExpression> createControl)
				{
				}
			public:
				static Ptr<WfExpression> CreateThemeName(theme::ThemeName themeName)
				{
					auto presentationExpr = MakePtr<WfTopQualifiedExpression>();
					presentationExpr->name.value = L"presentation";

					auto themeExpr = MakePtr<WfChildExpression>();
					themeExpr->parent = presentationExpr;
					themeExpr->name.value = L"theme";

					auto themeNameExpr = MakePtr<WfChildExpression>();
					themeNameExpr->parent = themeExpr;
					themeNameExpr->name.value = L"ThemeName";

					auto refExpr = MakePtr<WfChildExpression>();
					refExpr->parent = themeNameExpr;
					switch (themeName)
					{
#define THEME_NAME_CASE(TEMPLATE, CONTROL) case theme::ThemeName::CONTROL: refExpr->name.value = L ## #CONTROL; break;
						GUI_CONTROL_TEMPLATE_TYPES(THEME_NAME_CASE)
#undef THEME_NAME_CASE
					default:
						CHECK_FAIL(L"GuiTemplateControlInstanceLoader::CreateThemeName()#Unknown theme name.");
					}
					return refExpr;
				}

			public:
				GuiTemplateControlInstanceLoader(const WString& _typeName, theme::ThemeName _themeName, ArgumentRawFunctionType* _argumentFunction = nullptr, InitRawFunctionType* _initFunction = nullptr)
					:typeName(GlobalStringKey::Get(_typeName))
					, themeName(_themeName)
				{
					if (_argumentFunction) argumentFunction = _argumentFunction;
					if (_initFunction) initFunction = _initFunction;
				}

				GlobalStringKey GetTypeName()override
				{
					return typeName;
				}

				void GetPropertyNames(const TypeInfo& typeInfo, collections::List<GlobalStringKey>& propertyNames)override
				{
					if (CanCreate(typeInfo))
					{
						propertyNames.Add(GlobalStringKey::_ControlTemplate);
					}
				}

				Ptr<GuiInstancePropertyInfo> GetPropertyType(const PropertyInfo& propertyInfo)override
				{
					if (propertyInfo.propertyName == GlobalStringKey::_ControlTemplate)
					{
						auto info = GuiInstancePropertyInfo::Assign(TypeInfoRetriver<TemplateProperty<TTemplate>>::CreateTypeInfo());
						return info;
					}
					return 0;
				}

				bool CanCreate(const TypeInfo& typeInfo)override
				{
					return typeName == typeInfo.typeName;
				}

				Ptr<workflow::WfBaseConstructorCall> CreateRootInstance(GuiResourcePrecompileContext& precompileContext, types::ResolvingResult& resolvingResult, const TypeInfo& typeInfo, ArgumentMap& arguments, GuiResourceError::List& errors)override
				{
					auto createControl = MakePtr<WfBaseConstructorCall>();
					createControl->type = GetTypeFromTypeInfo(TypeInfoRetriver<TControl>::CreateTypeInfo().Obj());
					createControl->arguments.Add(CreateThemeName(themeName));
					return createControl;
				}

				Ptr<workflow::WfStatement> CreateInstance(GuiResourcePrecompileContext& precompileContext, types::ResolvingResult& resolvingResult, const TypeInfo& typeInfo, GlobalStringKey variableName, ArgumentMap& arguments, GuiResourceTextPos tagPosition, GuiResourceError::List& errors)override
				{
					CHECK_ERROR(CanCreate(typeInfo), L"GuiTemplateControlInstanceLoader::CreateInstance()#Wrong type info is provided.");

					auto block = MakePtr<WfBlockStatement>();
					{
						auto controlType = TypeInfoRetriver<TControl*>::CreateTypeInfo();

						auto createControl = MakePtr<WfNewClassExpression>();
						createControl->type = GetTypeFromTypeInfo(controlType.Obj());
						createControl->arguments.Add(CreateThemeName(themeName));

						if (argumentFunction)
						{
							createControl->arguments.Add(argumentFunction(arguments));
						}
						AddAdditionalArguments(resolvingResult, typeInfo, variableName, arguments, errors, createControl);

						auto refVariable = MakePtr<WfReferenceExpression>();
						refVariable->name.value = variableName.ToString();

						auto assignExpr = MakePtr<WfBinaryExpression>();
						assignExpr->op = WfBinaryOperator::Assign;
						assignExpr->first = refVariable;
						assignExpr->second = createControl;

						auto assignStat = MakePtr<WfExpressionStatement>();
						assignStat->expression = assignExpr;
						block->statements.Add(assignStat);
					}

					if (initFunction)
					{
						initFunction(variableName.ToString(), block);
					}
					return block;
				}

				Ptr<workflow::WfStatement> AssignParameters(GuiResourcePrecompileContext& precompileContext, types::ResolvingResult& resolvingResult, const TypeInfo& typeInfo, GlobalStringKey variableName, ArgumentMap& arguments, GuiResourceTextPos attPosition, GuiResourceError::List& errors)override
				{
					auto block = MakePtr<WfBlockStatement>();

					FOREACH_INDEXER(GlobalStringKey, prop, index, arguments.Keys())
					{
						if (prop == GlobalStringKey::_ControlTemplate)
						{
							auto& propertyValue = arguments.GetByIndex(index)[0];
							if (propertyValue.expression)
							{
								auto refValue = MakePtr<WfReferenceExpression>();
								refValue->name.value = variableName.ToString();

								auto refProp = MakePtr<WfMemberExpression>();
								refProp->parent = refValue;
								refProp->name.value = L"ControlTemplate";

								auto assign = MakePtr<WfBinaryExpression>();
								assign->op = WfBinaryOperator::Assign;
								assign->first = refProp;
								assign->second = propertyValue.expression;

								auto stat = MakePtr<WfExpressionStatement>();
								stat->expression = assign;
								block->statements.Add(stat);
							}
						}
					}

					if (block->statements.Count() > 0)
					{
						return block;
					}
					return nullptr;
				}
			};
#endif
		}
	}
}
#endif

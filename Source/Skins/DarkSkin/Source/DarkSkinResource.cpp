﻿#include "DarkSkin.h"

namespace vl
{
	namespace presentation
	{
		namespace user_resource
		{
			using namespace collections;
			using namespace stream;
			using namespace controls;

			class DarkSkinResourceReader
			{
			public:
				static const vint parserBufferLength = 1702; // 4351 bytes before compressing
				static const vint parserBufferBlock = 1024;
				static const vint parserBufferRemain = 678;
				static const vint parserBufferRows = 2;
				static const char* parserBuffer[2];

				static void ReadToStream(vl::stream::MemoryStream& stream)
				{
					DecompressStream(parserBuffer, true, parserBufferRows, parserBufferBlock, parserBufferRemain, stream);
				}
			};

			const char* DarkSkinResourceReader::parserBuffer[] = {
				"\xFF\x10\x00\x00\x9E\x06\x00\x00\x4A\x00\x01\x82\x80\x00\x81\x80\x1E\x29\x65\x73\x2F\x35\x32\x3B\x31\x33\x26\x65\x74\x21\x24\x31\x32\x88\x10\x27\x61\x6D\x25\x3D\x12\x12\x10\x10\x2B\x65\x72\x33\x29\x3F\x36\x34\x8F\x18\x2E\x30\x22\x1E\x1C\x1C\x21\x32\x38\x65\x6E\x24\x31\x93\x31\x35\x85\x17\x2C\xAF\x08\x8A\x8C\x86\x84\x88\x89\x14\x92\xBE\x05\x03\x82\x80\x05\xA2\x01\xC7\x81\x89\x2E\x33\x3A\x88\x37\x0E\x8D\x08\xA0\x02\xAB\xA5\xA7\xA7\x0E\xD3\x34\x39\x3C\x35\x33\x01\xA9\x5F\x81\x84\x2F\x33\x34\x03\xA8\xB3\x01\xD4\x25\x38\x34\x3F\x07\xA8\xB7\x01\xC3\x2C\x21\x33\x3B\x38\x8C\x8D\x08\xE3\x2F\x32\x34\x33\xA8\x01\xB0\x45\xCA\x81\xC2\x84\x21\x32\x39\x35\x53\x6B\x29\x2E\x3E\xBE\xBE\x05\xA9\x06\x10\xC2\x82\x25\x3C\x38\x3B\x92\x8D\x99\xC3\xC8\xA2\xC3\xB3\x31\x3A\x1A\xEE\x34\x3E\xB1\x03\xAA\x01\xA9\x10\x28\xD3\xD4\xB5\x34\x37\xC5\x32\x9E\xA0\xF1\x94\x3E\x5B\xA9\xDA\x83\x9E\xAC\x83\x25\x94\x3B\xD8\x9C\x1E\x5A\xDC\x89\x8C\x91\xE5\xAC\x10\x37\x19\x9B\xA2\x03\x1E\x96\x31\x31\x3A\x6C\x74\x2D\x0F\x26\x39\x92\x39\x34\x33\xAB\xBC\x1A\xBC\x33\xBE\x1F\x11\x46\x61\xE2\xFC\x1F\x14\xEE\xEE\xF2\xC5\xE5\x04\xFB\xA6\xE0\xE6\x8C\x8E\x23\x53\x2D\xC5\x33\x34\x38\x92\x37\xD3\xD5\xF2\x37\xE9\xEC\x96\xF2\x39\xDF\x62\x73\x79\x79\x6F\x1D\x70\x80\x0F\x62\x2B\x1F\x7F\x77\x30\x30\x07\x0D\x10\x43\x03\x14\x79\x82\x0B\xA8\x7C\x7A\x7A\x16\x82\x73\x1D\x4E\xB9\x7E\x58\x59\x51\x1F\x8C\x19\x1A\x53\x9A\x65\x80\x03\x87\x03\x5F\x8D\x13\x88\x63\x26\x8A\x65\x64\x48\x70\x80\x02\x14\x69\x22\x12\x18\x66\x2E\x8D\x62\x8F\x40\x32\x93\x13\x1A\x1C\x05\xAC\x19\x8D\x63\x80\x43\x40\x60\x15\x61\x22\x13\x92\x5F\x07\x13\x5D\x91\x5A\x6B\x74\x12\x13\x1B\x78\x0B\x93\x55\x02\x57\x82\x44\x17\x1B\x05\x8E\x57\x74\x1C\x56\xB1\x82\x65\x40\x57\x0B\x64\x1B\x1B\x77\x21\x95\x50\x03\x53\x6C\x91\x43\x11\x61\x23\x17\x11\x4C\xBB\x6E\x16\x19\x1A\x67\x03\x95\x68\x52\x45\x82\x40\x63\x10\x70\x20\x93\x54\x51\x7C\x93\x55\x55\x51\x87\x80\xA0\x1F\x6E\x6D\x30\x12\x1D\x42\x73\x25\x14\x18\x05\x53\x54\xA2\x5A\x61\x88\x4A\x6E\x1B\x4E\x0B\x4D\x45\x1A\x0B\x63\x01\xAD\x9D\x40\x28\x82\x4F\x87\x5D\x65\x02\x63\x41\x67\x98\x89\x6B\x63\xA8\x54\x46\xA2\x42\x13\x7B\x6D\x11\x18\x1B\x4C\x63\x1C\x19\x1D\x33\x69\x68\x52\xAF\x00\x2E\x0E\x0B\x0B\xC2\x84\xB3\xB0\x9C\x63\x15\x19\x12\x0B\x68\x30\xA1\x07\x54\xCF\x81\x48\x42\x19\x5D\x75\x77\x7D\xAE\xBB\xB3\x49\x0F\x54\xDB\x81\x45\xB3\xB7\xC3\x93\xB5\xB6\x7D\x25\x6F\x04\x15\x1E\x30\x6E\x43\x1F\x8F\x69\x30\x17\x66\x48\x2F\x07\x15\x1D\x1A\xE2\xB4\x74\xBA\x1B\x50\x3B\xA7\x1B\x62\xCC\xB0\xAE\x9B\x9A\x02\x53\x1D\xA6\x43\x46\x05\x83\x4E\x1C\x3B\x82\x4D\x8F\xC0\x65\x3E\x5B\x03\x54\x0F\xC1\x40\x17\xA3\x7A\x4D\xA9\x19\x57\x7D\x53\x5B\x9C\x88\x6F\x5D\xC1\x5F\x5C\x75\x68\xA9\x5F\x5E\x64\x03\x1E\xC5\x51\x70\x40\x04\x47\x61\x73\x1A\xAA\x0E\x0E\x54\x28\x15\x1A\x46\x18\x13\x55\xCD\x40\x2B\xEB\x1D\xCB\x62\x2F\xD4\x66\x65\x49\x6A\x4D\xA3\x5D\x6F\x1A\x13\x55\xD0\xCE\x98\xBB\xCE\x1B\xCB\x43\x32\xC3\x1B\x1A\x53\xB8\x11\xD0\x1C\x43\xE5\x1D\x07\x54\x57\xC8\xDC\xCA\xCB\x3A\x12\x13\x44\x49\x3E\xD7\x6E\x1B\xD4\x55\xDF\x03\x56\xD9\x5A\xFA\xCC\xD5\x6C\xA1\x74\x1C\x11\x92\xAD\x64\xD5\x45\x19\x21\x13\x55\xDD\xDA\x4A\xEF\xCC\xDB\x6C\x6A\x6C\x51\xD6\xDC\xBD\x60\x03\x56\xE0\x78\xEB\xD4\x5A\x6C\xA2\x56\x16\x4F\x1D\x21\x40\xE5\x1B\xD1\x45\x50\xE9\xCD\xDE\x3A\x0C\xA7\x8F\xDF\x33\xD4\xD3\xDC\x09\x53\x5C\xE5\xE0\xCF\x3A\x05\x18\x1C\x1C\x61\x32\x4B\x63\x19\x2E\x7A\x52\x1D\x45\x7B\x4E\xE4\xE1\x51\xAF\xD3\xEC\xD5\x12\xBD\x6D\x12\x11\x9C\x6B\x27\x10\x91\x1D\x32\x4E\xE6\x0B\x54\xBF\xDF\xEB\xD2\x0E\x22\x8E\x5A\xE1\x19\x77\x3B\x6B\xAD\x1B\x6E\x08\x15\x1B\x44\x8D\xD9\xE5\xD4\xE4\x03\x52\xE9\xD0\xD7\xC5\xF4\x17\xF3\x1D\x8E\xD4\xF2\x42\xF5\x5B\xE0\xED\xDE\xDB\x23\xB4\x1D\xF6\xD1\x02\x72\xE2\xFB\xA3\x65\x1B\xFE\xE0\x07\x53\x70\xF2\xF2\xDE\x73\xD0\x19\x1B\xD3\xD1\xC2\xD3\xDE\xF7\x01\x60\xFA\xD8\xE8\x47\x1B\x74\x1C\x18\x7A\x7F\xDE\x17\x03\x2A\x07\x93\x7C\xF1\x70\x6C\x0C\xC7\x59\x6D\x28\x0F\x8A\x7F\xF0\x53\x08\x0D\xBD\x34\x0F\x33\x74\x0B\x09\x19\x79\x0E\x70\x11\x13\x2E\x83\x0A\x94\x46\x8D\x25\x23\x0A\xAA\x69\x0C\x0E\x41\x1B\x3C\x9A\x0E\x78\x6D\xA2\x2D\x82\x82\x2F\x62\x87\x8D\x6E\x01\x6D\x92\x33\x0E\x71\x2D\x13\x29\x0E\xA1\x85\x47\x19\xB0\x4C",
				"\x0D\x5D\x32\x0D\x1E\x44\x00\x48\x38\x27\x4F\x0E\x34\x95\x32\xD8\x0E\x77\x05\xA9\x0D\x8C\x87\x23\x8E\x0F\x0F\xC1\x89\x0E\xDA\x73\x61\x7B\x2C\x87\x6D\xFA\x57\x70\x74\x19\xA5\x23\x8A\x21\x3C\x82\xF4\x73\x69\x05\xA9\x25\x88\x8A\x3E\x82\x82\xE8\x24\x72\x27\x1A\xA3\x6B\x8C\xBD\x37\x6D\x51\x72\x80\x87\xAE\x7D\x87\x8B\x02\x90\x22\x1B\x75\x0E\x80\xAC\x5B\x89\x7C\xC3\x7E\x8A\x14\x82\x8E\x70\x39\x83\x24\x8E\x5C\x81\x93\x1D\xEE\x09\x08\xBD\x2E\x0F\x6D\x62\x11\x6C\x1C\xE5\x03\x05\xA9\x15\x90\x8D\x25\x2F\x6E\x1C\x67\x05\x0C\x37\x8E\x73\x05\x53\x20\x94\x26\x8F\x96\x30\x4E\x84\x8F\x0D\x46\x88\x4D\x12\xBF\x6F\x8D\x02\xA5\x08\x05\x53\x30\x97\x28\x9A\x9C\x93\x12\xAE\x32\x4A\x4A\x80\x6B\x24\x97\x95\x28\x5E\xB5\x8A\x90\x53\x16\x54\x10\x9E\x93\x92\x51\x85\x2E\x98\xBF\x8B\x91\x30\xB7\x5C\x0D\x53\xA9\x90\x89\xC4\x8E\x95\xF0\x45\x23\x9B\x64\x91\x8B\x99\x40\x8D\x91\x26\x8C\x8E\x70\x59\x85\x2E\x9B\xD6\x93\x84\x36\xEC\x06\x97\x13\x91\x9A\x73\xBD\x2F\x89\x51\x6A\x91\x9C\xA0\x5C\x4C\x0D\x5E\x4D\x5E\xF3\x50\x72\x0E\xC7\x65\x03\x2A\xF7\x83\x97\x96\x5D\x44\x0F\x2F\x7A\x8C\x8F\x93\x80\x85\x51\x02\xAD\x9D\xB1\x6F\x99\x9E\x70\x17\x87\x24\x9E\x75\x28\x86\xB5\x8B\x4A\x3F\x6D\x0E\x8F\x40\x43\x99\x5C\xAD\x90\x9D\x65\x0D\x87\x40\x2F\x89\x91\x97\x48\x0B\xA2\x41\x48\x09\xE9\x64\x0D\x2A\xC7\x59\x03\x2A\x27\xAA\x83\x47\xBF\x41\x49\xF3\x48\x2E\x7F\x94\x68\x08\x15\x2B\x78\x7F\x7A\x81\xA7\x83\x7F\x9F\x7F\xF0\x4C\x05\x0C\x33\x34\x08\xA4\x15\xAC\x95\x1F\xC8\x21\x83\x8E\xBA\x03\x62\x6F\x1A\x74\xA4\x37\x76\xA6\x57\xBC\x93\x20\xBE\x86\xA8\x8D\x67\x08\x0D\x9F\xAC\xA1\xA8\x4B\x93\x92\xFC\x45\x2B\xAB\x3A\x80\xAC\x0D\xEE\x73\x92\x21\x82\x28\x90\x40\xAF\x63\x4B\x70\x1F\xAB\x39\xE5\x6A\x8A\x05\x96\x0F\xAB\x22\xB2\x25\x49\x93\x99\xA5\xA2\x35\xAD\x8E\x6F\xB7\xA9\x03\x93\x9C\x7E\x00\x30\xA4\x6B\x56\x13\xA4\xEE\x79\x78\xA3\xB1\x81\x25\xAC\x3A\xA7\xAD\x92\x73\x97\x61\xB5\xB3\x6B\x03\x53\x30\xB2\x02\xC8\x42\x0C\xC6\x84\xB5\x6A\x15\x13\x29\x66\x93\xB9\x49\x0E\xB8\xA2\x81\x4D\x10\x3A\x7D\x2E\x3E\x0D\x32\x23\x7C\x80\x18\xAF\xAA\x40\x51\xA6\xAC\x1D\x13\x0F\x74\x5D\x24\xB6\x69\xD1\x48\xB4\xB6\x88\x2C\xA3\xAD\xBF\x9C\x53\x8E\xB1\x71\xC1\x79\xA4\x72\xFF\x96\x8A\xED\x16\xAE\x70\x0F\x13\x2E\xB8\xA0\xB1\x25\x1D\x65\x96\x33\xCB\xB3\x69\x9F\x45\x30\xB9\x1D\xFB\x90\x9F\x7E\xAD\x5C\xB9\x29\x80\x48\xF7\x62\xA6\x6F\xDF\x9C\x6C\xBA\x08\xBC\xB5\x19\x67\x85\x28\xF2\x93\xBF\xA0\xD6\xB0\x0E\x33\xC7\x8B\x95\xAC\xAE\x92\xA3\x02\x38\xB5\x62\xB0\x68\xBC\x7F\x8A\xBE\x77\xC0\x7E\xBA\xF8\x75\xB7\xBA\x13\xB8\x92\xA8\xBB\x96\x92\x7E\xC3\x70\xBD\xF4\x8C\xBD\x37\x4D\xB8\xA2\x64\xC5\x2B\xC1\xF3\xBC\x9F\x4B\x59\x97\xB7\x80\xCC\x65\x0E\xA7\x2F\x0D\x0D\x75\x5D\x9D\x81\x26\xA8\xA5\x09\xF4\xBD\x40\xF6\x30\x0E\xE3\x37\x65\x28\x12\xF5\x8D\x4C\x32\x2B\x87\x24\xFE\x20",
				};

			class DarkSkinResourceLoaderPlugin : public Object, public IGuiPlugin
			{
			public:

				GUI_PLUGIN_NAME(GacGen_DarkSkinResourceLoader)
				{
					GUI_PLUGIN_DEPEND(GacUI_Res_Resource);
					GUI_PLUGIN_DEPEND(GacUI_Res_TypeResolvers);
#ifndef VCZH_DEBUG_NO_REFLECTION
					GUI_PLUGIN_DEPEND(GacUI_Instance_Reflection);
					GUI_PLUGIN_DEPEND(GacUI_Compiler_WorkflowTypeResolvers);
#endif
				}

				void Load()override
				{
					List<GuiResourceError> errors;
					MemoryStream resourceStream;
					DarkSkinResourceReader::ReadToStream(resourceStream);
					resourceStream.SeekFromBegin(0);
					GetResourceManager()->LoadResourceOrPending(resourceStream, GuiResourceUsage::InstanceClass);
				}

				void Unload()override
				{
				}
			};
			GUI_REGISTER_PLUGIN(DarkSkinResourceLoaderPlugin)
		}
	}
}

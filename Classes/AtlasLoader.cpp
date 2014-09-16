#include "AtlasLoader.h"

AtlasLoader::AtlasLoader()
{
}

AtlasLoader* AtlasLoader::sharedAtlasLoader = nullptr;

bool AtlasLoader::init()
{
	return true;
}

AtlasLoader* AtlasLoader::getInstance()
{
	if (this->sharedAtlasLoader == nullptr) {
		sharedAtlasLoader = new AtlasLoader;
		if (sharedAtlasLoader->init() == false) {
			CCLOG("AtlasLoader init error!");
			delete sharedAtlasLoader;
			sharedAtlasLoader = nullptr;
			return NULL;
		}
		return sharedAtlasLoader;
	}
}

void AtlasLoader::loadAtlas(string filename)
{
	
}
#ifndef __ATLAS_LOADER_H__
#define __ATLAS_LOADER_H__

#include "cocos2d.h"

using namespace std;
USING_NS_CC;

typedef struct _atlas{
	char name[255];
	int width;
	int height;
	Point start;
	Point end;
} Atlas;

class AtlasLoader
{
public:
	/**
	*  The default constructor.
	*/
	AtlasLoader();

	/**
	*  Destroys the instance of AtlasLoader.
	*/
	static void destroyInstance();

	/**
	* Load the atlas of file
	* This function load the image, so it will be delay the main thread
	* exp. AtlasLoader::getInstance()->loadAtlas("atlas.txt");
	*/
	void loadAtlas(string filename);

	/**
	* Load the atlas of file
	* you can load the texture in asyc method then use this function
	*/
	void loadAtlas(string filename, Texture2D *texture);

	/**
	* Get the sprite by name.
	* Warm: you should use this function after add atlas.png to getTextureCache,
	* or this function will take you a long time to load texture.
	* exp. SpriteFrame *bg_day = AtlasLoader::getInstance()->getSpriteFrameByName("bg_day");
	*/
	SpriteFrame* getSpriteFrameByName(string name);

	/**
	*  Get the instance of AtlasLoader
	*/
	AtlasLoader* getInstance();

protected:

	static AtlasLoader* sharedAtlasLoader;

	/**
	*  Initializes the instance of AtlasLoader.
	*
	*  @note When you are porting Cocos2d-x to a new platform, you may need to take care of this method.
	*        You could assign a default value to _defaultResRootPath in the subclass of FileUtils(e.g. FileUtilsAndroid). Then invoke the FileUtils::init().
	*  @return true if successed, otherwise it returns false.
	*
	*/
	virtual bool init();

	Map<std::string, SpriteFrame*> _spriteFrames;
};


#endif
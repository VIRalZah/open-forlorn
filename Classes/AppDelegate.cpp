#include "AppDelegate.h"
#include "MenuScene.h"
#include <thread>

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
}

const Size designResolution = Size(480, 320);

bool AppDelegate::applicationDidFinishLaunching()
{
	auto director = Director::getInstance();
	if (!director->getOpenGLView())
	{
#if (AX_TARGET_PLATFORM == AX_PLATFORM_WIN32)
		auto glView = GLView::create("HelloCpp", designResolution.width, designResolution.height);

		glView->setVSyncEnabled(true);
		glView->setResizePolicy(kResizeByAspectRatio);
#else
		glView = GLView::create();
#endif /* CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 */
		glView->setDesignResolutionSize(designResolution.width, designResolution.height, kResolutionNoBorder);

		director->setOpenGLView(glView);
	}

	FileUtils::getInstance()->addSearchPath("Resources");

	director->setDisplayStats(true);
	director->runWithScene(MenuLayer::scene());

    return true;
}

void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();
}
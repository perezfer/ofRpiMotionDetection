#include "ofMain.h"
#include "ofApp.h"
//#include "ofAppNoWindow.h"

//========================================================================
int main(int argc, char *argv[] ){


    //ofAppBaseWindow* pWindow = new ofAppNoWindow();
	ofSetLogLevel(OF_LOG_VERBOSE);
	//ofSetupOpenGL(pWindow,1280,720, OF_WINDOW);
	ofSetupOpenGL(1280,720, OF_WINDOW);			// <-------- setup the GL context
	ofApp *app = new ofApp();
	if (argc > 1)
		app->RPiId=argv[1];
	else
		app->RPiId="X";
	ofRunApp( app );

}

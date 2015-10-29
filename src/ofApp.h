#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#ifdef __arm__
#include "ofxCvPiCam.h"
#endif
#include "ConsoleListener.h"
#include "ofxOsc.h"
#include "ofxOpenCv.h"
#include "ofxGui.h"

#define NUM_MSG_STRINGS 20
#define OSC_PORT 8001

using namespace ofxCv;
using namespace cv;


class ofApp : public ofBaseApp, public SSHKeyListener{

	public:

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void fpsChanged(int & fps);
		void learningTimeChanged(int &learningTime);
		void backgroundThresholdChanged(int &backgroundThreshold);

		// program ID
		string RPiId;
	
    private:
	
		int framenr;
	
#ifdef __arm__
		ofxCvPiCam cam;
#else
		ofVideoGrabber cam;
#endif
	
		// OSC
		ofxOscSender sender;
		ofxOscReceiver receiver;
	
		// Cv
		ofPixels pix;
		int sent_blobs;
		ofImage thresholded;
		Mat frame, frameProcessed, accum;
		ofxCv::RunningBackground background;
		void onCharacterReceived(SSHKeyListenerEventData& e);
		ofxCvContourFinder 	contourFinder;
		ofxCvGrayscaleImage    grayImage;
	    ofImage image;
		ofPixels tosave;
	
		// Settings
		ofxPanel gui;
		ofParameter<int> cutDown;
		ofParameter<int> fps;
		ofParameter<int> learningTime;
		ofParameter<float> accumFactor;
		ofParameter<int> backgroundThreshold;
		ofParameter<int> erodeFactor;
		ofParameter<int> dilateFactor;
		ofParameter<int> medianBlurFactor;
		ofParameter<int> minContourArea;
		ofParameter<int> maxContourArea;
		ofParameter<int> maxContours;
		ofParameter<bool> useAccum;
	string filename_save;
	
		ofRectangle ROI;
		string exposureModes[14];
		string exposureMeteringModes[5];
		string awbModes[11];
		string flickerAvoids[11];
		ofParameter<float> roiX;
        ofParameter<float> roiY;
        ofParameter<float> roiW;
        ofParameter<float> roiH;
        ofParameter<int>  exposureCompensation;
        ofParameter<int> exposureMeteringMode;
        ofParameter<int> exposureMode;
        ofParameter<int> awbMode;
        ofParameter<int> shutterSpeed;
        ofParameter<int> flickerAvoid;
		int awbModeInt;
        int exposureModeInt;
        int exposureMeteringModeInt;
		int flickerAvoidInt;
	
		ConsoleListener consoleListener;
};


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
    
    myCamera.initGrabber(320, 240);
    myFont.load("avenir-next-bold.ttf", 15);
    
    mySender.setup(NODE_HOST, NODE_PORT);//指定したIPアドレスとポート番号でnodeサーバーに接続
    
    std::string file = "../../ms_emotion/facedata.json";
    
    // Now parse the JSON
    bool parsingSuccessful = result.open(file);
    
    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << result.getRawString();
        
        // now write pretty print
        if (!result.save("example_output_pretty.json", true))
        {
            ofLogNotice("ofApp::setup") << "example_output_pretty.json written unsuccessfully.";
        }
        else
        {
            ofLogNotice("ofApp::setup") << "example_output_pretty.json written successfully.";
        }
        
        // now write without pretty print
        if (!result.save("example_output_fast.json", false))
        {
            ofLogNotice("ofApp::setup") << "example_output_pretty.json written unsuccessfully.";
        }
        else
        {
            ofLogNotice("ofApp::setup") << "example_output_pretty.json written successfully.";
        }
        
    }
    else
    {
        ofLogError("ofApp::setup")  << "Failed to parse JSON" << endl;
    }
    
    pushButton = false;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    myCamera.update();
    
    std::string file = "../../ms_emotion/facedata.json";
    result.open(file);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(50);
    ofDrawRectangle(20, 320, 320, 240);
    
    ofSetColor(255);
    ofDrawBitmapString(ofToString(ofGetFrameRate()), ofGetWidth()-60, 20);
    myFont.drawString("Camera Image", 20, 30);
    myCamera.draw(20, 40);
    myFont.drawString("Saved Image", 20, 310);
    savedImage.load("myFace/myFace.jpg");
    if(pushButton){
        savedImage.draw(20, 320);
    }
    myFont.drawString("Search Result", 360, 30);
    
    float anger = result[0]["scores"]["anger"].asDouble();
    float contempt = result[0]["scores"]["contempt"].asDouble();
    float disgust = result[0]["scores"]["disgust"].asDouble();
    float fear = result[0]["scores"]["fear"].asDouble();
    float happiness = result[0]["scores"]["happiness"].asDouble();
    float neutral = result[0]["scores"]["neutral"].asDouble();
    float sadness = result[0]["scores"]["sadness"].asDouble();
    float surprise = result[0]["scores"]["surprise"].asDouble();
        
    ofDrawBitmapString("anger = " + ofToString(anger), 360, 80);
    ofDrawBitmapString("contempt = " + ofToString(contempt), 360, 100);
    ofDrawBitmapString("disgust = " + ofToString(disgust), 360, 120);
    ofDrawBitmapString("fear = " + ofToString(fear), 360, 140);
    ofDrawBitmapString("happiness = " + ofToString(happiness), 360, 160);
    ofDrawBitmapString("neutral = " + ofToString(neutral), 360, 180);
    ofDrawBitmapString("sadness = " + ofToString(sadness), 360, 200);
    ofDrawBitmapString("surprise = " + ofToString(surprise), 360, 220);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key ==' '){
        myImage.grabScreen(20, 40, 320, 240);
        myImage.save("myFace/myFace.jpg", OF_IMAGE_QUALITY_HIGH);
        pushButton = true;
        
        ofxOscMessage m;
        m.setAddress("/button/space");
        m.addStringArg("true");
        mySender.sendMessage(m);

    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}

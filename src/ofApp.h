#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxJSON.h"

#define NODE_HOST "127.0.0.1"//受信側(Node)のIPアドレス
#define NODE_PORT 8000//受信側(node)のポート番号

class ofApp : public ofBaseApp{
    
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
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofVideoGrabber myCamera;
    ofImage myImage;//写真を保存
    ofImage savedImage;//保存した写真を表示
    bool saveImage;
    bool pushButton;
    ofTrueTypeFont myFont;
    
    ofxOscSender mySender;//OSCメッセージを送信するインスタンス
    
    string myData;//受信したデータ
    string myJson;
    ofxJSONElement result;
    
};

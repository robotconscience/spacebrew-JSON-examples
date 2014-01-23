#include "testApp.h"

ofVec2f point;
ofVec2f localPoint;

//--------------------------------------------------------------
void testApp::setup(){
    Spacebrew::Config config;
    config.clientName = "Spacebrew OF custom object example";
    config.addSubscribe("ofPoint", "point2d");
    config.addPublish("ofPoint", "point2d", "");//"{\"x\":0, \"y\": 0}");
    
    spacebrew.connect( Spacebrew::SPACEBREW_CLOUD, config );
    ofAddListener(spacebrew.onMessageEvent, this, &testApp::onSpacebrewMessage);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    ofEllipse(point, 20, 20);
    ofSetColor(0);
    ofEllipse(localPoint, 20,20);
    localPoint.set(mouseX, mouseY);
    
    // one way to send JSON
    spacebrew.send("ofPoint", "point2d", "{\"x\":" + ofToString(round(mouseX)) + ", \"y\":" + ofToString(round(mouseY))+ "}");
    
    // OR
    /*
    Json::Value pt = Json::Value( Json::objectValue );
    pt["x"] = round(mouseX);
    pt["y"] = round(mouseY);
    spacebrew.send("ofPoint", "point2d", pt.toStyledString());
    */
    
}

//--------------------------------------------------------------
void testApp::onSpacebrewMessage( Spacebrew::Message & m ){
    if ( m.type == "point2d"){
        Json::Value  pointJSON;
        Json::Reader reader;
        reader.parse(m.value, pointJSON);
        
        point.x = pointJSON["x"].asInt();
        point.y = pointJSON["y"].asInt();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableLighting();
    ofEnableDepthTest();
    light.setup();
    light.enable();
    light.setPosition(0,800,200);

    cam.setFarClip(ofGetWidth()*100);
	cam.setNearClip(0.1);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float time = ofGetElapsedTimef();

    cam.begin();
    ofSetColor(125,125,125);

    drawSmallBoxes(time);
    drawRoom(time);

    cam.end();
}

void ofApp::drawRoom(float time) {
    int radius = ofGetHeight()/2;
    int size = 5000;
    int separation = size + 200;
    float remainder = std::fmod(100 * time, separation);

    int x_gap = 40;
    int y_gap = 500;
    for (int i = separation; i > -100 * separation; i -= separation) {
        float z = i + remainder;
        ofDrawBox(x_gap + size / 2, y_gap + size / 2, z, size);
        ofDrawBox(x_gap + size / 2, -y_gap - size / 2, z, size);
        ofDrawBox(-x_gap - size / 2, y_gap + size / 2, z, size);
        ofDrawBox(-x_gap - size / 2, -y_gap - size / 2, z, size);
    }
}

void ofApp::drawSmallBoxes(float time) {
    int radius = ofGetHeight()/4;
    int separation = 500;
    float remainder = std::fmod(100 * time, separation);
    int size = 100;

    for (int i = separation; i > -100 * separation; i -= separation) {
        float z = i + remainder;
        ofDrawBox(radius, radius, z, size);
        ofDrawBox(radius, -radius, z, size);
        ofDrawBox(-radius, radius, z, size);
        ofDrawBox(-radius, -radius, z, size);
    }
}

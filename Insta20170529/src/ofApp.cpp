#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Sphere");

	this->radius = 250;
}

//--------------------------------------------------------------
void ofApp::update(){

	this->locations.clear();

	this->span = 10;
	float noise_param = span * 50.f;
	
	for (int i = 0; i < 360; i += this->span) {
		for (int j = this->span; j < 180; j += this->span) {
			int x = radius * cos(i * DEG_TO_RAD) * sin(j * DEG_TO_RAD);
			int y = radius * sin(i * DEG_TO_RAD) * sin(j * DEG_TO_RAD);
			int z = radius * cos(j * DEG_TO_RAD);

			ofVec3f location = ofVec3f(x, y, z);
			float noise_value = ofNoise(x / noise_param, y / noise_param, z / noise_param, ofGetFrameNum() * 0.02);
			if (noise_value > 0.6) {
				location *= 1.5;
				
			}
			this->locations.push_back(location);

		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	this->cam.begin();
	ofRotate(ofGetFrameNum() % 360);

	ofSetLineWidth(1.f);
	ofSetColor(255);
	for (ofVec3f& location : locations) {
		for (ofVec3f& s_location : locations) {
			float distance = location.distance(s_location);
			if (location.length() > this->radius - this->span && location.length() < this->radius + this->span && distance < 50) {
				ofSetColor(0, 255, 255);
				ofLine(location, s_location);
			}
			else if (location.length() > this->radius * 1.45 && distance < 120) {
				ofSetColor(255, 255, 0);
				ofLine(location, s_location);
			}
		}
		//ofSphere(location, 5);
	}

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

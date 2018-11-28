#include "gl.h"
#include <GLFW/glfw3.h>

#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include <vecmath.h>
#include "tutte.h"

using namespace std;

// initial stuff
vector<Vector3f> vecv;
vector<Vector3f> vecn;
vector<vector<unsigned>> vecf;


string replaceChar(string input, char a, char b) {
	string output = input;
	for (unsigned int i = 0; i < input.length(); ++i) {
		if (input[i] == a){
			output[i] = b;
		}
		else {
			output[i] = input[i];
		}
	}
	return output;
}

void getObjMesh(string filename) {
	// draw obj mesh here
	// read vertices and face indices from vecv, vecn, vecf
	ifstream infile(filename);
	string line;
	while (getline(infile, line)) {
		istringstream iss(line);
		GLfloat x, y, z;
		string prefix;
		string vertex = "v";
		string vnormal = "vn";
		string face = "f";
		if (iss >> prefix >> x >> y >> z) {
			// case for vertices
			if (prefix == vertex) {
				vecv.push_back(Vector3f(x, y, z));
			}
			else if (prefix == vnormal) {
				vecn.push_back(Vector3f(x, y, z));
			}
			else {
				std::cout << line << " useless line\n";
			}
		}
	}

	infile.clear();
	infile.seekg(0, std::ios::beg);
	while (getline(infile, line))
	{
		line = replaceChar(line, '/', ' ');
		istringstream iss(line);
		string prefix;
		string face = "f";
		unsigned int a, b, c, d, e, f, g, h, i;
		if (iss >> prefix >> a >> b >> c >> d >> e >> f >> g >> h >> i) {
			if (prefix == face) {
				vecf.push_back(vector<unsigned>({ a, b, c, d, e, f, g, h, i }));
			}
		}
	}
}

void getTutte(vector<Vector3f> vertices) {
    // method for asking the Tutte embedding code to transform the vertices from 
    // our object file
    vector<Vector2f> transform;
    flatten(vertices, transform);
}

void main() {
    // not sure what the main thing will be yet
}
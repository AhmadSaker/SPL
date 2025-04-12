#pragma once 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;
vector<vector<string>> readConfigFile(const string& configFilePath);
void cutTheExtra(vector<vector<string>>& vec);
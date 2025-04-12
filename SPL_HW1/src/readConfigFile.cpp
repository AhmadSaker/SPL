#include "readConfigFile.h"


vector<vector<string>> readConfigFile(const string& configFilePath)
{
    ifstream inputFile(configFilePath);// open the file for reading
    vector<vector<string>> output;
    if (inputFile.is_open())
    {
        // read data from the file
        string line;
        while (getline(inputFile, line))
        {   
            // variable to store token obtained from the original string
            string s;
            // constructing stream from the string
            stringstream ss(line);
            vector<string> lineVec;
            while (getline(ss, s, ' '))
            {
                // store token string in the vector
                if ( s!= "")
                {
                    lineVec.push_back(s);
                }
                
            }
            output.push_back(lineVec);
        }
        cutTheExtra(output);
        inputFile.close();// close the file
    }

    else
    {
        cout << "Unable to open file" << endl;
    }

    return output;
}
//cuts the #.....
// void cutTheExtra(vector<vector<string>>& vec)
// {
//     string char_solamit = "#";
//     int n = vec.size();
//     for(int i = 0; i < n; i++)
//     {
//         int m = vec[i].size();
//         for(int j = 0; j < m; j++)
//         {
//             if((vec[i][j]).c_str()[0]=='#')
//             {
//                 for(int k = 0; k < m-j;k++)
//                 {
//                     vec[i].pop_back();
//                 }
                
//             }
//         }
//     }
//     vec.erase(std::remove_if(vec.begin(), vec.end(), [](const std::vector<std::string>& v) {return v.size() == 0;}), vec.end());
// }

void cutTheExtra(vector<vector<string>>& vec) {
    for (auto& lineVec : vec) {
        // Find the position of the first '#' in the vector
        auto hashIter = find_if(lineVec.begin(), lineVec.end(), [](const string& s) { return !s.empty() && s[0] == '#'; });

        // If '#' is found, erase elements from the vector starting from that position
        if (hashIter != lineVec.end()) {
            lineVec.erase(hashIter, lineVec.end());
        }
    }

    // Remove vectors with size 0
    vec.erase(remove_if(vec.begin(), vec.end(), [](const vector<string>& v) { return v.empty(); }), vec.end());
}

//
//  main.cpp
//  knapsackProblem
//
//  Created by SicongLi
//  Copyright © 2016 AllenLi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector< vector<int> > DataHandle();

int main()
{
    vector<vector<int>> data = DataHandle();
    //    cout << data.size() << endl;
    
    
    int vals[101][10001] = {0};
    for ( int i = 0; i<100; i++)
    {
        vector<int> tempData = data[i];
        for ( int j = 0; j <10001; j++)
        {
            if (j < tempData[1])
            {
                vals[i+1][j] = vals[i][j];
            }
            else
            {
                int val = (vals[i][j] > vals[i][j-tempData[1]]+tempData[0] ? vals[i][j] : vals[i][j-tempData[1]]+tempData[0]);
                vals[i+1][j] = val;
            }
        }
        
    }
    
    cout << vals[100][10000] << endl;
    
}


vector< vector<int> > DataHandle()
{
    ifstream in("/knapsack1.txt");
    string line;
    
    vector< vector<int> > data;
    
    
//    in.open("../knapsack1.txt",ios::in);
    
    while (!in.eof())
    {
        getline(in,line);
        int len = line.length();
        char *useLine = new char[len+1];
        useLine[len] = '\0';
        
        line.copy(useLine,len,0);
        char* tempChar;
        
        int index1;
        int index2;
        vector<int> tempData;
        
        tempChar =strtok(useLine," \r");
        index1 = atoi(tempChar);
        
        tempChar =strtok(NULL," \r");
        index2 = atoi(tempChar);
        
        tempData.push_back(index1);
        tempData.push_back(index2);
        
        data.push_back(tempData);
        
    }
    in.close();
    return data;
}
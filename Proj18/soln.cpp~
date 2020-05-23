#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

//A type named "Node" for holding triangle values and the dijkstra weights
typedef pair<int64_t,int64_t> Node;

int main(){

  //each of the vectors in this
  //is a row of the triangle
  vector<vector<Node>> triangle;


  //pulling from the file and parsing into our vector of rows
  ifstream trianglefile;
  trianglefile.open("triangle67.txt");
  string line;
  
  while(getline(trianglefile, line)){

    vector<Node> cur_row;
    stringstream linestream(line);

    int cur_val = 0;
    while (linestream >> cur_val)
      cur_row.push_back(Node(cur_val, cur_val));

    triangle.push_back(cur_row);
    
  }
  
  trianglefile.close();

  //printing to ensure we've parsed correctly
  for(int i = 0; i < triangle.size(); i++){
    for (int j = 0; j < triangle[i].size(); j++)
      cout << triangle[i][j].first << " ";
    cout << endl;
  }


  //now we iterate through and weight everything using dijkstra
  //for each row
  for(int i = 0; i < triangle.size()-1; i++){
    //stand at each point in this row
    //look at all our options and note the best possible values
    for (int j = 0; j < triangle[i].size(); j++){
      //checking left path
      if (triangle[i+1][j].second < (triangle[i+1][j].first + triangle[i][j].second))
	triangle[i+1][j].second = triangle[i+1][j].first + triangle[i][j].second;

      //checking right path
      if (triangle[i+1][j+1].second < (triangle[i+1][j+1].first + triangle[i][j].second))
	triangle[i+1][j+1].second = triangle[i+1][j+1].first + triangle[i][j].second;
    }
  }

  //printing our resulting calculations
  for(int i = 0; i < triangle.size(); i++){
    for (int j = 0; j < triangle[i].size(); j++)
      cout << triangle[i][j].second << " ";
    cout << endl;
  }

  //finding our max result value
  int max_val = 0;
  for (int j = 0; j < triangle[triangle.size()-1].size(); j++){
    if (triangle[triangle.size()-1][j].second > max_val){
      max_val = triangle[triangle.size()-1][j].second;
    }
  }
    
  cout << "The sum is: " << max_val << endl;
  
  
  return 0;
  
}

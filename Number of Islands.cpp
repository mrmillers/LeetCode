/*https://leetcode.com/problems/number-of-islands/
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/
/*
E1 Put access code before conditon test. Should be (p.x>0 && p.x<w && p.y>0 && p.y<h  &&  grid[p.x][p.y] == '1')
E2 Boundary check px <= 0
E3 Multiple existence in quere results in MLE.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char> > &grid) {
        if (grid.size()==0)
        	return 0;
        if (grid[0].size()==0)
        	return 0;
        int w = grid.size();
		int h = grid[0].size();
        int tot = 0;
        queue<Point> q;
        for (int i=0;i<w;i++)
        	for (int j=0;j<h;j++){
        		if (grid[i][j] == '1'){
        			tot ++;
        			q.push(Point(i,j));
        			while (!q.empty()){
        				const Point t = q.front();
        				q.pop();
						grid[t.x][t.y] = '0';
						
						for (int k=0;k<4;k++){
							Point p(t.x+move[k].x,t.y+move[k].y);
							if (p.x>=0 && p.x<w && p.y>=0 && p.y<h  &&  grid[p.x][p.y] == '1'){
								grid[p.x][p.y] = '0';
								q.push(p);
							}
						}
					}
				}
			}
		return tot;
    }
    
    
private:
	struct Point{ 
		Point(int x,int y):x(x),y(y){}
		int x, y; 
	};
	static const Point move[4];

};
const Solution::Point Solution::move[4] = {Point(0,1),Point(0,-1),Point(1,0),Point(-1,0)};


int main(){
	Solution s;
	vector<vector<char> >v;
	v.push_back(vector<char>());
	v[0].push_back('1');
	v[0].push_back('1');
	cout<<s.numIslands(v);
	return 0;
}


#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
struct point_t
{
	int x;
	int y;
} typedef point;

bool p_compare(point & i, point & j)
{
	
	if(i.x < j.x)
		return true;
	if(i.x == j.x) 
		return i.y < j.y;
	return false;
}
int main()
{
	int n;

	cin.sync_with_stdio(false);
	vector<point> lines;
	int x;
	int y;
	cin >> n;
	for(int i =0; i < n; i++)
	{
		cin >> x;
		cin >> y;
		lines.push_back({x,y});
	}
	sort(lines.begin(), lines.end(), p_compare);
	vector<point> ranges;
	ranges.push_back(lines[0]);
	for(int i =1; i < n; i++)
	{

		if (ranges.back().y >= lines[i].x){ // merge
			ranges.back().y = lines[i].y > ranges.back().y ?  lines[i].y : ranges.back().y;
			continue;
		}
		ranges.push_back(lines[i]);
		
	}
	int distance = 0;
	for(int i =0; i < ranges.size(); i++)
	{
		distance  += abs(ranges[i].y - ranges[i].x );
	}
	cout << distance;
	return 0;
}
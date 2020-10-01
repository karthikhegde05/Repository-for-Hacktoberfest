#include <bits/stdc++.h>
#include"time.h"
#include"AstroObservation.h"
using namespace std;
float dist(pair<int,int> p1,pair<float,float> p2)
{
	int x1=p1.first,y1=p1.second;
	float y2=p2.second,x2=p2.first;
	return sqrt(pow(x2 - x1, 2) +  pow(y2 - y1, 2) * 1.0);
}
int main() {
	int lon,lat,valid=0,all=0,tx=0,ty=0;
	string name,date;
	char c;
	vector<AstroObservation*> lst;
	while(true)
	{
		cin>>name;
		if(name[0]=='#' && name[1]=='#')
		break;
		all++;
		cin>>lat;
		cin>>lon;
		cin>>date;
		cin>>c;
    int p;
    for(p=0;p<3;p++)
    {
      if(isupper(name[p]))
       continue;
      else
       break;
    }
		if(name.length()==3 && p==3 && date.length()==8 && lat>=-90 && lat<=90 && lon>=-180 && lon<=180 && isgooddate(date))
		{
			valid++;
			tx+=lat;
			ty+=lon;
			vector<AstroObservation*>::iterator itr;
			for(itr=lst.begin();itr!=lst.end();itr++)
			{
				if(name.compare((*itr)->name)==0)
				{
					(*itr)->add(lat,lon,date);
					break;
				}
			}
			if(itr==lst.end())
			lst.push_back(new AstroObservation(name,lat,lon,date));
		}
	}
	pair <float,float> avg((tx*1.0)/valid,(ty*1.0)/valid);
  int j=0,j_i;
	float min_dis=dist(lst[0]->trajectory[0],avg);
	string max_name;
	for(j=0;j<lst.size();j++)
	{
    vector<pair<int,int>> tmp=lst[j]->trajectory;
		for(int i=0;i<tmp.size();i++)
		{
			if(dist(tmp[i],avg)<min_dis)
			{
				min_dis=dist(tmp[i],avg);
				max_name=lst[j]->name;
        j_i=j;
			}
		}
	}
  vector<string>same_dist;
  for(j=0;j<lst.size();j++)
  {
    vector<pair<int,int>> tmp=lst[j]->trajectory;
    for(int i=0;i<tmp.size();i++)
    {
      if(dist(tmp[i],avg)==min_dis)
      {
        same_dist.push_back(lst[j]->name);
      }
    }
  }
  sort(same_dist.begin(),same_dist.end());
  max_name=same_dist[0];
int tot_t;
j=0;
for(j=0;j<lst.size();j++)
{
  vector<string> tmp_t=lst[j]->date;
  for(int i=0;i<tmp_t.size();i++)
  {
    tot_t=getDifference(tmp_t[i],(lst[0]->date[0]));
  }
}
float avg_t_i=(1.0*tot_t)/valid;
string avg_t=addDays(lst[0]->date[0],avg_t_i);

float min_dis_t=abs(getDifference(lst[0]->date[0],avg_t));
string max_name_t;
for(j=0;j<lst.size();j++)
{
  vector<string> tmp_t=lst[j]->date;
  for(int i=0;i<tmp_t.size();i++)
  {
    if(abs(getDifference(tmp_t[i],avg_t))<min_dis_t)
    {
      min_dis_t=abs(getDifference(tmp_t[i],avg_t));
      max_name_t=lst[j]->name;
    }
  }
}
vector<string>same_dist_t;
for(j=0;j<lst.size();j++)
{
  vector<string> tmp_t=lst[j]->date;
  for(int i=0;i<tmp_t.size();i++)
  {
    if(abs(getDifference(tmp_t[i],avg_t))==min_dis_t)
    {
      same_dist_t.push_back(lst[j]->name);
    }
  }
}
sort(same_dist_t.begin(),same_dist_t.end());
max_name_t=same_dist_t[0];
  float max_area=0;
  vector<string> max_names;
  for(int i=0;i<lst.size();i++)
  {
    if(lst[i]->area()>max_area)
    max_area=lst[i]->area();
  }
  for(int i=0;i<lst.size();i++)
  {
    if(lst[i]->area()==max_area)
    {
      max_names.push_back(lst[i]->name);
    }
  }
  sort(max_names.begin(),max_names.end());
	cout<<valid<<' '<<all<<" "<<max_name<<" "<<max_name_t<<" ";
  for(int i=0;i<max_names.size();i++)
  {
    cout<<max_names[i]<<" ";
  }
	return 0;
}
//AAA 0 0 01012019 # BJB 10 10 11111111 # AAA 1 0 29022019 # AAA 0 1 30031833 # ##

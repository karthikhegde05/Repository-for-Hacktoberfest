#ifndef IMT2018019_4
#define IMT2018019_4
#include <bits/stdc++.h>
#include"AstroObservation.h"
using namespace std;
AstroObservation::AstroObservation(string n,int x,int y,string dat){
  name=n;
  trajectory.push_back(make_pair(x,y));
  date.push_back(dat);
}
void AstroObservation::add(int x,int y,string dat)
{
  trajectory.push_back(make_pair(x,y));
  date.push_back(dat);
}
int AstroObservation::area(){
  int minx=trajectory[0].first;
  int miny=trajectory[0].second;
  int maxx=trajectory[0].first;
  int maxy=trajectory[0].second;
  vector<pair<int,int>>::iterator itr;
  for(itr=trajectory.begin();itr!=trajectory.end();itr++)
  {
    if(minx>itr->first)
    minx=itr->first;
    if(maxx<itr->first)
    maxx=itr->first;
    if(miny>itr->second)
    miny=itr->second;
    if(maxy<itr->second)
    maxy=itr->second;
  }
  return (maxx-minx)*(maxy-miny);
}
#endif

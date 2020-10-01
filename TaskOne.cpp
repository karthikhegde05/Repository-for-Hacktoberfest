#include"TaskOne.h"

pair<float,float> TaskOne::coefficient_finder(string s){
    float a1=0;
    float b1=0;
    int o1=0;
    int o2=-1; 
    s=s+'+';
    for(int i=1;i<s.length();i++)
    {
        if(s[i]=='+' || s[i]=='-'){
            o2=i;
            if(s[i-1]=='x'){
                if(o2-o1-1<=1){
                    if(s[o1]=='-')
                        a1-=1;
                    else if(s[o1]=='+' || (o1==0 && o2-o1-1==0))
                        a1+=1;
                    else{
                        try {
                        a1+=stof(s.substr(o1,1));
                        }
                        catch(exception e)
                        {
                            flag=false;
                        }
                    }
                }
                else
                {
                    try {
                        a1+=stof(s.substr(o1,o2-o1-1));
                    }
                    catch(exception e)
                    {
                        flag=false;
                    }
                }   
            }
            else
            {
                try 
                {
                    b1+=stof(s.substr(o1,o2-o1));
                }
                catch(exception e)
                {
                    flag=false;
                }
                // cout<<"o1= "<<o1<<" o2= "<<o2<<endl;
            }
            o1=i;
        }
        }
        // cout<<"a1= "<<a1<<" b1= "<<b1<<endl;
        pair<float,float> p={a1,b1};
        return p;
}
void TaskOne::Equationhandler()              // To find out coefficients; 
{
    string eqn=this->geteq();
    int ep,xp,op=-2;
    xp=eqn.find('x');
    ep=eqn.find('=');
    string exp,constant;
    // cout<<xp<<ep<<endl;
    if(xp<ep){
        constant=eqn.substr(ep+1, eqn.length()-ep-2);
        c=coefficient_finder(constant).second;
        exp=eqn.substr(1,ep-1);
        // cout<<exp<<endl;
        a=coefficient_finder(exp).first;
        b=coefficient_finder(exp).second;
    }
    else{
        constant=eqn.substr(1,ep-1);
        c=coefficient_finder(constant).second;
        exp=eqn.substr(ep+1,eqn.length()-ep-2);
        a=coefficient_finder(exp).first;
        b=coefficient_finder(exp).second;
    }
    // cout<<a<<" "<<b<<" "<<c<<endl;
}
void TaskOne::solveEquation(){
    this->Equationhandler();
    float ex;
    ex=float(c-b);
    if(a==0 && c-b==0)
        this->setis(1);
    else if(a==0)
        this->setns(1);
    this->setx(ex/(float)a);
}
void TaskOne::print(ostream& str)
{
    if(!flag)
        cout<<"Sorry! This equation cannot be solved";
    else if(this->getns()==1)
    {
        cout<<"No Solution";
    }
    else if(this->getis()==1)
    {
        cout<<"Infinite Solution";
    }
    else
        cout<<"x="<<round_off(this->getx());
}

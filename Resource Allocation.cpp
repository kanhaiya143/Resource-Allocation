#include<bits/stdc++.h>

using namespace std;

int main(){
    
unordered_map<long long,string>capacity;
capacity[10]="Large";
capacity[20]="XLarge";
capacity[40]="2XLarge";
capacity[80]="4XLarge";
capacity[160]="8XLarge";
capacity[320]="10XLarge";

vector<vector<pair<long long,long long>>>Country;
vector<pair<long long,long long>>NewYork,India,Chine;
NewYork.push_back({10,120});
NewYork.push_back({20,230});
NewYork.push_back({40,450});
NewYork.push_back({80,774});
NewYork.push_back({160,1400});
NewYork.push_back({320,2820});
Country.push_back(NewYork);

India.push_back({10,140});
India.push_back({20,INT_MAX});
India.push_back({40,413});
India.push_back({80,890});
India.push_back({160,1300});
India.push_back({320,2970});
Country.push_back(India);

Chine.push_back({10,110});
Chine.push_back({20,200});
Chine.push_back({40,INT_MAX});
Chine.push_back({80,670});
Chine.push_back({160,1180});
Chine.push_back({320,INT_MAX});
Country.push_back(Chine);

    long long units,time;
    cout<<"Input units and Time respectively"<<endl;
    cin>>units>>time;
    
   string name[]={"NewYork","India","Chine"};
    priority_queue<pair<double,pair<long long,long long>>>pq;
    
    for(int type=0;type<3;type++){
        long long totalcost=0;
        vector<pair<string,long long>>machines;
        long long requnits=units;
        for(int i=0;i<Country[type].size();i++){
            
            if(Country[type][i].second!=INT_MAX)
            pq.push({(double)(Country[type][i].first/(Country[type][i].second*1.0)),{Country[type][i].second,Country[type][i].first}});
        }
        
        while(!pq.empty()&&requnits>0){
            
            long long cost=pq.top().second.first;
            long long req=pq.top().second.second*time;
            long long x=requnits/req;
            //cout<<req<<" "<<cost<<endl;
            if(requnits>=req){
            totalcost+=(x)*(cost)*time;
            requnits=requnits-(x*req);
            machines.push_back({capacity[req],x});
            }
            pq.pop();
        }
        cout<<"region: "<<name[type]<<endl;
        cout<<"total_cost: "<<totalcost<<endl;
        cout<<"machines: ";
        for(int i=0;i<machines.size();i++){
            cout<<"("<<machines[i].first<<", "<<machines[i].second<<")"<<endl;
        }
        cout<<endl;
    }
}

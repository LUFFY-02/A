#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <functional>
// using namespace __gnu_pbds;
// #define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define omap tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define pb emplace_back 
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define maxi(v) *max_element((v).begin(),(v).end())
#define mini(v) *min_element((v).begin(),(v).end())
#define sum(v) accumulate((v).begin(),(v).end())
#define reverse(v) reverse((v).begin(),(v).end())
#define ed '\n'
#define Ed '\n'
#define no cout<<"NO"<<ed
#define yes cout<<"YES"<<ed
typedef vector<int>     vi;   typedef vector<vector<int>> vvi;
unordered_map<int,pair<int,int>> go_in,curr_in;
set<vector<vector<int>>> sz;
int ans=-1;
void print_matrix(vector<vector<int>> &ar,vector<vector<int>> &goals,int n,int action){
   cout<<"          STEP-> "<<ans<<ed;
   cout<<"Curr_Matrix      Goal Matrix"<<ed;
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         cout<<((action==1) ? ar[i][j] : goals[i][j])<<" ";
      }
         cout<<"              ";
      for(int j=0;j<n;j++){
         cout<<goals[i][j]<<" ";
      }
      cout<<ed;
   }
}
int man_dis(vector<vector<int>> &ar,vector<vector<int>> &goals,int n,int type){
   int ans=0;
   for(int i=1;i<n*n;i++){
      if(type==0) ans+=(abs(go_in[i].first-curr_in[i].first)+abs(go_in[i].second-curr_in[i].second));
      else{
	if(go_in[i].first != curr_in[i].first || go_in[i].second != curr_in[i].second ) ans++;
	}
   }
   
   return ans;
}
void locations(vector<vector<int>> &ar,int n){
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         curr_in[ar[i][j]]={i,j};
      }
   }
}
void calulate_v_distance(vector<vector<int>> &ar,vector<vector<int>> &goals,int n,vector<int> &dis,int type){
   if(curr_in[0].second!=0){
      swap(ar[curr_in[0].first][curr_in[0].second],ar[curr_in[0].first][curr_in[0].second-1]);
      locations(ar,n);
      if(sz.find(ar)==sz.end()){
         dis[0]=man_dis(ar,goals,n,type);
      }
      swap(ar[curr_in[0].first][curr_in[0].second],ar[curr_in[0].first][curr_in[0].second+1]);
      locations(ar,n);
   }
   if(curr_in[0].second!=n-1){
      swap(ar[curr_in[0].first][curr_in[0].second],ar[curr_in[0].first][curr_in[0].second+1]);
      locations(ar,n);
      if(sz.find(ar)==sz.end()){
         dis[1]=man_dis(ar,goals,n,type);
      }
      swap(ar[curr_in[0].first][curr_in[0].second],ar[curr_in[0].first][curr_in[0].second-1]);
      locations(ar,n);
   }
   if(curr_in[0].first!=0){
      swap(ar[curr_in[0].first][curr_in[0].second],ar[curr_in[0].first-1][curr_in[0].second]);
      locations(ar,n);
      if(sz.find(ar)==sz.end()){
         dis[2]=man_dis(ar,goals,n,type);
      }
      swap(ar[curr_in[0].first][curr_in[0].second],ar[curr_in[0].first+1][curr_in[0].second]);
      locations(ar,n);
   }
   if(curr_in[0].first!=n-1){
      swap(ar[curr_in[0].first][curr_in[0].second],ar[curr_in[0].first+1][curr_in[0].second]);
      locations(ar,n);
      if(sz.find(ar)==sz.end()){
         dis[3]=man_dis(ar,goals,n,type);
      }
      swap(ar[curr_in[0].first][curr_in[0].second],ar[curr_in[0].first-1][curr_in[0].second]);
      locations(ar,n);
   }
}
void convert(vector<vector<int>> &ar,vector<vector<int>> &goals,int n,int i,int w){
   if(i==0){
      if(w==1){
         swap(ar[curr_in[0].first][curr_in[0].second],ar[curr_in[0].first][curr_in[0].second-1]);
         locations(ar,n);
         sz.insert(ar);
      }
      locations(ar,n);
      if(w==0){
         sz.erase(ar);
         swap(ar[curr_in[0].first][curr_in[0].second],ar[curr_in[0].first][curr_in[0].second+1]);
         locations(ar,n);
      }
   }
   if(i==1){
      if(w==1){
         swap(ar[curr_in[0].first][curr_in[0].second],ar[curr_in[0].first][curr_in[0].second+1]);
         locations(ar,n);
         sz.insert(ar);
      }
      locations(ar,n);
      if(w==0){
         sz.erase(ar);
         swap(ar[curr_in[0].first][curr_in[0].second],ar[curr_in[0].first][curr_in[0].second-1]);
         locations(ar,n);
      }
   }
   if(i==2){
      if(w==1){
         swap(ar[curr_in[0].first][curr_in[0].second],ar[curr_in[0].first-1][curr_in[0].second]);
         locations(ar,n);
         sz.insert(ar);
      }
      locations(ar,n);
      if(w==0){
         sz.erase(ar);
         swap(ar[curr_in[0].first][curr_in[0].second],ar[curr_in[0].first+1][curr_in[0].second]);
         locations(ar,n);
      }
   }
   if(i==3){
      if(w==1){
         sz.insert(ar);
         swap(ar[curr_in[0].first][curr_in[0].second],ar[curr_in[0].first+1][curr_in[0].second]);
         locations(ar,n);
      }
      locations(ar,n);
      if(w==0){
         sz.erase(ar);
         swap(ar[curr_in[0].first][curr_in[0].second],ar[curr_in[0].first-1][curr_in[0].second]);
         locations(ar,n);
      }
   }  
}
bool grid_solver(vector<vector<int>> &ar,vector<vector<int>> &goals,int n,int currr,int type){
   vector<int> v(4,-1);
   ans++;if(type) 
   print_matrix(ar,goals,n,1);
   if(ans>15000) return false;
   locations(ar,n);
   if(man_dis(ar,goals,n,type)==0) return true;
   calulate_v_distance(ar,goals,n,v,type);
   if(maxi(v) == -1) return false;
   int t=INT_MAX;
	
   for(int i=0;i<4;i++){
	if(type && v[i]!=-1) cout<<v[i]+1<<" ";
	else cout<<v[i]<<" ";
      if(v[i]!=-1) t=min(v[i],t);
      if(v[i]==0) return true;
   }
cout<<ed;
   // cout<<ans<<" "<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<ed;
   bool done=false;
	
   for(int i=0;i<4;i++){
      if(v[i]==t){
         sz.insert(ar);
         convert(ar,goals,n,i,1);
         if(grid_solver(ar,goals,n,currr+1,type)){
            return true;
         }
         convert(ar,goals,n,i,0);
      }
   }
   return done;
}
bool solvable(vector<vector<int>> &v,int n){
   int inversions=0;
   vector<int> temp;
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         if(v[i][j]!=0) temp.pb(v[i][j]);
	
      }
   }
	//cout<<ed;
   for(int i=0;i<temp.size()-1;i++){
      for(int j=i+1;j<temp.size();j++){
         if(temp[i]>temp[j]) inversions++;
      }
   }
   int row=curr_in[0].first;
   if(n&1 && inversions%2==0) return true;
   else if(n%2==0 && inversions%2==0 && row%2==0) return true;
   else if(n%2==0 && inversions%2==1 && row%2==1) return true;
   else return false;
}
signed main(){
   // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
   // io_file();
   // CODE........................................................................
   cout<<"Enter dimensions of the matrix (N*N) : ";
   int n;cin>>n;
   // cout<<n;
   vector<vector<int>> arr(n),goals(n);
   int input;
   cout<<ed;
   cout<<"Enter Initial Configuration in matrix form : "<<ed;
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         cin>>input;
         arr[i].pb(input);
      }
   }
   cout<<ed;
   cout<<"Enter Goal Configuration in matrix form : "<<ed;
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         cin>>input;
         goals[i].pb(input);
         go_in[goals[i][j]]={i,j};
      }
   }
   cout<<ed;
	cout<<"Enter Manhattan (0) or Tile diff (1) : ";
	int type;cin>>type;
	cout<<ed;
   if(!solvable(arr,n)) cout<<"NOT SOLVABLE "<<ed;
   else if(grid_solver(arr,goals,n,0,type)) {
      ans++;
	cout<<ed;
      print_matrix(arr,goals,n,0);
      cout<<"SOLVED IN "<<ans<<" STEPS"<<ed;
   }
   else cout<<"NOT SOLVABLE "<<ed;
}

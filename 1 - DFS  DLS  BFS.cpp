#include<bits/stdc++.h>
using namespace std;
struct Node{
	int val;
	Node *left,*right;
	Node(int data){
		val=data;
		left=right=NULL;
	}
};
bool dfs(Node *root,int value){
	if(root==NULL) return false;
	if(root->val == value) return true;
	if(dfs(root->left,value)|| dfs(root->right,value)) return true;
	return false;
}
bool dls(Node *root,int value,int level,int curr){
	if(root==NULL) return false;
	if(level<=curr) return false;
	if(dls(root->left,value,level,curr+1)) return true;
	if(root->val == value) return true;
	if(dls(root->right,value,level,curr+1)) return true;
	return false;
}
bool bfs(Node *root,int value){
	if(root == NULL) return false;
	queue<Node*> s;
	s.push(root);
	while(!s.empty()){
		int size=s.size();
		for(int i=0;i<size;i++){
			Node *curr=s.front();
			s.pop();
			if(curr->val == value)	return true;
			if(curr->left) s.push(curr->left);
			if(curr->right) s.push(curr->right);
		}
	}
	return false;
}
signed main(){
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
	root->left->right->left = new Node(8);
	cout<<"VALUE TO SEARCH :  ";
    int value;cin>>value;
    cout<<"\n TILL WHAT LEVEL TO BE SEARCHED :  ";
    int level;cin>>level;
    bool check_dfs=dfs(root,value);
    bool check_bfs=bfs(root,value);
    bool check_dls=dls(root,value,level,0);
    if(check_dfs) cout<<"FOUND in DFS "<<endl;
    else cout<<"NOT FOUND in DFS "<<endl;
    if(check_bfs) cout<<"FOUND in BFS "<<endl;
    else cout<<"NOT FOUND in BFS "<<endl;
    if(check_dls) cout<<"FOUND in DLS"<<endl;
    else cout<<"NOT FOUND in DLS"<<endl;
}

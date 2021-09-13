#include <bits/stdc++.h>

using namespace std;
const int N = 1e3+7 ;

bool vis[N] ;
vector<vector<int>> languageEmployees;
vector<vector<int>> graph;

int n,m,nbLangages,l;

void dfs(int pos){
	vis[pos] = true ;
	for(auto child: graph[parent]){
		if(!vis[child])
            dfs(child);
	}

	return ;
}

int main()
{

cin>>n>>m;

languageEmployees.resize(m);
graph.resize(n);
memset(vis,false,sizeof vis);

for (int i=0 ; i<n ; i++)
{
    cin>>nbLangages;

    for (int j=0 ; j<nbLangages ; j++)
     {
        cin>>l;
        languageEmployees[l-1].push_back(i);
     }
}

for (int i=0 ; i<n ; i++)
{
    int nb = languageEmployees[i].size();
    for (int j=0 ; j < nb-1 ; j++)
    {
        graph[languageEmployees[i][j].push_back(languageEmployees[i][j+1]);
    }
}

int disconnectedGraphs=0;
for ( int i=0 ; i<n ; i++)
{
    if (!vis[i])
    {
        dfs(i);
        disconnectedGraphs++;
    }
}

cout<<disconnectedGraphs-1;
    return 0;
}

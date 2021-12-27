#include<bits/stdc++.h>
using namespace std;

class edge{
    public:
        int destID;
        int weight;

    void set_destID(int id){
        destID=id;
    }

    void set_weight(int w){
        weight=w;
    }

    int get_destID(){
        return destID;
    }

    int get_weight(){
        return weight;
    }

};

class vertex{
    public:
        int vertexID;
        string vertexName;
        list<edge> edgelist;

    void set_vertexID(int id){
        vertexID=id;
    }

    void set_vertexName(string w){
        vertexName=w;
    }

    int get_vertexID(){
        return vertexID;
    }

    string get_vertexName(){
        return vertexName;
    }

    list<edge> get_edgelist(){
        return edgelist;
    }

    void print_edgelist(){
        for(auto it=edgelist.begin();it!=edgelist.end();it++){
            cout<<"Going to vertex: "<<it->get_destID()<<" with weight of: "<<it->get_weight()<<endl;
        }
    }
    
};

class graph{
    public:
        vector<vertex> vertices;

    bool checkifvertexexistbyID(int vid){
        for(int i=0;i<vertices.size();i++){
            if(vertices.at(i).get_vertexID()==vid){
                return true;
            }
        }
        return false;
    }

    void add_vertex(vertex V){
        bool check=checkifvertexexistbyID(V.vertexID);

        if(check){
            cout<<"This vertex already exists in the graph."<<endl;
        }
        else{
            vertices.push_back(V);
            cout<<"Vertex has been added in the graph."<<endl;
        }
    }

    vertex getvertexbyID(int id){
        for(int i=0;vertices.size();i++){
            if(vertices.at(i).get_vertexID()==id){
                return vertices.at(i);
            }
        }
    }

    bool checkifedgeexistbyID(int tovertex, int fromvertex){
        vertex v=getvertexbyID(fromvertex);
        list<edge>e = v.get_edgelist();

        for(auto it=e.begin();it!=e.end();it++){
            if(it->get_destID()==tovertex){
                return true;
            }
        }
        return false;
    }

    void addedgebyID(int tovertex, int fromvertex, int weight){
        bool check1=checkifvertexexistbyID(tovertex);
        bool check2=checkifvertexexistbyID(fromvertex);

        bool check3=checkifedgeexistbyID(tovertex,fromvertex);

        if(check1 && check2){
            if(check3){
                cout<<"The edge already exists between these two."<<endl;
            }
            else{
                edge e;
                e.set_weight(weight);
                for(int i=0;i<vertices.size();i++){
                    if(vertices.at(i).get_vertexID()==fromvertex){
                        e.set_destID(tovertex);
                        vertices.at(i).edgelist.push_back(e);
                    }
                    else if(vertices.at(i).get_vertexID()==tovertex){
                        e.set_destID(fromvertex);
                        vertices.at(i).edgelist.push_back(e);
                    }
                }
                cout<<"Edge added succesfully."<<endl;
            }
        }
        else{
            cout<<"One or more of these vertex don't exist in the graph ";
        }
    }

    void print_graph(){
        for(int i=0;i<vertices.size();i++){
            cout<<"Vertex name: "<<vertices.at(i).get_vertexName()<<" it's id: "<<vertices.at(i).get_vertexName()<<" and it's neighbours: ";
            vertices.at(i).print_edgelist();
        }
    }

    void update_edge(int tovertex, int fromvertex){
        bool check3=checkifedgeexistbyID(tovertex,fromvertex);

        if(check3){
            int w;
            cout<<"Enter the weight of the new edge: ";
            cin>>w;

            for(int i=0;i<vertices.size();i++){
                for(auto it=vertices.at(i).edgelist.begin();it!=vertices.at(i).edgelist.begin();it++){
                    if(it->destID==fromvertex){
                        it->set_weight(w);
                    }
                    else if(it->destID==tovertex){
                        it->set_weight(w);
                    }
                }
            }
            cout<<"Edge added succesfully. "<<endl;
        }
        else{
            cout<<"This edge doesn't exist. "<<endl;
        }
    }

    void delete_edge(int tovertex, int fromvertex){
        bool check3=checkifedgeexistbyID(tovertex,fromvertex);

        if(check3){
            for(int i=0;i<vertices.size();i++){
                for(auto it=vertices.at(i).edgelist.begin();it!=vertices.at(i).edgelist.begin();it++){
                    if(it->destID==fromvertex){
                        vertices.at(i).edgelist.erase(it);
                        break;
                    }
                    else if(it->destID==tovertex){
                        vertices.at(i).edgelist.erase(it);
                        break;
                    }
                }
            }
            cout<<"Edge deleted succesfully. "<<endl;
        }
        else{
            cout<<"This edge doesn't exist. "<<endl;
        }
    }

    void update_vertex(int vertexID){
        if(checkifvertexexistbyID(vertexID)){
            string m;
            cout<<"Enter the new name of the vertex: ";
            cin>>m;
            for(int i=0;i<vertices.size();i++){
                if(vertices.at(i).get_vertexID()==vertexID){
                    vertices.at(i).set_vertexName(m);
                }
            }
            cout<<"Vertex updated succesfully. "<<endl;
        }
        else{
            cout<<"This vertex doesn't exist. "<<endl;
        }
    }

    void delete_vertex(int vertexID){
        if(checkifvertexexistbyID(vertexID)){
            int Pindex=0;
            for(int i=0;i<vertices.size();i++){
                if(vertices.at(i).get_vertexID()==vertexID){
                    Pindex=i;
                }
            }
            for(int i=0;i<vertices.size();i++){
                for(auto it=vertices.at(i).edgelist.begin();it!=vertices.at(i).edgelist.end();it++){
                    if(it->destID==vertexID){
                        vertices.at(i).edgelist.erase(it);
                        break;
                    }
                }
            }
            vertices.erase(vertices.begin()+Pindex);
            cout<<"Vertex deleted successfully"<<endl;
        }
        else{
            cout<<"This vertex doesn't exist. "<<endl;
        }
    }

    void BFS1(int VID){
        bool visited[vertices.size()];
        queue<vertex> q;
        for(int i=0;i<vertices.size();i++){
            visited[i]=false;
        }
        for(int i=0;i<vertices.size();i++){
            if(vertices.at(i).get_vertexID()==VID){
                visited[VID]=true;
                q.push(vertices.at(i));
                while(!q.empty()){
                    vertex v=q.front();
                    cout<<v.get_vertexName()<<" ";
                    q.pop();
                    for(auto it=v.edgelist.begin();it!=v.edgelist.end();it++){
                        if(!visited[it->get_destID()]){
                            visited[it->destID]=true;
                            for(int j=0;j<vertices.size();j++){
                                if(vertices.at(j).get_vertexID()==it->get_destID()){
                                    q.push(vertices.at(j));
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    void DFSTraversal(int VID, bool Visited[])
	{
		for(int i=0;i<vertices.size();i++)
		{
			if(vertices.at(i).get_vertexID()==VID)
			{
				Visited[VID]=true;
				cout<<vertices.at(i).get_vertexName()<<" ";
				for(auto it=vertices.at(i).edgelist.begin();it!=vertices.at(i).edgelist.end();it++)
				{
					if(!Visited[it->get_destID()])
					{
						DFSTraversal(it->get_destID(),Visited);
					}
				}
			}
		}
		
	}
	
	
	void DFS(int VID)
	{
		bool Visited[vertices.size()];
		for(int i=0;i < vertices.size();i++)
		{
			Visited[i]=false;
		}
		DFSTraversal(VID,Visited);
		
	}

};


int main(){
    graph G;
    int n, vid, vid1, vid2;
    string vname;
    cout<<"Enter the number of vertices in your graph: ";
    cin>>n;

    for(int i=0;i<n;i++){
        vertex V;
        cout<<"Set vertex id and vertex name of vertex "<<i+1<<":";
        cin>>vid>>vname;
        V.set_vertexID(vid);
        V.set_vertexName(vname);
        G.add_vertex(V);
    }

    cout<<"Enter the number of edges in your graph: ";
    cin>>n;

    for(int i=0;i<n;i++){
        edge e;
        cout<<"Set vertices on which edge "<<i+1<<" will be formed: ";
        cin>>vid1>>vid2;
        G.addedgebyID(vid1,vid2,2);
    }

    G.print_graph();
    G.BFS1(1);

    return 0;
}

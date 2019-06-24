#include<iostream>
#include<vector>
#include<climits>
#include <map>
#include<deque>
#include<fstream>
#include <sstream>
using namespace std;

#define BLACK -1;
#define WHITE 0;
#define GRAY 1;
#define NOCOLOR -99;

struct Node{
    string source;
    int peso;
    int cor;
};
typedef pair< Node, Node > Position;
struct Edge{
    Position _edge_pos;
    int color;
    int peso;
};
struct Vertex{
    Node node;
    deque <Vertex> adj_points;
    deque <Edge> _vet_edge;
};
struct Graph{
    vector <Vertex> _node_graph;
};

Edge _set_edge(Node _vertex, Node _adj,int peso){
    Edge edge;
    edge._edge_pos.first=_vertex;
    edge.color= BLACK;
    return edge;
}
void _fixed_adj(Vertex _vertex, vector<Vertex> adj){
    int peso;
    for(Vertex i: adj){
        cout<<"Digite o peso do Edge: ";
        cin>>peso;
        i.node.peso=peso;
        _vertex.adj_points.push_front(i);
        _vertex._vet_edge.push_front(_set_edge(_vertex.node,i.node,peso));
    }

}
// read a dataset
vector <string>_read_data(string _dataset_name){
    vector <string> vet_line;
    Vertex vert;
    string tokens[2];
    int index=0;
    fstream file;
    string str;
    file.open(_dataset_name);
    while (getline(file,str)){
        vet_line.push_back(str);
    }
    file.close();
    return vet_line;
}
 vector <Vertex>_split_dataset(vector <string> _dataset){
     Vertex vertex;
     string words[2];
     int index=0;
     vector<Vertex> _node_graph;
     for(string i : _dataset){
       stringstream line(i);
       string token;
       while(getline(line,token,',')){
           words[index]=token;
           index++;
       }  
       vertex.node.source= (string) words[0];
       vertex.node.peso =stoi(words[1]);
       index = 0;
       _node_graph.push_back(vertex);
     }
     return _node_graph;
 }
 //finish

void _make_a_graph(Graph &graph){
    vector <Vertex> _graph_vertex;
    vector<string> _lines_read;
    _lines_read =_read_data("dataset_trabalho.txt");
    _graph_vertex = _split_dataset(_lines_read);
}



int main(){
    vector<string> lines = _read_data("dataset_trabalho.txt");
    vector<Vertex> nodes = _split_dataset(lines);
    cout<<nodes.size();
    return 0;
}
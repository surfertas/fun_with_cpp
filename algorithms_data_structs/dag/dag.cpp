#include "dag.h"


int main(int argc, char** argv)
{
    using namespace dag;
    std::unique_ptr<Meta> meta1 = std::make_unique<Meta>();
    std::unique_ptr<Meta> meta2 = std::make_unique<Meta>();
    meta1->name = "test1";
    meta2->name = "test2";

    auto v1 = std::make_shared<Vertex>(std::move(meta1));
    auto v2 = std::make_shared<Vertex>(std::move(meta2));
    
    Edge e1(v1,v2);
   
    Graph G;
    G.insert_edge(e1);
    G.insert_vertex(v1);
    G.insert_vertex(v2);
    G.print_graph();
}
    
    
    
  
  

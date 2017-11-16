#include "dag.h"

// https://en.wikipedia.org/wiki/Edmonds%E2%80%93Karp_algorithm
int main(int argc, char** argv)
{
    using namespace dag;
    std::unique_ptr<Meta> meta1 = std::make_unique<Meta>();
    std::unique_ptr<Meta> meta2 = std::make_unique<Meta>();
    std::unique_ptr<Meta> meta3 = std::make_unique<Meta>();
    std::unique_ptr<Meta> meta4 = std::make_unique<Meta>();
    std::unique_ptr<Meta> meta5 = std::make_unique<Meta>();
    std::unique_ptr<Meta> meta6 = std::make_unique<Meta>();
    std::unique_ptr<Meta> meta7 = std::make_unique<Meta>();

    meta1->name = "A";
    meta2->name = "B";
    meta3->name = "C";
    meta4->name = "D";
    meta5->name = "E";
    meta6->name = "F";
    meta7->name = "G";

    auto A = std::make_shared<Vertex>(std::move(meta1));
    auto B = std::make_shared<Vertex>(std::move(meta2));
    auto C = std::make_shared<Vertex>(std::move(meta3));
    auto D = std::make_shared<Vertex>(std::move(meta4));
    auto E = std::make_shared<Vertex>(std::move(meta5));
    auto F = std::make_shared<Vertex>(std::move(meta6));
    auto G = std::make_shared<Vertex>(std::move(meta7));

    Graph Gr;
    Gr.insert_vertex(A);
    Gr.insert_vertex(B);
    Gr.insert_vertex(C);
    Gr.insert_vertex(D);
    Gr.insert_vertex(E);
    Gr.insert_vertex(F);
    Gr.insert_vertex(G);

    Edge e1(A,B,3);
    Edge e2(A,D,3);
    Edge e3(D,F,6);
    Edge e4(D,E,2);
    Edge e5(F,G,9);
    Edge e6(C,A,3);
    Edge e7(C,D,1);
    Edge e8(B,C,4);

    Gr.insert_edge(e1);
    Gr.insert_edge(e2);
    Gr.insert_edge(e3);
    Gr.insert_edge(e4);
    Gr.insert_edge(e5);
    Gr.insert_edge(e6);
    Gr.insert_edge(e7);
    Gr.insert_edge(e8);

    // Check if setting undirected fails.
    Gr.insert_edge(e2);
   
    Gr.print_graph();
}
    
    
    
  
  

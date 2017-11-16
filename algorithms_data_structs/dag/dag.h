// Author: Tasuku Miura
#ifndef DAG_H
#define DAG_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

namespace dag {

struct Meta {
  std::string name;
};

struct Vertex {
  Vertex(std::unique_ptr<Meta> meta) : meta_(std::move(meta)) {}
  
  std::string get_meta() {
    return meta_->name;
  }

private:
  // Meta data will be unique to a vertex, thus use unique_ptr<>
  std::unique_ptr<Meta> meta_;
};

struct Edge {
  Edge(std::shared_ptr<Vertex> v1, std::shared_ptr<Vertex> v2) :
    head_(v1), tail_(v2), weight_(0) {}
  Edge(std::shared_ptr<Vertex> v1, std::shared_ptr<Vertex> v2, size_t weight) :
    head_(v1), tail_(v2), weight_(weight) {}

  // Vertices will be shared thus make shared.
  std::shared_ptr<Vertex> head_;
  std::shared_ptr<Vertex> tail_;
  size_t weight_;
};

struct Graph {
  Graph() : edges_(), vertices_() {}
  
  void insert_edge(Edge e) {
    edges_.emplace_back(e);
  }

  void insert_vertex(std::shared_ptr<Vertex> v) {
    vertices_.emplace_back(v);
  }

  void print_graph() {
    for (auto e : edges_) {
      std::cout << e.head_->get_meta() << "->" << e.tail_->get_meta() << "\n";
    }
  }
private:
  std::vector<Edge> edges_;
  std::vector<std::shared_ptr<Vertex>> vertices_;
};

}// dag
#endif

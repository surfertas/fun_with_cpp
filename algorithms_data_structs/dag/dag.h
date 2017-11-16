// Author: Tasuku Miura
#ifndef DAG_H
#define DAG_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

namespace dag {

struct Meta {
  std::string name;
  std::size_t id; 
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
    if (!(check_edge_exists(e) || check_undirected_edge(e))) {
      edges_.emplace_back(e);
    }
  }

  void insert_vertex(std::shared_ptr<Vertex> v) {
    vertices_.emplace_back(v);
  }

  bool check_edge_exists(Edge e) {
    auto exists = std::find_if(edges_.begin(), edges_.end(), [&](Edge edge) {
      return ((e.head_ == edge.head_) && (e.tail_ == edge.tail_));
    });
    if (exists != edges_.end()) {
      std::cout << "Edge already exists.\n";
      return true;
    }
    return false;
  }
  
  bool check_undirected_edge(Edge e) {
    auto undirected = std::find_if(edges_.begin(), edges_.end(), [&](Edge edge) {
      return ((e.head_ == edge.tail_) && (e.tail_ == edge.head_));
    });
    if (undirected != edges_.end()) {
      std::cout << "Including edge would make graph undirected. \n";
      return true;
    }
    return false;
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
#endif // DAG_H

#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <vector>

struct Edge 
{
    int u, v;
    double weight;
    bool operator<(const Edge& other) const 
    {
        return weight < other.weight;
    }
};

std::vector<Edge> generate_graph(int num_vertices, long long num_edges);

#endif
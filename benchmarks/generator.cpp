#include "generator.hpp" // Ensure this matches your header name (.h or .hpp)
#include <random>
#include <vector>

std::vector<Edge> generate_graph(int num_vertices, long long num_edges) 
{
    std::vector<Edge> edges;
    edges.reserve(num_edges);
    
    std::mt19937 rng(42); 
    std::uniform_int_distribution<int> dist_node(0, num_vertices - 1);
    std::uniform_real_distribution<double> dist_weight(1.0, 1000.0);
    
    std::vector<bool> seen((size_t)num_vertices * num_vertices, false);
    
    while (edges.size() < num_edges) 
    {
        int u = dist_node(rng);
        int v = dist_node(rng);
        
        if (u == v) continue;
        
        if (u > v) std::swap(u, v);
        
        size_t index = (size_t)u * num_vertices + v;
        
        if (!seen[index]) 
        {
            seen[index] = true;
            edges.push_back({u, v, dist_weight(rng)});
        }
    }
    
    return edges;
}
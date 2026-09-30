#include "union_find.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

struct Edge 
{
    int u, v;
    double weight;
    
    bool operator<(const Edge& other) const 
    {
        return weight < other.weight;
    }
};

std::vector<Edge> kruskal_mst(int num_vertices, std::vector<Edge>& edges, int variant) 
{
    std::sort(edges.begin(), edges.end());
    
    UnionFind uf(num_vertices);
    std::vector<Edge> mst;
    mst.reserve(num_vertices - 1);

    for (const auto& edge : edges) 
    {
        bool merged = false;
        
        if (variant == 0) 
        {
            merged = uf.unite_naive(edge.u, edge.v);
        } 
        
        else if (variant == 1) 
        {
            merged = uf.unite_rank(edge.u, edge.v);
        } 
        
        else if (variant == 2) 
        {
            merged = uf.unite_optimised(edge.u, edge.v);
        }

        if (merged) 
        {
            mst.push_back(edge);
            if (mst.size() == num_vertices - 1) 
            {
                break;
            }
        }
    }
    
    return mst;
}
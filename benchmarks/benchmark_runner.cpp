#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "generator.hpp"

std::vector<Edge> kruskal_mst(int num_vertices, std::vector<Edge>& edges, int variant);

int main() 
{
    std::ofstream csv_file("data/results.csv");
    csv_file << "Vertices,Edges,Density,NaiveTime_ms,RankOnlyTime_ms,OptimisedTime_ms\n";

    std::vector<int> vertex_counts = {1000, 2500, 5000, 7500, 10000};
    
    for (int V : vertex_counts) 
    {
        long long E_sparse = 3LL * V;
        long long E_dense = (1LL * V * (V - 1)) / 4;

        std::vector<std::pair<long long, std::string>> densities = {{E_sparse, "Sparse"}, {E_dense, "Dense"}};

        for (auto& density : densities) 
        {
            long long E = density.first;
            std::string density_label = density.second;

            std::cout << "Benchmarking " << density_label << " graph: V=" << V << ", E=" << E << "...\n";
            std::vector<Edge> edges = generate_graph(V, E);

            auto start_naive = std::chrono::high_resolution_clock::now();
            kruskal_mst(V, edges, 0);
            auto end_naive = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> time_naive = end_naive - start_naive;

            auto start_rank = std::chrono::high_resolution_clock::now();
            kruskal_mst(V, edges, 1);
            auto end_rank = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> time_rank = end_rank - start_rank;

            auto start_optimized = std::chrono::high_resolution_clock::now();
            kruskal_mst(V, edges, 2);
            auto end_optimized = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> time_optimized = end_optimized - start_optimized;

            csv_file << V << "," << E << "," << density_label << "," << time_naive.count() << "," << time_rank.count() << "," << time_optimized.count() << "\n";
        }
    }
    
    csv_file.close();
    std::cout << "Benchmarking complete. Results saved to data/results.csv\n";
    return 0;
}
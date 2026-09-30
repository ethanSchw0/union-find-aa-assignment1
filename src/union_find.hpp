#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP

#include <vector>
#include <numeric>

class UnionFind 
{
    private:
        std::vector<int> parent;
        std::vector<int> rank;

    public:
        UnionFind(int n) 
        {
            parent.resize(n);
            rank.resize(n, 0);
            std::iota(parent.begin(), parent.end(), 0);
            
        }

        
        int find_naive(int i) 
        {
            while (parent[i] != i) 
            {
                i = parent[i];
            }
            return i;
        }

        bool unite_naive(int i, int j) 
        {
            int root_i = find_naive(i);
            int root_j = find_naive(j);
            if (root_i == root_j) return false;
            
            parent[root_i] = root_j;
            return true;
        }


        int find_optimised(int i) 
        {
            if (parent[i] == i) 
            {
                return i;
            }
            return parent[i] = find_optimised(parent[i]); 
        }

        bool unite_optimised(int i, int j) 
        {
            int root_i = find_optimised(i);
            int root_j = find_optimised(j);

            if (root_i == root_j) 
            {
                return false;
            }

            if (rank[root_i] < rank[root_j]) 
            {
                parent[root_i] = root_j;
            } 
            
            else if (rank[root_i] > rank[root_j]) 
            {
                parent[root_j] = root_i;
            }
            
            else 
            {
                parent[root_j] = root_i;
                rank[root_i]++;
            }
            return true;
        }

        int find_rank(int i) 
        {
            while (parent[i] != i) 
            {
                i = parent[i];
                
            }
            return i;
        }

        bool unite_rank(int i, int j) 
        {
            int root_i = find_rank(i);
            int root_j = find_rank(j);
            if (root_i == root_j) 
            {
                return false;
            }

            if (rank[root_i] < rank[root_j]) 
            {
                parent[root_i] = root_j;
            } 

            else if (rank[root_i] > rank[root_j]) 
            {
                parent[root_j] = root_i;
            } 

            else 
            {
                parent[root_j] = root_i;
                rank[root_i]++;
            }
            return true;
        }
};

#endif
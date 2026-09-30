# Programming Assignment 1: Union-Find Empirical Study

This repository contains an implementation of Kruskal's Minimum Spanning Tree (MST) algorithm, driven by a custom Disjoint Set (Union-Find) data structure. It was built for Track A to empirically compare the performance of three Union-Find variants across sparse and dense graphs.

## Repository Structure

* `include/union_find.hpp`: The core Disjoint Set class implementing Naive Quick-Union, Union-by-Rank, and Union-by-Rank with Path Compression.
* `src/kruskal.cpp`: The MST algorithm that utilizes the Union-Find structure for cycle detection.
* `benchmarks/generator.cpp`: A memory-optimized random graph generator using a 1D boolean adjacency matrix.
* `benchmarks/benchmark_runner.cpp`: The C++ timing harness that executes the empirical study and exports data.
* `benchmarks/plot_results.py`: A Python script that reads the exported data and renders performance graphs.
* `data/`: Directory where the raw `results.csv` and generated matplotlib PNGs are saved.

## Prerequisites

To compile and run this project, you will need:

* A C++ compiler supporting C++17 (e.g., GCC or Clang).
* Python 3.x.
* Python libraries: `pandas` and `matplotlib` (`pip install pandas matplotlib`).

## How to Build and Reproduce Results

Follow these commands from the root directory of the repository to reproduce the empirical study:

**1. Compile the benchmarking suite**
Use the `-O3` flag to ensure the compiler applies maximum optimization, providing accurate performance metrics.

```bash
g++ -O3 -std=c++17 src/kruskal.cpp benchmarks/generator.cpp benchmarks/benchmark_runner.cpp -o benchmark

```

**2. Run the C++ benchmark**
This will generate graphs ranging from $V=1000$ to $V=10000$, run all three Union-Find variants on each, and output the raw timing data.

```bash
./benchmark

```

*Note: This will automatically create or overwrite `data/results.csv`.*

**3. Generate the performance visualizations**
Run the Python plotting script to parse the CSV and create the final line graphs.

```bash
python benchmarks/plot_results.py

```

## Expected Output

After executing the steps above, the `data/` directory will contain:

1. `results.csv`: Raw execution times (in milliseconds) for all variants across all vertex counts.
2. `sparse_plot.png`: A graph comparing performance on sparse networks ($E = 3V$).
3. `dense_plot.png`: A graph comparing performance on dense networks ($E \approx V^2/4$).
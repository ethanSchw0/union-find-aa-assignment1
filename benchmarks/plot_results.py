import pandas as pd
import matplotlib.pyplot as plt
import os

os.makedirs('data', exist_ok=True)

try:
    df = pd.read_csv('data/results.csv')
    
except FileNotFoundError:
    print("Error: data/results.csv not found. Run the C++ benchmark first.")
    exit(1)

sparse_df = df[df['Density'] == 'Sparse']
dense_df = df[df['Density'] == 'Dense']

def create_plot(data, title, filename):
    plt.figure(figsize=(10, 6))
    
    plt.plot(data['Vertices'], data['NaiveTime_ms'], marker='o', linewidth=2, label='Naive Union-Find', color='red')
    plt.plot(data['Vertices'], data['RankOnlyTime_ms'], marker='^', linewidth=2, label='Union by Rank', color='green')
    plt.plot(data['Vertices'], data['OptimizedTime_ms'], marker='s', linewidth=2, label='Union by Rank & Path Compression', color='blue')
    
    plt.title(title, fontsize=14, fontweight='bold')
    plt.xlabel('Number of Vertices (V)', fontsize=12)
    plt.ylabel('Execution Time (ms)', fontsize=12)
    plt.grid(True, linestyle='--', alpha=0.7)
    plt.legend(fontsize=12)
    
    plt.tight_layout()
    plt.savefig(f'data/{filename}')
    print(f"Saved plot: data/{filename}")
    plt.close()


create_plot(sparse_df, 'Kruskal MST Time vs Vertices (Sparse Graphs: E = 3V)', 'sparse_plot.png')
create_plot(dense_df, 'Kruskal MST Time vs Vertices (Dense Graphs: E ≈ V²/4)', 'dense_plot.png')
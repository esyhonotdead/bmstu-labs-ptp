import matplotlib.pyplot as plt

PATH = "./data/tsc/"


def read_data(filename):
    x = []
    y = []
    with open(filename, "r") as file:
        for line in file:
            parts = line.strip().split()
            if len(parts) >= 3:
                x_val = int(parts[0])
                y_val = float(parts[2])
                x.append(x_val)
                y.append(y_val)
    sorted_pairs = sorted(zip(x, y))
    x_sorted, y_sorted = zip(*sorted_pairs)
    return x_sorted, y_sorted


files = [
    PATH + "dataout_1_tsc.txt",
    PATH + "dataout_2_tsc.txt",
    PATH + "dataout_3_tsc.txt",
]
labels = ["dataout_1", "dataout_2", "dataout_3"]
colors = ["blue", "green", "red"]
markers = ["o", "s", "^"]

plt.figure(figsize=(10, 6))

for i, file in enumerate(files):
    x, y = read_data(file)
    plt.plot(
        x,
        y,
        label=labels[i],
        color=colors[i],
        marker=markers[i],
        linestyle="-",
        linewidth=1,
    )

plt.xlabel("Число элементов массива", fontsize=12)
plt.ylabel("Время выполнения", fontsize=12)
plt.title("Зависимость времени выполнения от числа элементов массива", fontsize=14)
plt.grid(True, linestyle="--", alpha=0.7)
plt.legend()
plt.tight_layout()
plt.savefig("./graphs/tsc_graph_01")
plt.show()

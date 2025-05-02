import matplotlib.pyplot as plt

PATH = "./data/tsc/"


def read_data(filename):
    x, means, mins, maxs = [], [], [], []
    with open(filename, "r") as file:
        for line in file:
            parts = line.strip().split()
            if len(parts) >= 6:
                x.append(int(parts[0]))
                means.append(float(parts[2]))
                mins.append(float(parts[4]))
                maxs.append(float(parts[5]))
    sorted_data = sorted(zip(x, means, mins, maxs), key=lambda t: t[0])
    x_sorted = [item[0] for item in sorted_data]
    means_sorted = [item[1] for item in sorted_data]
    mins_sorted = [item[2] for item in sorted_data]
    maxs_sorted = [item[3] for item in sorted_data]
    return x_sorted, means_sorted, mins_sorted, maxs_sorted


colors = ["blue", "green", "red"]
labels = ["dataout_1", "dataout_2", "dataout_3"]
alpha_fill = 0.15

plt.figure(figsize=(12, 7))

for i in range(3):
    x, mean, min_val, max_val = read_data(PATH + f"dataout_{i+1}_tsc.txt")

    plt.plot(
        x,
        mean,
        color=colors[i],
        label=labels[i],
        linewidth=2,
        marker="o" if i == 0 else "s" if i == 1 else "^",
        markersize=6,
    )

    plt.fill_between(
        x,
        min_val,
        max_val,
        color=colors[i],
        alpha=alpha_fill,
        label=f"Диапазон {labels[i]}",
    )

# Оформление
plt.xlabel("Число элементов массива", fontsize=12)
plt.ylabel("Время выполнения", fontsize=12)
plt.title("Кусочно-линейный график времени выполнения с диапазоном ошибок", fontsize=14)
plt.grid(True, linestyle="--", alpha=0.6)
plt.legend(loc="upper left", fontsize=10)
plt.tight_layout()
plt.savefig("./graphs/tsc_graph_02")
plt.show()

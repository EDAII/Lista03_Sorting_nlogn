import matplotlib.pyplot as plt

x = [10000, 50000, 100000, 500000, 1000000, 5000000, 10000000]
x2 = ["10k", "50k", "100k", "500k", "1m", "5m", "10m"]


def ssplit(l):
    length = len(l)
    return [l[p:p + 7] for p in range(0, length, 7)]


def generate_results():
    algs = ["quick", "merge"]
    res = []

    with open('data.txt') as file:
        for line in file:
            if line.strip() not in algs:
                res.append(line.split()[1])

    return res


data = ssplit([float(x) for x in generate_results()])
print(data)
plt.figure(1)

plt.plot(x2, data[0], 'ro')
plt.title('Quick Sort')
plt.ylabel('Tempo(s)')
plt.xlabel('Quantidade Numeros')
plt.grid(True)
plt.show()

plt.plot(x2, data[1], 'ro')
plt.title('Merge Sort')
plt.ylabel('Tempo(s)')
plt.xlabel('Quantidade Numeros')
plt.grid(True)
plt.show()

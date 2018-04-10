import matplotlib.pyplot as plt

x = [10, 100, 250, 500, 1000, 2500, 5000, 10000, 25000, 50000, 100000, 250000, 500000, 1000000, 2500000, 5000000, 10000000]
x2 = ["10", "100", "250", "500", "1k", "2.5k", "5k", "10k", "25k", "50k", "100k", "250k", "500k", "1m", "2.5m", "5m", "10m"]


def ssplit(l):
    length = len(l)
    return [l[p:p + 17] for p in range(0, length, 17)]


def generate_results():
    algs = ["quick", "merge", "radix"]
    res = []

    with open('data.txt') as file:
        for line in file:
            if line.strip() not in algs:
                res.append(line.split()[1])

    return res


data = ssplit([float(x) for x in generate_results()])
print(data)
plt.figure(1)

plt.plot(x2, data[0])
plt.title('Quick Sort')
plt.ylabel('Tempo(s)')
plt.xlabel('Quantidade Numeros')
plt.grid(True)
plt.show()

plt.plot(x2, data[1])
plt.title('Merge Sort')
plt.ylabel('Tempo(s)')
plt.xlabel('Quantidade Numeros')
plt.grid(True)
plt.show()

plt.plot(x2, data[2],)
plt.title('Radix Sort')
plt.ylabel('Tempo(s)')
plt.xlabel('Quantidade Numeros')
plt.grid(True)
plt.show()

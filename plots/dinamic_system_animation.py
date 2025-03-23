import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Загрузка данных из CSV-файла
data = pd.read_csv('csv_data/tmp.csv')

# Извлечение данных
x1 = data['x1'].values
v1 = data['v1'].values
x2 = data['x2'].values
v2 = data['v2'].values

# Создание фигуры и оси
fig, ax = plt.subplots()
ax.set_xlim(0, max(max(x1), max(x2)) + 0.1)
ax.set_ylim(-0.1, 0.1)

# Создание блоков
block1, = ax.plot([], [], 'bo', markersize=15)
block2, = ax.plot([], [], 'ro', markersize=15)


# Функция инициализации анимации
def init():
    block1.set_data([], [])
    block2.set_data([], [])
    return block1, block2,


# Функция обновления анимации
def update(frame):
    block1.set_data([x1[frame]], [0])  # Передаем как список
    block2.set_data([x2[frame]], [0])  # Передаем как список
    return block1, block2,


# Создание анимации
ani = animation.FuncAnimation(fig, update, frames=len(x1), init_func=init,
                              blit=True, interval=5)

# Показать анимацию
plt.show()
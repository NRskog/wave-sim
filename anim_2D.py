import numpy as np
import matplotlib.animation as animation
import matplotlib.pyplot as plt


def open_file(filename):
    read_file = open(filename, "r")
    list_of_lines = read_file.readlines()
    real_part = []
    imag_part = []
    for line in list_of_lines:
        real, imag = map(float, line.split())
        real_part.append(real)
        imag_part.append(imag)


    #print(len(real_part), len(imag_part))
    return np.array(real_part), np.array(imag_part)


#print(open_file("wave_res.txt"))


real_part, imag_part = open_file('wave_res.txt')
magnitude = np.sqrt(real_part**2 + imag_part**2)

fig, ax = plt.subplots()
x = np.arange(len(real_part))  # Använd np.arange för x-axeln
line, = ax.plot(x, magnitude, lw=2)

# x- och y gränser
ax.set_xlim(0, len(real_part) - 1)
ax.set_ylim(0, np.max(magnitude))

# uppd. för animation
def update(frame):
    line.set_data(x[:frame], magnitude[:frame])
    return line,

#animation
ani = animation.FuncAnimation(fig, update, frames=len(magnitude), blit=True, interval=50)

plt.xlabel('grid points')
plt.ylabel('magnitude')
plt.title('Wave func evolution')
ani.save('simulation.mp4', writer='ffmpeg', fps=30)

plt.show()


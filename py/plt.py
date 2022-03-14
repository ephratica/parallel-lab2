# -*- coding: utf-8 -*-
import matplotlib.pyplot as plt

name_list = ['int', 'float', 'double']
num_list = [6.23,
6.23,
6.24
]
num_list1 = [4.07,
4.08,
4.07
]
# l=[num_list1[i]/num_list[i]-1 for i in range(3)]
# print(l)
num_list2 = [7.68,
7.67,
7.68
]
# l=[num_list2[i]/num_list[i]-1 for i in range(3)]
# print(l)
x = list(range(len(num_list)))
total_width, n = 0.8, 3
width = total_width / n

plt.bar(x, num_list, width=width, label='common')
for i in range(len(x)):
    x[i] = x[i] + width
plt.bar(x, num_list1, width=width, label='multilink', tick_label=name_list)
for i in range(len(x)):
    x[i] = x[i] + width
plt.bar(x, num_list2, width=width, label='recursion', tick_label=name_list)
plt.ylabel("cache-loads(%)")
plt.xlabel("data type")
plt.legend()
plt.show()
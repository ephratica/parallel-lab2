import matplotlib.pyplot as plt

name_list = ['2^20', '2^25', '2^28']
num_list = [1,
1,
1
]
num_list1 = [755123/190875,
32167186/7977684,
290857940/74198531
]
# l=[num_list1[i]/num_list[i]-1 for i in range(3)]
# print(l)
num_list2 = [911283/182123,
38045323/6429668,
345035776/61311258
]
# l=[num_list2[i]/num_list[i]-1 for i in range(3)]
# print(l)
x = list(range(len(num_list)))
total_width, n = 0.8, 3
width = total_width / n

bar=plt.bar(x, num_list, width=width, label='common')
plt.bar_label(bar,label_type='edge')
for i in range(len(x)):
    x[i] = x[i] + width
bar=plt.bar(x, num_list1, width=width, label='omp', tick_label=name_list)
plt.bar_label(bar,label_type='edge')
for i in range(len(x)):
    x[i] = x[i] + width
bar=plt.bar(x, num_list2, width=width, label='omp simd', tick_label=name_list)
plt.bar_label(bar,label_type='edge')
plt.ylabel("times/second")
plt.xlabel("n")
plt.legend()
plt.show()

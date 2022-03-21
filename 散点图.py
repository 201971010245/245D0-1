import numpy as np
import matplotlib.pyplot as plt

#  在区间 [a, b] 上均匀地取指定数量的值
x = np.linspace(0.05, 10, 1000)  

np.random.seed(22)
y = np.random.randn(1000)

# 图表元素中正常显示中文字符
plt.rcParams['font.sans-serif'] = 'SimHei'
# 坐标轴刻度标签正常显示负号
plt.rcParams['axes.unicode_minus'] = False

plt.scatter(x, y,
            s=87,  # 标记点大小
            marker='*',  # 标记点的样式 星号
            c='g',  # green 绿色
            linewidths=0.41,
            edgecolor='y',  # 边缘颜色
            label='scatter figure')

plt.xticks(size=12, color='grey')  # x 轴刻度标签
plt.yticks(size=12, color='grey')  # y 轴刻度标签
plt.title('散点图', size=14, color='y');  # 添加图表标题
plt.legend()  # 添加图例

# 设置坐标轴刻度范围
plt.xlim(-0.5, 10.5)  
plt.ylim(-3.5, 3.5);

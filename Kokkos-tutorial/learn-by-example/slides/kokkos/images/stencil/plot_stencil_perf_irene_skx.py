import numpy as np
import matplotlib.pyplot as plt
from matplotlib import rc
#rc('text', usetex=True)

size=np.array([32,48,64,96,128,160,192,224,256,320,384,448,512,640])

# test_stencil_3d_flat
v0=np.array([50.2433,57.1813,57.262,57.0929,57.5146,57.4686,57.6813,56.908,56.9097,56.9656,57.2515,56.6332,57.1319,57.0381])

# test_stencil_3d_flat_vector without views
v1=np.array([196.166,301.695,334.484,392.235,397.446,399.13,381.384,316.004,255.401,232.042,201.634,181.157,172.295,169.225])

# test_stencil_3d_flat_vector with    views
v2=np.array([200.504,380.747,605.479,1001.12,1180.76,1215.78,682.135,344.527,267.268,240.274,204.822,182.524,172.65,169.839])

# test_stencil_3d_range
v3=np.array([124.909,181.715,209.138,214.847,219.636,220.684,215.351,212.494,202.487,196.481,195.375,194.521,195.282,192.98])

# test_stencil_3d_range_vector
v4=np.array([217.51,446.821,545.41,1087.23,1192.84,1034.95,673.593,342.019,267.128,241.168,204.15,184.19,172.43,169.687])

# test_stencil_3d_range_vector2
v5=np.array([173.186,298.27,399.369,427.633,415.486,401.113,265.919,194.39,168.675,158.241,159.584,153.051,169.094,171.998])

plt.plot(size,v0, label='# test_stencil_3d_flat')
plt.plot(size,v1, label='# test_stencil_3d_flat_vector without views')
plt.plot(size,v2, label='# test_stencil_3d_flat_vector with    views')
plt.plot(size,v3, label='# test_stencil_3d_range')
plt.plot(size,v4, label='# test_stencil_3d_range_vector')
plt.plot(size,v5, label='# test_stencil_3d_range_vector2')
plt.grid(True)
plt.title('3d Heat kernel performance')
plt.xlabel('N - linear size')
plt.ylabel(r'Bandwidth (GBytes/s)')
plt.legend()
plt.show()

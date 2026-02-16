# gm_network

`gm_network` 模块提供获取网络接口信息功能。提供简单、易用的接口，方便用户获取网络接口信息。
本模块仅提供了 get 类接口，如需设置可使用 [libnl](https://github.com/thom311/libnl) 或 [NetworkManager](https://github.com/NetworkManager/NetworkManager) 等第三方库。

## 目录结构

```bash
gm_network/
├── build/                # 编译输出目录
├── CMakeLists.txt
├── examples/             # 示例代码
│   ├── CMakeLists.txt
│   └── example_network.c
├── gm_network/           # 模块核心源码
│   ├── CMakeLists.txt
│   ├── gm_network.c
│   └── gm_network.h
├── LICENSE
└── README.md
```

## 编译与运行

### 编译

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
```

编译完成后，`build` 目录结构如下（仅说明关键文件）：

``` bash
build/
├── examples/
│   └── example_network # 可执行文件
└── gm_network/
    └── libgm_network.a # 静态库
```

### 运行示例

```bash
$ cd build/examples
$ sudo ./example_network
```

注意：

- 执行 `example_network` 时需要 root 权限，因为需要使用 ICMP 协议进行 ping 操作

## 移植

### 方式一：使用源码

将 `gm_network` 目录下的源码文件复制到你的项目目录中，并在代码中包含 `gm_network.h` 头文件。
可参考 `gm_network/CMakeLists.txt` 中的写法，将其作为一个独立模块进行编译。

### 方式二：使用静态库

将生成的 `libgm_network.a` 和 `gm_network.h` 拷贝到你的项目中，包含 `gm_network.h` 头文件并链接 `libgm_network.a` 库即可。

## 注意事项

- 接口行为及返回值请以头文件注释为准

## 问题与建议

有任何问题或建议欢迎提交 [issue](https://github.com/general-modules/gm_network/issues) 进行讨论。

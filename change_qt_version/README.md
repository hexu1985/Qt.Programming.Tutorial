### 修改编译工程使用的qt版本

我们通过访问<https://download.qt.io/>可以下载不同的qt版本，并且可以在linux上安装多个版本的qt。
当我们生成qt工程，编译qt程序时，如何选择相应的qt版本呢？根据我们使用qmake还是cmake的不同，修改方式也不同。

#### qmake方式

首先，通过qtchooser增加相应的qt版本的qmake，例如：

```
$ qtchooser -install qt-5.12.12 /home/hexu/Qt5.12.12/5.12.12/gcc_64/bin/qmake
# 根据自己的安装路径，提示无效命令记得安装qtchooser，sudo apt-get install qtchooser
$ qtchooser -l
4
5
default
qt-5.12.12          # qtchooser -install新增的版本
qt4-x86_64-linux-gnu
qt4
qt5-x86_64-linux-gnu
qt5
```

通过QT_SELECT环境变量控制当前使用的qt版本

```
export QT_SELECT=qt-5.12.12
# 可以把这条语句加到~/.profile里，这样就不用每次登录新窗口执行环境变量导出了
```

然后执行qmake -v验证是否使用的是你指定的qt版本

```
$ qmake -v
QMake version 3.1
Using Qt version 5.12.12 in /home/hexu/Qt5.12.12/5.12.12/gcc_64/lib
```

#### cmake方式

通过把qt的路径添加到CMAKE_PREFIX_PATH变量里实现修改依赖qt版本 

```
$ vim CMakeLists.txt

list(APPEND CMAKE_PREFIX_PATH "/home/hexu/Qt5.12.12/5.12.12/gcc_64")
````

#### 验证使用的qt版本

可以通过ldd命令查看可执行程序依赖的版本

```
$ ldd hello
        linux-vdso.so.1 (0x00007fff487e9000)
        libQt5Widgets.so.5 => /home/hexu/Qt5.12.12/5.12.12/gcc_64/lib/libQt5Widgets.so.5 (0x00007f36ee74d000)
        libQt5Core.so.5 => /home/hexu/Qt5.12.12/5.12.12/gcc_64/lib/libQt5Core.so.5 (0x00007f36edfb0000)
        libstdc++.so.6 => /usr/lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007f36edc27000)
        libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007f36eda0f000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f36ed61e000)
        libQt5Gui.so.5 => /home/hexu/Qt5.12.12/5.12.12/gcc_64/lib/libQt5Gui.so.5 (0x00007f36ecdcf000)
        libpthread.so.0 => /lib/x86_64-linux-gnu/libpthread.so.0 (0x00007f36ecbb0000)
        libGL.so.1 => /usr/lib/x86_64-linux-gnu/libGL.so.1 (0x00007f36ec924000)
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f36ec586000)
        libz.so.1 => /lib/x86_64-linux-gnu/libz.so.1 (0x00007f36ec369000)
        libicui18n.so.56 => /home/hexu/Qt5.12.12/5.12.12/gcc_64/lib/libicui18n.so.56 (0x00007f36ebed0000)
        libicuuc.so.56 => /home/hexu/Qt5.12.12/5.12.12/gcc_64/lib/libicuuc.so.56 (0x00007f36ebb18000)
        libicudata.so.56 => /home/hexu/Qt5.12.12/5.12.12/gcc_64/lib/libicudata.so.56 (0x00007f36ea135000)
        libdl.so.2 => /lib/x86_64-linux-gnu/libdl.so.2 (0x00007f36e9f31000)
        libgthread-2.0.so.0 => /usr/lib/x86_64-linux-gnu/libgthread-2.0.so.0 (0x00007f36e9d2f000)
        libglib-2.0.so.0 => /usr/lib/x86_64-linux-gnu/libglib-2.0.so.0 (0x00007f36e9a18000)
        /lib64/ld-linux-x86-64.so.2 (0x00007f36ef1a0000)
        libGLX.so.0 => /usr/lib/x86_64-linux-gnu/libGLX.so.0 (0x00007f36e97e7000)
        libGLdispatch.so.0 => /usr/lib/x86_64-linux-gnu/libGLdispatch.so.0 (0x00007f36e9531000)
        libpcre.so.3 => /lib/x86_64-linux-gnu/libpcre.so.3 (0x00007f36e92bf000)
        libX11.so.6 => /usr/lib/x86_64-linux-gnu/libX11.so.6 (0x00007f36e8f87000)
        libxcb.so.1 => /usr/lib/x86_64-linux-gnu/libxcb.so.1 (0x00007f36e8d5f000)
        libXau.so.6 => /usr/lib/x86_64-linux-gnu/libXau.so.6 (0x00007f36e8b5b000)
        libXdmcp.so.6 => /usr/lib/x86_64-linux-gnu/libXdmcp.so.6 (0x00007f36e8955000)
        libbsd.so.0 => /lib/x86_64-linux-gnu/libbsd.so.0 (0x00007f36e8740000)
        librt.so.1 => /lib/x86_64-linux-gnu/librt.so.1 (0x00007f36e8538000)
```

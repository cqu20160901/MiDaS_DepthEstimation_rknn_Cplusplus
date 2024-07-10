# MiDaS_DepthEstimation_rknn_Cplusplus
MiDaS（Multiple Depth Estimation Accuracy with Single Network）单目深度估计，部署 rk3588。


模型转换和仿真测试参考 [onnx转rknn](https://blog.csdn.net/zhangqian_1/article/details/140291694)。

由于模型文件比较大，无法和代码一起上传。[rknn模型文件](https://github.com/cqu20160901/MiDaS_DepthEstimation_rknn_Cplusplus/releases/tag/V1.0)

## 编译和运行

1）编译

```
cd examples/rknn_MiDaSDepth

bash build-linux_RK3588.sh

```

2）运行

```
cd install/rknn_MIDASDepth_demo_Linux

./rknn_MIDASDepth_demo

```

注意：修改模型、测试图像、保存图像的路径，修改文件为src下的main.cc

```

int main(int argc, char **argv)
{
    char model_path[256] = "/home/firefly/zhangqian/rknn/examples/rknn_MiDaSDepth/model/RK3588/midas_v21_384.rknn";
    char image_path[256] = "/home/firefly/zhangqian/rknn/examples/rknn_MiDaSDepth/test.jpg";
    char save_image_path[256] = "/home/firefly/zhangqian/rknn/examples/rknn_MiDaSDepth/test_result.jpg";

    detect(model_path, image_path, save_image_path);
    return 0;
}
```

# 板端测试效果
![image](https://github.com/cqu20160901/MiDaS_DepthEstimation_rknn_Cplusplus/blob/main/examples/rknn_MiDaSDepth/test.jpg)
![image](https://github.com/cqu20160901/MiDaS_DepthEstimation_rknn_Cplusplus/blob/main/examples/rknn_MiDaSDepth/test_result.jpg)


#ifndef _POSTPROCESS_H_
#define _POSTPROCESS_H_

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <vector>

#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

typedef signed char int8_t;
typedef unsigned int uint32_t;

class MiDaS
{
public:
    MiDaS();

    ~MiDaS();

    int GetConvDetectionResult(int8_t **pBlob, std::vector<int> &qnt_zp, std::vector<float> &qnt_scale, cv::Mat &SegMask);

    int InputHeight_ = 224;
    int InputWidth_ = 384;

    float MaxValue_ = 255;

    float DepthMap_[224][384];

    cv::Mat DepthMapGray_ = cv::Mat::zeros(InputHeight_, InputWidth_, CV_8UC1);
};

#endif

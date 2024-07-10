#include "postprocess.h"

static float DeQnt2F32(int8_t qnt, int zp, float scale)
{
    return ((float)qnt - (float)zp) * scale;
}

MiDaS::MiDaS()
{
}

MiDaS::~MiDaS()
{
}

int MiDaS::GetConvDetectionResult(int8_t **PtrBlob, std::vector<int> &qnt_zp, std::vector<float> &qnt_scale, cv::Mat &SegMask)
{
    int ret = 0;
    int8_t *Output = (int8_t *)PtrBlob[0];
    int QuantZp = qnt_zp[0];
    float QuantScale = qnt_scale[0];

    float DepthMin = 0;
    float DepthMax = 0;
    float DeQntValue = 0;

    for (int h = 0; h < InputHeight_; h++)
    {
        for (int w = 0; w < InputWidth_; w++)
        {
            DeQntValue = DeQnt2F32(Output[h * InputWidth_ + w], QuantZp, QuantScale);
            DepthMap_[h][w] = DeQntValue;

            if (h == 0 && w == 0)
            {
                DepthMin = DeQntValue;
                DepthMax = DeQntValue;
            }
            else
            {
                if (DeQntValue < DepthMin)
                {
                    DepthMin = DeQntValue;
                }

                if (DeQntValue > DepthMax)
                {
                    DepthMax = DeQntValue;
                }
            }
        }
    }

    for (int h = 0; h < InputHeight_; h++)
    {
        for (int w = 0; w < InputWidth_; w++)
        {
            DeQntValue = DepthMap_[h][w];
            DepthMap_[h][w] = MaxValue_ * (DeQntValue - DepthMin) / (DepthMax - DepthMin);

            DepthMapGray_.at<uchar>(h, w) = static_cast<uchar>(int(DepthMap_[h][w]));
        }
    }

    cv::applyColorMap(DepthMapGray_, SegMask, cv::COLORMAP_AUTUMN);

    return ret;
}
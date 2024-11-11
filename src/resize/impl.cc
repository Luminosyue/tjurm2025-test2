#include "impls.h"
#include <opencv2/opencv.hpp>

cv::Mat my_resize(const cv::Mat& input, float scale) {
    /**
     * 要求：
     *      实现resize算法，只能使用基础的语法，比如说for循环，Mat的基本操作。不能
     * 用cv::resize。resize算法的内容自行查找学习，不是很难。
     * 
     * 提示：
     * 无。
     * 
     * 通过条件：
     * 运行测试点，你的结果跟答案长的差不多就行。
     */
    int new_rows = input.rows * scale, new_cols = input.cols * scale;
    // IMPLEMENT YOUR CODE HERE
    cv::Mat output(new_rows, new_cols, input.type());

   
  for (int i = 0; i < new_rows; ++i) {
        for (int j = 0; j < new_cols; ++j) {
            
            float x = j / scale;
            float y = i / scale;

            
            int x_nearest = static_cast<int>(round(x));
            int y_nearest = static_cast<int>(round(y));

            
            if (x_nearest < input.cols && y_nearest < input.rows) {
                
                if (input.channels() == 3) { 
                    output.at<cv::Vec3b>(i, j) = input.at<cv::Vec3b>(y_nearest, x_nearest);
                } else { 
                    output.at<uchar>(i, j) = input.at<uchar>(y_nearest, x_nearest);
                }
            }
        }
    }

    return output;
}
//
//  NNClassifier.h
//  TLD
//
//  Created by 陈裕昕 on 11/4/14.
//  Copyright (c) 2014 Fudan. All rights reserved.
//

#ifndef __TLD__NNClassifier__
#define __TLD__NNClassifier__

#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include "TLDSystemStruct.h"

using namespace std;
using namespace cv;

class NNClassifier
{
private:
//debug
public:
//end debug
    //save positive patches and negative patches in [1 x (patchSize ^ 2)]
    vector<Mat> pPatches, nPatches;

    float calcNCC(const Mat &patch1, const Mat &patch2);
    
    Mat getPatch(const Mat &img);
    
    void getS(const Mat &img, float &Sp, float &Sn, float &Sr, float &Sc);
    float calcSr(const Mat &img);
    bool update(const Mat &patch, int c);
    
    Mat newSamplesP, newSamplesN;
    void addToNewSamples(const Mat &patch, const int c);
    
public:
    float thPos;
    
    NNClassifier();
    
    ~NNClassifier();
    
    void train(const TYPE_TRAIN_DATA_SET &trainDataSet);
    
    void showModel();
    
    // assert : img.type() == CV_8U
    bool getClass(const Mat &img, TYPE_DETECTOR_SCANBB &sbb);
};

#endif /* defined(__TLD__NNClassifier__) */

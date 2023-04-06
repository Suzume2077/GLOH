#pragma once
#include<opencv2/opencv.hpp>

using namespace cv;

namespace A_A {
	class GLOH
	{

	public:
		static Ptr<GLOH> create(int nfeatures = 0, int nOctaveLayers = 3,double contrastThreshold = 0.04, double edgeThreshold = 10,double sigma = 1.6);

		virtual void detectAndCompute(InputArray img, InputArray mask,
			std::vector<KeyPoint>& keypoints,
			OutputArray descriptors,
			bool useProvidedKeypoints = false) = 0;

	};

	typedef GLOH GLOHFeatureDetector;
	typedef GLOH GLOHDescriptorExtractor;
}



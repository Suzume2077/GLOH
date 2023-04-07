#pragma once
#include<opencv2/opencv.hpp>
#include<string>

using namespace cv;
using std::string;

namespace A_A {
	class GLOH : public Feature2D
	{

	public:
		static Ptr<GLOH> create(int nfeatures = 0, int nOctaveLayers = 3,double contrastThreshold = 0.04, double edgeThreshold = 10,double sigma = 1.6,int descriptorType=CV_32F);

		virtual void detectAndCompute(InputArray img, InputArray mask,
			std::vector<KeyPoint>& keypoints,
			OutputArray descriptors,
			bool useProvidedKeypoints = false) = 0;

		virtual string getDefaultName() const override;
		virtual void setNFeatures(int maxFeatures) = 0;
		virtual int getNFeatures() const = 0;

		virtual void setNOctaveLayers(int nOctaveLayers) = 0;
		virtual int getNOctaveLayers() const = 0;
		virtual void setContrastThreshold(double contrastThreshold) = 0;
		virtual double getContrastThreshold() const = 0;
		virtual void setEdgeThreshold(double edgeThreshold) = 0;
		virtual double getEdgeThreshold() const = 0;
		virtual void setSigma(double sigma) = 0;
		virtual double getSigma() const = 0;

	};

	typedef GLOH GLOHFeatureDetector;
	typedef GLOH GLOHDescriptorExtractor;
}



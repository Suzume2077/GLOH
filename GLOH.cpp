#include "GLOH.h"


namespace A_A {
	class GLOH_Impl : public GLOH
	{
	public:
		explicit GLOH_Impl(int nfeatures = 0, int nOctaveLayers = 3,
			double contrastThreshold = 0.04, double edgeThreshold = 10,
			double sigma = 1.6);

		//! returns the descriptor size in floats (128)
		int descriptorSize() const;

		//! returns the descriptor type
		int descriptorType() const;

		//! returns the default norm type
		int defaultNorm() const;

		//! finds the keypoints and computes descriptors for them using SIFT algorithm.
		//! Optionally it can compute descriptors for the user-provided keypoints
		void detectAndCompute(InputArray img, InputArray mask,
			std::vector<KeyPoint>& keypoints,
			OutputArray descriptors,
			bool useProvidedKeypoints = false);


		void buildGaussianPyramid(const Mat& base, std::vector<Mat>& pyr, int nOctaves) const;
		void buildDoGPyramid(const std::vector<Mat>& pyr, std::vector<Mat>& dogpyr) const;
		void findScaleSpaceExtrema(const std::vector<Mat>& gauss_pyr, const std::vector<Mat>& dog_pyr,
			std::vector<KeyPoint>& keypoints) const;

	protected:
		 int nfeatures;
		 int nOctaveLayers;
		 double contrastThreshold;
		 double edgeThreshold;
		 double sigma;
	};

	Ptr<GLOH> GLOH::create(int _nfeatures, int _nOctaveLayers, double _contrastThreshold, double _edgeThreshold, double _sigma)
	{
		return makePtr<GLOH_Impl>(_nfeatures, _nOctaveLayers, _contrastThreshold, _edgeThreshold, _sigma);

	}
	GLOH_Impl::GLOH_Impl(int _nfeatures, int _nOctaveLayers, double _contrastThreshold, double _edgeThreshold, double _sigma):
		nfeatures(_nfeatures), nOctaveLayers(_nOctaveLayers),contrastThreshold(_contrastThreshold), edgeThreshold(_edgeThreshold), sigma(_sigma)
	{
	}
	int GLOH_Impl::descriptorSize() const
	{
		return 128;
	}
	int GLOH_Impl::descriptorType() const
	{
		return 0;
	}
	int GLOH_Impl::defaultNorm() const
	{
		return 0;
	}
	void GLOH_Impl::detectAndCompute(InputArray img, InputArray mask, std::vector<KeyPoint>& keypoints, OutputArray descriptors, bool useProvidedKeypoints)
	{
	}
	void GLOH_Impl::buildGaussianPyramid(const Mat& base, std::vector<Mat>& pyr, int nOctaves) const
	{
	}
	void GLOH_Impl::buildDoGPyramid(const std::vector<Mat>& pyr, std::vector<Mat>& dogpyr) const
	{
	}
	void GLOH_Impl::findScaleSpaceExtrema(const std::vector<Mat>& gauss_pyr, const std::vector<Mat>& dog_pyr, std::vector<KeyPoint>& keypoints) const
	{
	}
}
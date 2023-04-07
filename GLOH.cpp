#include "GLOH.h"


namespace A_A {
	class GLOH_Impl : public GLOH
	{
	public:
		explicit GLOH_Impl(int nfeatures = 0, int nOctaveLayers = 3,
			double contrastThreshold = 0.04, double edgeThreshold = 10,
			double sigma = 1.6, int descriptorType = CV_32F);

		//! returns the descriptor size in floats (128)
		int descriptorSize() const override;

		//! returns the descriptor type
		int descriptorType() const override;

		//! returns the default norm type
		int defaultNorm() const override;

		//! finds the keypoints and computes descriptors for them using SIFT algorithm.
		//! Optionally it can compute descriptors for the user-provided keypoints
		void detectAndCompute(InputArray img, InputArray mask,
			std::vector<KeyPoint>& keypoints,
			OutputArray descriptors,
			bool useProvidedKeypoints = false) override;


		void buildGaussianPyramid(const Mat& base, std::vector<Mat>& pyr, int nOctaves) const;
		void buildDoGPyramid(const std::vector<Mat>& pyr, std::vector<Mat>& dogpyr) const;
		void findScaleSpaceExtrema(const std::vector<Mat>& gauss_pyr, const std::vector<Mat>& dog_pyr,
			std::vector<KeyPoint>& keypoints) const;


		void read(const FileNode& fn) override;
		void write(FileStorage& fs) const override;

		void setNFeatures(int maxFeatures) override { nfeatures = maxFeatures; }
		int getNFeatures() const override { return nfeatures; }

		void setNOctaveLayers(int nOctaveLayers_) override { nOctaveLayers = nOctaveLayers_; }
		int getNOctaveLayers() const override { return nOctaveLayers; }

		void setContrastThreshold(double contrastThreshold_) override { contrastThreshold = contrastThreshold_; }
		double getContrastThreshold() const override { return contrastThreshold; }

		void setEdgeThreshold(double edgeThreshold_) override { edgeThreshold = edgeThreshold_; }
		double getEdgeThreshold() const override { return edgeThreshold; }

		void setSigma(double sigma_) override { sigma = sigma_; }
		double getSigma() const override { return sigma; }




	protected:
		 int nfeatures;
		 int nOctaveLayers;
		 double contrastThreshold;
		 double edgeThreshold;
		 double sigma;
		 int descriptor_type;
	};

	Ptr<GLOH> GLOH::create(int _nfeatures, int _nOctaveLayers, double _contrastThreshold, double _edgeThreshold, double _sigma, int _descriptorType)
	{
		return makePtr<GLOH_Impl>(_nfeatures, _nOctaveLayers, _contrastThreshold, _edgeThreshold, _sigma, _descriptorType);

	}
	string GLOH::getDefaultName() const
	{
		return (Feature2D::getDefaultName() + ".GLOH");
	}
	GLOH_Impl::GLOH_Impl(int _nfeatures, int _nOctaveLayers, double _contrastThreshold, double _edgeThreshold, double _sigma, int _descriptorType):
		nfeatures(_nfeatures), nOctaveLayers(_nOctaveLayers),contrastThreshold(_contrastThreshold),
		edgeThreshold(_edgeThreshold), sigma(_sigma), descriptor_type(_descriptorType)
	{
	}
	int GLOH_Impl::descriptorSize() const
	{
		return 128;
	}
	int GLOH_Impl::descriptorType() const
	{
		return descriptor_type;
	}
	int GLOH_Impl::defaultNorm() const
	{
		return NORM_L2;
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

	void GLOH_Impl::read(const FileNode& fn)
	{
		// if node is empty, keep previous value
		if (!fn["nfeatures"].empty())
			fn["nfeatures"] >> nfeatures;
		if (!fn["nOctaveLayers"].empty())
			fn["nOctaveLayers"] >> nOctaveLayers;
		if (!fn["contrastThreshold"].empty())
			fn["contrastThreshold"] >> contrastThreshold;
		if (!fn["edgeThreshold"].empty())
			fn["edgeThreshold"] >> edgeThreshold;
		if (!fn["sigma"].empty())
			fn["sigma"] >> sigma;
		if (!fn["descriptorType"].empty())
			fn["descriptorType"] >> descriptor_type;
	}
	void GLOH_Impl::write(FileStorage& fs) const
	{
		if (fs.isOpened())
		{
			fs << "name" << getDefaultName();
			fs << "nfeatures" << nfeatures;
			fs << "nOctaveLayers" << nOctaveLayers;
			fs << "contrastThreshold" << contrastThreshold;
			fs << "edgeThreshold" << edgeThreshold;
			fs << "sigma" << sigma;
			fs << "descriptorType" << descriptor_type;
		}
	}

}
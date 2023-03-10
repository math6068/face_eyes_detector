#include <detector_lib/FaceDetector.hpp>
#include <gtest/gtest.h>

TEST(FaceDetectionTest, DetectFaces)
{
    // Load the input image
    cv::Mat img = cv::imread("data/CelebA_sample_image/sample_image.png");
    if (img.empty()) {
        std::cout << "Input image file not found " << std::endl;
    }
    // Initialize face detector and detect faces
    FaceDetector faceDetector("data/model_weight/haarcascade_frontalface_alt.xml");
    
    // Detect faces in the input image
    std::vector<cv::Rect> faces = faceDetector.face_detect(img);

    // Check that at least one face was detected
    ASSERT_GT(faces.size(), 0);
}
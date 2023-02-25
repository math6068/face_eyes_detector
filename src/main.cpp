#include "../include/FaceDetector.hpp"

int main(int argc, char* argv[])
{

    // Load image
    cv::Mat img = cv::imread(argv[1]);
    if (img.empty()) {
        std::cout << "Input image file not found " << std::endl;
        return 1;
    }

    // Create a face detector
    FaceDetector faceDetector("data/model_weight/haarcascade_frontalface_alt.xml");
    std::cout << "here 1" << std::endl;
    // Detect faces in the input image
    std::vector<cv::Rect> faces;
    faceDetector.face_detect(img, faces);
    std::cout << "here 2: " << faces.size() << std::endl;
    // Draw rectangles around the detected faces
    for (int i = 0; i < faces.size(); i++)
    {
        cv::rectangle(img, faces[i], cv::Scalar(0, 255, 0), 2);
    }

    cv::imwrite(argv[2], img);
    
    return 0;
}

//#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <opencv/cv.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc.hpp>
//using namespace std;
//using namespace cv;
//
//int ROW=240;
//int CLO=320;
//
//int threshold_value = 0;
//int threshold_type=3;
//int const max_value = 255;
//int const max_BINARY_value = 255;
//char* trackbar_value = "Value";
//
//String window_name0="origin";
//String window_name1="target";
//String window_name2="modifiedxor";
//String window_name3="unmodifiedxor";
//
//
//vector<Mat> channels0;
//vector<Mat> channels1;
//vector<Mat> channels2;
//vector<Mat>	channels3;
//
//Mat image0,image1,imageT,imageD;
//double fps ;
//Size size(CLO,ROW);
//
//void Threshold_Demo( int, void* );
//
//int main() {
//
//	bool loop = true;
//
//	namedWindow(window_name0,1);
//	namedWindow(window_name1,1);
//	namedWindow(window_name2,1);
//	namedWindow(window_name3,1);
//
//	createTrackbar( trackbar_value,
//			window_name2, &threshold_value,
//			max_value, Threshold_Demo );
//	char KeyStroke;
//
//	VideoCapture cap;
//	cap.open(0);
//
//	while(loop == true)
//	{
//
//		try
//		{
//			cap>>image0;
//			//fps = cap.get(CAP_PROP_FPS);
//			if(KeyStroke==' ')
//			{
//				break;
//			}
//			resize(image0,image0,size,CV_INTER_NN);
//			if(!image0.data)
//			{
//				cout<<"Could not open or find the image0"<< endl;
//				return -1;
//			}
//			if(image1.empty())
//			{
//				image1=image0.clone();
//				continue;
//			}
//
//			imageT=Mat::zeros(ROW,CLO,CV_8UC3);
//			imageD=Mat::zeros(ROW,CLO,CV_8UC3);
//
//			imshow(window_name0,image0);
//
//
//			split(image0,channels0);
//			Mat BlueI(channels0[0]);
//			Mat GreenI(channels0[1]);
//			Mat RedI(channels0[2]);
//
//			split(image1,channels1);
//			Mat BlueR(channels1[0]);
//			Mat GreenR(channels1[1]);
//			Mat RedR(channels1[2]);
//
//			split(imageT,channels2);
//			Mat BlueT(channels2[0]);
//			Mat GreenT(channels2[1]);
//			Mat RedT(channels2[2]);
//
//
//			split(imageD,channels3);
//			Mat BlueD(channels3[0]);
//			Mat GreenD(channels3[1]);
//			Mat RedD(channels3[2]);
//
//			bitwise_xor(BlueI, BlueR, BlueT);
//			bitwise_xor(GreenI, GreenR, GreenT);
//			bitwise_xor(RedI, RedR, RedT);
//
//			merge(channels2, imageT);
//			Threshold_Demo(0,0);
//			KeyStroke = cvWaitKey(30);
//			image1=image0.clone();
//			imshow(window_name1,image1);
//		}
//		catch (Exception& e)
//		{
//			const char* err_msg = e.what();
//			std::cout << "exception caught: imshow:\n" << err_msg << std::endl;
//		}
//
//		char key = waitKey(33) & 0xFF;
//		if (key == 'q')
//		{
//			std::cout <<"6"<<std::endl;
//			loop = false;
//		}
//	}
//	return 0;
//
//}
//void Threshold_Demo( int, void* )
//{
//	Mat des=imageT;
//	//threshold(imageT, des, threshold_value, max_BINARY_value,threshold_type );
//
//	uint8_t* pixelPtr = (uint8_t*)des.data;
//	//cout<<"pxiel count:"<<pixelPtr;
//
//	int cn = des.channels();
//	int count=0;
//	Scalar_<uint8_t> bgrPixel;
//	if(threshold_value>0)
//	for(int i = 0; i < des.rows; i++)
//	{
//		for(int j = 0; j < des.cols; j++)
//		{
//			bgrPixel.val[0] = pixelPtr[i*des.cols*cn + j*cn + 0]; // B
//			bgrPixel.val[1] = pixelPtr[i*des.cols*cn + j*cn + 1]; // G
//			bgrPixel.val[2] = pixelPtr[i*des.cols*cn + j*cn + 2]; // R
//			if(!bgrPixel.val[0]==0||!bgrPixel.val[1]==0||!bgrPixel.val[2]==0)
//			{
//				pixelPtr[i*des.cols*cn + j*cn + 0]=bgrPixel.val[0]/threshold_value*threshold_value;
//				pixelPtr[i*des.cols*cn + j*cn + 1]=bgrPixel.val[1]/threshold_value*threshold_value;
//				pixelPtr[i*des.cols*cn + j*cn + 2]=bgrPixel.val[2]/threshold_value*threshold_value;
//			}
//
//		}
//	}
//
//
//
//
//	imshow( window_name2, des);
//	split(image0,channels0);
//	Mat BlueI(channels0[0]);
//	Mat GreenI(channels0[1]);
//	Mat RedI(channels0[2]);
//	split(des,channels2);
//	Mat BlueT(channels2[0]);
//	Mat GreenT(channels2[1]);
//	Mat RedT(channels2[2]);
//	split(imageD,channels3);
//	Mat BlueD(channels3[0]);
//	Mat GreenD(channels3[1]);
//	Mat RedD(channels3[2]);
//	bitwise_xor(BlueT, BlueI, BlueD);
//	bitwise_xor(GreenT, GreenI, GreenD);
//	bitwise_xor(RedT, RedI, RedD);
//	merge(channels3, imageD);
//	imshow(window_name3,imageD);
//
//
//	//pixelPtr = (uint8_t*)des.data;
//	//cout<<"pxiel count:"<<pixelPtr;
//	 count=0;
//
//
//	uint8_t final_data[320*240*3];
//
//	int zero_count=0;
//
//	for(int i = 0; i < des.rows; i++)
//	{
//		for(int j = 0; j < des.cols; j++)
//		{
//			bgrPixel.val[0] = pixelPtr[i*des.cols*cn + j*cn + 0]; // B
//			bgrPixel.val[1] = pixelPtr[i*des.cols*cn + j*cn + 1]; // G
//			bgrPixel.val[2] = pixelPtr[i*des.cols*cn + j*cn + 2]; // R
//			if(!bgrPixel.val[0]==0||!bgrPixel.val[1]==0||!bgrPixel.val[2]==0)
//			{
//				count++;
//				//
//				uint8_t o=zero_count/(256*256);
//				//
//				uint8_t p=zero_count%(256*256)/256;
//				//
//				uint8_t q=zero_count%(256*256)%256;
//				//置零
//				zero_count=0;
//			}
//			else
//			{
//				zero_count++;
//			}
//		}
//	}
//	//cout<<"fps:"<<fps<<"	======count:========"<<count<<endl;
//	cout<<"======count:========"<<count<<endl;
//}

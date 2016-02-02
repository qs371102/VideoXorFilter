//#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <opencv/cv.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc.hpp>
//using namespace std;
//using namespace cv;
////240
//int ROW=480;
////320
//int CLO=640;
//
//
//int mod=256;
//
//int threshold_value = 15;
///* 0: Binary
// 1: Binary Inverted
// 2: Threshold Truncated
// 3: Threshold to Zero
// 4: Threshold to Zero Inverted
// */
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
//
//vector<Mat> channels0;
//vector<Mat> channels1;
//vector<Mat> channels2;
//vector<Mat>	channels3;
//
//Mat image0,image1,imageT,imageD;
//
//Size size(CLO,ROW);
//
//void Threshold_Demo( int, void* );
//void formImage(uint8_t* finaldata,int length);
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
//	//cap.set(CV_CAP_PROP_CONVERT_RGB, false);
//	cap.open(0);
//
//	while(loop == true)
//	{
//
//		try
//		{
//			cap>>image0;
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
//			//imwrite("/home/mrq/Desktop/image0.jpg",image0);
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
//		char key = waitKey(30) & 0xFF;
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
//
//	Mat des;
//	threshold(imageT, des, threshold_value, max_BINARY_value,threshold_type );
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
//	uint8_t* pixelPtr = (uint8_t*)des.data;
//	uint8_t* final_data;
//	int cn = des.channels();
//	int count=0;
//	Scalar_<uint8_t> bgrPixel;
//
//	int nz=0;
//	int index=0;
//
//	uint8_t zero_count=0;
//
//	for(int i = 0; i < des.rows; i++)
//	{
//		for(int j = 0; j < des.cols; j++)
//		{
//			bgrPixel.val[0] = pixelPtr[i*des.cols*cn + j*cn + 0]; // B
//			bgrPixel.val[1] = pixelPtr[i*des.cols*cn + j*cn + 1]; // G
//			bgrPixel.val[2] = pixelPtr[i*des.cols*cn + j*cn + 2]; // R
//
//			if(bgrPixel.val[0]==0&&bgrPixel.val[1]==0&&bgrPixel.val[2]==0)
//			{
//				count++;
//				zero_count++;
//				//最后一个点
//				if(count==size.width*size.height)
//				{
//					//
//					uint8_t o=zero_count/(mod*mod);
//					//
//					uint8_t p=(zero_count%(mod*mod))/mod;
//					//
//					uint8_t q=(zero_count%(mod*mod))%mod;
//
//					//if(o!=0||p!=0||q!=0)
//					{
//						//最小为1 最大为 16
//						cout<<"the last point"<<endl;
//						final_data[index*3+0]=o+1;
//						final_data[index*3+1]=p;
//						final_data[index*3+2]=q;
//						index++;
//						final_data[index*3+0]=1;
//						final_data[index*3+1]=0;
//						final_data[index*3+2]=0;
//					}
//				}
//			}
//			else
//			{
//				nz++;
//				if(zero_count>0)
//				{
//					//
//					uint8_t o=zero_count/(mod*mod);
//					//
//					uint8_t p=(zero_count%(mod*mod))/mod;
//					//
//					uint8_t q=(zero_count%(mod*mod))%mod;
//
//					//cout<<"o p q"<<o<<p<<q<<endl;
//					//cout<<bgrPixel.val[0]<<endl;
//					if(o!=0||p!=0||q!=0)
//					{
//						//最小为1 最大为 16
//						final_data[index*3+0]=o+1;
//						final_data[index*3+1]=p;
//						final_data[index*3+2]=q;
//						index++;
//					}
//				}
//
//
//				final_data[index*3+0]=bgrPixel.val[0];
//				final_data[index*3+1]=bgrPixel.val[1];
//				final_data[index*3+2]=bgrPixel.val[2];
//
//				//置零
//				zero_count=0;
//				index++;
//				count++;
//			}
//		}
//	}
//	cout<<"	======count:========"<<count<<endl;
//	cout<<"	======index:========"<<index<<endl;
//	cout<<"	======n   z:========"<<nz<<endl;
//	formImage(final_data,index);
//}
//
//std::ostream & operator<<(std::ostream & os, uint8_t val)
//{
//	return os << static_cast<int>(val);
//}
//
//void formImage(uint8_t* finaldata,int length)
//{
//	//cout<<"=======formImage====="<<endl;
//	int count=0;
//	namedWindow("recover");
//	Mat tmp=Mat::zeros(size.height,size.width,CV_8UC3);
//
//	Scalar_<uint8_t> bgrPixel;
//
//	uint8_t* pixelPtr = (uint8_t*)tmp.data;
//	long index=0;
//
//	try
//	{
//		for(int o=0;o<length;o++)
//		{
//
//
//			uint8_t f=finaldata[o*3+0];
//			uint8_t s=finaldata[o*3+1];
//			uint8_t t=finaldata[o*3+2];
//
//			//结束标志
//
//			if((f==1&&s==0&&t==0)||o>=size.height*size.width||index>=size.height*size.width)
//			{
//				cout<<"=======break======"<<endl;
//				break;
//			}
//			else
//			{
//				//cout<<"else"<<endl;
//				if(f>0&&f<16)
//				{
//
//					long l=(f-1)*(mod*mod)+s*mod+t;
//					//cout<<"l:"<<l<<endl;
//					for(long x=0;x<l;x++,index++)
//					{
//						count++;
//						pixelPtr[index*3+0]=0;
//						pixelPtr[index*3+1]=0;
//						pixelPtr[index*3+2]=0;
//						//index++;
//						//perror("Error");
//					}
//					//perror("Error");
//
//				}
//				else
//				{
//					//continue;
//
//					pixelPtr[index*3+0]=finaldata[o*3+0];
//					pixelPtr[index*3+1]=finaldata[o*3+1];
//					pixelPtr[index*3+2]=finaldata[o*3+2];
//					count++;
//					index++;
//				}
//
//			}
//		}
//	}
//	catch (Exception& e)
//	{
//		const char* err_msg = e.what();
//		std::cout << "exception caught: imshow:\n" << err_msg << std::endl;
//	}
//	cout<<"count:"<<count<<endl;
//	imshow("recover",tmp);
//	//imwrite("/home/mrq/Desktop/xor.jpg",tmp);
//	cout<<"form image . . ."<<endl;
//
//}

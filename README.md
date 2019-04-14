# Yet another image processing framework for teaching.


## how to run?
``` shell
make run
```



## demo
``` c++
int main(int argc, char *argv[]){
	
	framework::ImageLoader *jpgLoader = new framework::JPGImageLoader();
	framework::PixelMatrix *pixels = jpgLoader->loadImage("/Users/neroyang/project/sbwIP/img/nasa.jpg");
	framework::PixelMatrix *pixels1 = jpgLoader->loadImage("/Users/neroyang/project/sbwIP/img/nasa.jpg");

	framework::Fliter *binaryValFliter = new framework::BinaryValFliter(pixels);
	framework::Window *binaryWindow = new framework::Window(pixels->getWidth(), pixels->getHeight(), "二值化");
	binaryWindow->setPixelMatrix(binaryValFliter->doFliter());
	
	framework::Fliter *grayFliter = new framework::GrayFliter(pixels1);
	framework::Window *grayWindow = new framework::Window(pixels1->getWidth(), pixels1->getHeight(), "灰度图");
	grayWindow->setPixelMatrix(grayFliter->doFliter());

	framework::WindowManager *manager = framework::WindowManager::GetWindowManagerInstance();
	manager->createWindow(binaryWindow);
	manager->createWindow(grayWindow);
	manager->renderWindow();

	return 1;
}
```
## image
![image](docs/img/img.png)
## gray
![gray](docs/img/gray.png)
## Binary Value
![Binary](docs/img/2.png)
## DeNoise
![DeNoise](docs/img/noise.png)

# cocos2dxStudy
官网下载cocos2dx 压缩包，解压后放到一个文件夹用来创建工程用。
进入解压后的文件夹tools->cocos2d-console->bin目录下。
用python运行如下：
python cocos.py new HelloWorldDemo -p com.coco2dx.org -l cpp -d ~/Desktop
参数说明：

HelloWorldDemo为项目名称
-p后面接包名
-l后面接开发语言类型，有cpp, lua, js三种类型
-d后面接项目存放的目录

cocos2dx基本控件使用：
1、先创建Director。
2、创建scene，然后第一次用Direct执行runwithscene来执行创建的scene。
3、创建scene的时候要在init函数中先创建Layer，然后添加到scene中：scene->addChild(layer);
CREATE_FUNC可以快速创建

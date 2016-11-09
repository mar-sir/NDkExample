#NDK开发
##NDK----examplefirst(HelloWord)
####开发配置
* NDK配置,如图:![](https://github.com/mar-sir/NDkExample/blob/master/NDKExample/imgs/step1.png?raw=true)
* 成功标志,如图：![](https://github.com/mar-sir/NDkExample/blob/master/NDKExample/imgs/step2.png?raw=true)
* 在gradle.properties文件中添加代码:android.useDeprecatedNdk=true

####step1
新建一个类JniUtils，里面代码如下:
    
    public class JniUtils {
        //访问C++代码
        public static native String sayHello();
    }
MainActivity里面代码如下:
    
    public class MainActivity extends AppCompatActivity {
        TextView textView;
    
        @Override
        protected void onCreate(Bundle savedInstanceState) {
            super.onCreate(savedInstanceState);
            setContentView(R.layout.activity_main);
            textView = (TextView) findViewById(R.id.test);
            textView.setText(JniUtils.sayHello());
        }
    
    }
写完之后点击rebuild，然后你会在build的文件夹下发现多了一个类，然后打开as的终端，进入debug目录，输入 javah -jni com.example.examplefirst.JniUtils
(后面的路径根据自己的来写)回车运行,你会发现又多了一个.h的文件,如图.
![](https://github.com/mar-sir/NDkExample/blob/master/NDKExample/imgs/step3.png?raw=true)
####step2
新建jni文件，如图:
![](https://github.com/mar-sir/NDkExample/blob/master/NDKExample/imgs/step4.png?raw=true)
在jni文件下把step1生成的.h文件剪切过来，如图:
![](https://github.com/mar-sir/NDkExample/blob/master/NDKExample/imgs/step5.png?raw=true)
并新建一个.cpp文件,我的文件名叫SayHello，里面代码如下:
    
    //把copy的.h文件引进来
    #include "com_example_examplefirst_JniUtils.h"
    //在实现自己写的C++代码
    //jstring 对应String 类型
    //这里的代码可以从.h文件里面拷过来，只不过加了参数和return 
    JNIEXPORT jstring JNICALL Java_com_example_examplefirst_JniUtils_sayHello
      (JNIEnv * env, jclass o){
      return env->NewStringUTF("sayHello");
      };
####step3
在build.gradle的defaultConfig下面添加如下代码：
    
        ndk {
                moduleName "jniModule"
                abiFilters "armeabi", "armeabi-v7a", "x86"//支持的平台
            }
在JniUtils类里面加入代码:
      
      static {
            System.loadLibrary("jniModule");
        }
如图:![](https://github.com/mar-sir/NDkExample/blob/master/NDKExample/imgs/step6.png?raw=true)

####step4
![](https://github.com/mar-sir/NDkExample/blob/master/NDKExample/imgs/step8.png?raw=true)
效果:
![](https://github.com/mar-sir/NDkExample/blob/master/NDKExample/imgs/step7.png?raw=true)

[这里真的有代码](https://github.com/mar-sir/NDkExample.git)
 
 
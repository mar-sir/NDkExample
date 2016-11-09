//
// Created by huangcl on 2016/11/9.
//

//把copy的.h文件引进来
#include "com_example_examplefirst_JniUtils.h"
//在实现自己写的C++代码
//jstring 对应String 类型
JNIEXPORT jstring JNICALL Java_com_example_examplefirst_JniUtils_sayHello
  (JNIEnv * env, jclass o){
  return env->NewStringUTF("sayHello");
  };
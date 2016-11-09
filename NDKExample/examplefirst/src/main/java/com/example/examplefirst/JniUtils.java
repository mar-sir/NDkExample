package com.example.examplefirst;

/**
 * Created by huangcl on 2016/11/9.
 */

public class JniUtils {
    static {
        System.loadLibrary("jniModule");
    }

    //访问C++代码
    public static native String sayHello();
}

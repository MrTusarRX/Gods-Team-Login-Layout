#include "obfuscate.h"
#include<jni.h>
#include <sstream>


void AddButton(JNIEnv *env, jobject ctx, const char *name, int id){
    jclass BTN = env->GetObjectClass(ctx);
    jmethodID inter = env->GetMethodID(BTN,OBFUSCATE("addButton"),OBFUSCATE("(Ljava/lang/String;Luk/lgl/modmenu/FloatingModMenuService$InterfaceBtn;)V"));

    jmethodID BTNS = env->GetMethodID(BTN,OBFUSCATE("BTN"),OBFUSCATE("(I)Luk/lgl/modmenu/FloatingModMenuService$InterfaceBtn;"));

    env->CallVoidMethod(ctx, inter, env->NewStringUTF(name), env->CallObjectMethod(ctx, BTNS, id));
}
void stopMod(JNIEnv *env, jobject ctx) {
    jclass native_context = env->GetObjectClass(ctx);
    jclass intentClass = env->FindClass(OBFUSCATE("android/content/Intent"));
    jclass actionString = env->FindClass(OBFUSCATE("uk/lgl/modmenu/FloatingModMenuService"));
    jmethodID newIntent = env->GetMethodID(intentClass, OBFUSCATE("<init>"), OBFUSCATE("(Landroid/content/Context;Ljava/lang/Class;)V"));
    jobject intent = env->NewObject(intentClass, newIntent, ctx, actionString);
    jmethodID stopServiceMethodId = env->GetMethodID(native_context, OBFUSCATE("stopService"), OBFUSCATE("(Landroid/content/Intent;)Z"));
    env->CallBooleanMethod(ctx, stopServiceMethodId, intent);
}
void AddCheckBox(JNIEnv *env, jobject ctx, const char *name, int id){
    jclass Main = env->GetObjectClass(ctx);
    jmethodID swich = env->GetMethodID(Main,OBFUSCATE("addCheckBox"),OBFUSCATE("(Ljava/lang/String;Luk/lgl/modmenu/FloatingModMenuService$InterfaceBool;)V"));

    jmethodID BOOL = env->GetMethodID(Main,OBFUSCATE("BOOL"),OBFUSCATE("(I)Luk/lgl/modmenu/FloatingModMenuService$InterfaceBool;"));

    env->CallVoidMethod(ctx, swich, env->NewStringUTF(name), env->CallObjectMethod(ctx, BOOL, id));
}
void AddSwich(JNIEnv *env, jobject ctx, const char *name, int id){
    jclass Main = env->GetObjectClass(ctx);
    jmethodID swich = env->GetMethodID(Main,OBFUSCATE("addSwitch"),OBFUSCATE("(Ljava/lang/String;Luk/lgl/modmenu/FloatingModMenuService$InterfaceBool;)V"));

    jmethodID BOOL = env->GetMethodID(Main,OBFUSCATE("BOOL"),OBFUSCATE("(I)Luk/lgl/modmenu/FloatingModMenuService$InterfaceBool;"));

    env->CallVoidMethod(ctx, swich, env->NewStringUTF(name), env->CallObjectMethod(ctx, BOOL, id));
}

void AddSkeedBar(JNIEnv *env, jobject ctx, const char *name, int min, int max, int id){
    jclass Main = env->GetObjectClass(ctx);
    jmethodID skeed = env->GetMethodID(Main,OBFUSCATE("addSeekBar"),OBFUSCATE("(Ljava/lang/String;IILuk/lgl/modmenu/FloatingModMenuService$InterfaceInt;)V"));

    jmethodID INT = env->GetMethodID(Main,OBFUSCATE("INT"),OBFUSCATE("(I)Luk/lgl/modmenu/FloatingModMenuService$InterfaceInt;"));

    env->CallVoidMethod(ctx, skeed, env->NewStringUTF(name),min,max, env->CallObjectMethod(ctx, INT, id));
}

void AddCategory(JNIEnv *env, jobject ctx, const char *name){
    jclass Main = env->GetObjectClass(ctx);
    jmethodID AddCategory = env->GetMethodID(Main,OBFUSCATE("addCategory"),OBFUSCATE("(Ljava/lang/String;)V"));
    env->CallVoidMethod(ctx, AddCategory, env->NewStringUTF(name));
}

void setText(JNIEnv *env, jobject obj, const char* text){
    jclass textView = (*env).FindClass(OBFUSCATE("android/widget/TextView"));
    jmethodID setText = (*env).GetMethodID(textView, OBFUSCATE("setText"), OBFUSCATE("(Ljava/lang/CharSequence;)V"));

    jstring jstr = (*env).NewStringUTF(text);
    (*env).CallVoidMethod(obj, setText,  jstr);
}

void Funçoes(JNIEnv *env, jobject ctx, const char *pkg, const char *libname, const char *offset, const char *hex){
    jclass Main = env->GetObjectClass(ctx);
    jmethodID AddFunçoes = env->GetMethodID(Main,OBFUSCATE("Funçoes"),OBFUSCATE("(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"));
    env->CallVoidMethod(ctx, AddFunçoes, env->NewStringUTF(pkg), env->NewStringUTF(libname), env->NewStringUTF(offset), env->NewStringUTF(hex));
}

void Funçoes(JNIEnv *env, jobject ctx, const char *pkg, const char *libname, int offset, const char *hex){
    jclass Main = env->GetObjectClass(ctx);
    jmethodID AddFunçoes = env->GetMethodID(Main,OBFUSCATE("Funçoes"),OBFUSCATE("(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;)V"));
    env->CallVoidMethod(ctx, AddFunçoes, env->NewStringUTF(pkg), env->NewStringUTF(libname), offset, env->NewStringUTF(hex));
}

void setDialog(jobject ctx, JNIEnv *env, const char *title, const char *msg){
    jclass Alert = env->FindClass(OBFUSCATE("android/app/AlertDialog$Builder"));
    jmethodID AlertCons = env->GetMethodID(Alert, OBFUSCATE("<init>"), OBFUSCATE("(Landroid/content/Context;)V"));

    jobject MainAlert = env->NewObject(Alert, AlertCons, ctx);

    jmethodID setTitle = env->GetMethodID(Alert, OBFUSCATE("setTitle"), OBFUSCATE("(Ljava/lang/CharSequence;)Landroid/app/AlertDialog$Builder;"));
    env->CallObjectMethod(MainAlert, setTitle, env->NewStringUTF(title));

    jmethodID setMsg = env->GetMethodID(Alert, OBFUSCATE("setMessage"), OBFUSCATE("(Ljava/lang/CharSequence;)Landroid/app/AlertDialog$Builder;"));
    env->CallObjectMethod(MainAlert, setMsg, env->NewStringUTF(msg));

    jmethodID setCa = env->GetMethodID(Alert, OBFUSCATE("setCancelable"), OBFUSCATE("(Z)Landroid/app/AlertDialog$Builder;"));
    env->CallObjectMethod(MainAlert, setCa, false);

    jmethodID setPB = env->GetMethodID(Alert, OBFUSCATE("setPositiveButton"), OBFUSCATE("(Ljava/lang/CharSequence;Landroid/content/DialogInterface$OnClickListener;)Landroid/app/AlertDialog$Builder;"));
    env->CallObjectMethod(MainAlert, setPB, env->NewStringUTF("Ok"), static_cast<jobject>(NULL));

    jmethodID create = env->GetMethodID(Alert, OBFUSCATE("create"), OBFUSCATE("()Landroid/app/AlertDialog;"));
    jobject creaetob = env->CallObjectMethod(MainAlert, create);

    jclass AlertN = env->FindClass(OBFUSCATE("android/app/AlertDialog"));

    jmethodID show = env->GetMethodID(AlertN, OBFUSCATE("show"), OBFUSCATE("()V"));
    env->CallVoidMethod(creaetob, show);
}

void Toast(JNIEnv *env, jobject thiz, const char *text, int length) {
    jstring jstr = env->NewStringUTF(text);
    jclass toast = env->FindClass(OBFUSCATE("android/widget/Toast"));
    jmethodID methodMakeText =env->GetStaticMethodID(toast,OBFUSCATE("makeText"),OBFUSCATE("(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;"));
    jobject toastobj = env->CallStaticObjectMethod(toast, methodMakeText,thiz, jstr, length);
    jmethodID methodShow = env->GetMethodID(toast, OBFUSCATE("show"), OBFUSCATE("()V"));
    env->CallVoidMethod(toastobj, methodShow);
}

void startActivityPermisson(JNIEnv *env, jobject ctx){
    jclass native_context = env->GetObjectClass(ctx);
    jmethodID startActivity = env->GetMethodID(native_context, OBFUSCATE("startActivity"),OBFUSCATE("(Landroid/content/Intent;)V"));

    jmethodID pack = env->GetMethodID(native_context, OBFUSCATE("getPackageName"),OBFUSCATE("()Ljava/lang/String;"));
    jstring packetname = static_cast<jstring>(env->CallObjectMethod(ctx, pack));

    const char *pkg = env->GetStringUTFChars(packetname, 0);

    std::stringstream pkgg;
    pkgg << OBFUSCATE("package:");
    pkgg << pkg;
    std::string pakg = pkgg.str();

    jclass Uri = env->FindClass(OBFUSCATE("android/net/Uri"));
    jmethodID Parce = env->GetStaticMethodID(Uri, OBFUSCATE("parse"), OBFUSCATE("(Ljava/lang/String;)Landroid/net/Uri;"));
    jobject UriMethod = env->CallStaticObjectMethod(Uri, Parce, env->NewStringUTF(pakg.c_str()));

    jclass intentclass = env->FindClass(OBFUSCATE("android/content/Intent"));
    jmethodID newIntent = env->GetMethodID(intentclass, OBFUSCATE("<init>"), OBFUSCATE("(Ljava/lang/String;Landroid/net/Uri;)V"));
    jobject intent = env->NewObject(intentclass,newIntent,env->NewStringUTF(OBFUSCATE("android.settings.action.MANAGE_OVERLAY_PERMISSION")), UriMethod);

    env->CallVoidMethod(ctx, startActivity, intent);
}

void startMod(JNIEnv *env, jobject ctx){
    jclass native_context = env->GetObjectClass(ctx);
    jclass intentClass = env->FindClass(OBFUSCATE("android/content/Intent"));
    jclass actionString = env->FindClass(OBFUSCATE("uk/lgl/modmenu/FloatingModMenuService"));
    jmethodID newIntent = env->GetMethodID(intentClass, OBFUSCATE("<init>"), OBFUSCATE("(Landroid/content/Context;Ljava/lang/Class;)V"));
    jobject intent = env->NewObject(intentClass,newIntent,ctx,actionString);
    jmethodID startActivityMethodId = env->GetMethodID(native_context, OBFUSCATE("startService"), OBFUSCATE("(Landroid/content/Intent;)Landroid/content/ComponentName;"));
    env->CallObjectMethod(ctx, startActivityMethodId, intent);
}

void CheckFloatingPermison(JNIEnv *env, jobject ctx){
    jclass Settigs = env->FindClass(OBFUSCATE("android/provider/Settings"));
    jmethodID canDraw =env->GetStaticMethodID(Settigs,OBFUSCATE("canDrawOverlays"),OBFUSCATE("(Landroid/content/Context;)Z"));
    if (!env->CallStaticBooleanMethod(Settigs, canDraw, ctx)){
        Toast(env,ctx,OBFUSCATE("Overlay permission is required in order to show mod menu. Restart the game after you allow permission"),1);
        Toast(env,ctx,OBFUSCATE("Overlay permission is required in order to show mod menu. Restart the game after you allow permission"),1);
        startActivityPermisson(env, ctx);
        return;
    }

    startMod(env, ctx);
}

uintptr_t string2Offset(const char *c) {
    int base = 16;
    static_assert(sizeof(uintptr_t) == sizeof(unsigned long) || sizeof(uintptr_t) == sizeof(unsigned long long), "Please add string to handle conversion for this architecture.");

    if (sizeof(uintptr_t) == sizeof(unsigned long)) {
        return strtoul(c, nullptr, base);
    }

    return strtoull(c, nullptr, base);
}

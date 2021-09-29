#include <windows.h>

int main(int argc, char **argv) 
{
    HMODULE dll = LoadLibrary("shared_lib.dll");

    // Optional, call into the loaded DLL
    // Can use this to show that the debugger is able to breakpint inside the shared lib code.
    /*
    typedef void (*GreetFn)(void);
    GreetFn greet = (GreetFn) GetProcAddress(dll, "greet");
    greet();
    greet = nullptr;
    */

    // Breakpoint on the FreeLibrary call and observe using Process Explorer that LLDB *and* app.exe have a handle to shared_lib.dll
    // Process Explorer available from https://docs.microsoft.com/en-us/sysinternals/downloads/process-explorer
    FreeLibrary(dll);
    
    // app.exe no longer has a handle to shared_lib.dll
    // By this point it is no longer locked by Visual Studio 2019 debugger, if using that.
    // However, shared_lib.dll remains locked by LLDB, even though there is no need for it anymore
    // This can be verified using Process Explorer, or just by trying to delete shared_lib.dll
    system("pause"); // Pause - if running without a debugger can see at this point that shared_lib.dll is no longer locked.
    return 0;
}
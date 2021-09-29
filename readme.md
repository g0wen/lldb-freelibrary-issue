Run build-llvm.bat or follow the steps it outlines to build the shared_lib.dll and app.exe.
CMake can be used to generate a Visual Studio project for behaviour comparison.

Debug the application using LLDB (Confirmed on LLDB 11 and 12.0.1)

Repro:
 * Build a shared library DLL
 * Create an executable that does not link that DLL
 * Load a DLL in code using LoadLibrary
 * Unload the same DLL using FreeLibrary on the HMODULE obtained from the first step
 * Observe that LLDB does not release its lock on the DLL file, until LLDB is closed.

LLDB Issue: https://bugs.llvm.org/show_bug.cgi?id=52017
# WinMain function

## Description

The user-provided entry point for a graphical Windows-based application.

**WinMain** is the conventional name used for the application entry point. For more information, see Remarks.

## Parameters

### `hInstance` [in]

Type: **HINSTANCE**

A handle to the current instance of the application.

### `hPrevInstance` [in, optional]

Type: **HINSTANCE**

A handle to the previous instance of the application. This parameter is always **NULL**. If you need to detect whether another instance already exists, create a uniquely named mutex using the [CreateMutex](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createmutexa) function. **CreateMutex** will succeed even if the mutex already exists, but the function will return **ERROR_ALREADY_EXISTS**. This indicates that another instance of your application exists, because it created the mutex first. However, a malicious user can create this mutex before you do and prevent your application from starting. To prevent this situation, create a randomly named mutex and store the name so that it can only be obtained by an authorized user. Alternatively, you can use a file for this purpose. To limit your application to one instance per user, create a locked file in the user's profile directory.

### `lpCmdLine` [in]

Type: **LPSTR**

The command line for the application, excluding the program name. To retrieve the entire command line, use the [GetCommandLine](https://learn.microsoft.com/windows/desktop/api/processenv/nf-processenv-getcommandlinea) function.

### `nShowCmd` [in]

Type: **int**

Controls how the window is to be shown. This parameter can be any of the values that can be specified in the *nCmdShow* parameter for the [ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow) function.

## Return value

Type: **int**

If the function succeeds, terminating when it receives a [WM_QUIT](https://learn.microsoft.com/windows/desktop/winmsg/wm-quit) message, it should return the exit value contained in that message's *wParam* parameter. If the function terminates before entering the message loop, it should return zero.

## Remarks

The name **WinMain** is used by convention by many programming frameworks. Depending on the programming framework, the call to the **WinMain** function can be preceded and followed by additional activities specific to that framework.

Your **WinMain** should initialize the application, display its main window, and enter a message retrieval-and-dispatch loop that is the top-level control structure for the remainder of the application's execution. Terminate the message loop when it receives a [WM_QUIT](https://learn.microsoft.com/windows/desktop/winmsg/wm-quit) message. At that point, your **WinMain** should exit the application, returning the value passed in the **WM_QUIT** message's *wParam* parameter. If **WM_QUIT** was received as a result of calling [PostQuitMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postquitmessage), the value of *wParam* is the value of the **PostQuitMessage** function's *nExitCode* parameter. For more information, see [Creating a Message Loop](https://learn.microsoft.com/windows/desktop/winmsg/using-messages-and-message-queues).

ANSI applications can use the *lpCmdLine* parameter of the **WinMain** function to access the command-line string, excluding the program name. Note that *lpCmdLine* uses the **LPSTR** data type instead of the **LPTSTR** data type. This means that **WinMain** cannot be used by Unicode programs. The [GetCommandLineW](https://learn.microsoft.com/windows/desktop/api/processenv/nf-processenv-getcommandlinew) function can be used to obtain the command line as a Unicode string. Some programming frameworks might provide an alternative entry point that provides a Unicode command line. For example, the Microsoft Visual Studio C++ complier uses the name **wWinMain** for the Unicode entry point.

## Example

The following code example demonstrates the use of **WinMain**

```cpp
#include <windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    return MessageBox(NULL, "hello, world", "caption", 0);
}
```

## See also

**Conceptual**

[CreateMutex](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createmutexa)

[DispatchMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dispatchmessage)

[GetCommandLine](https://learn.microsoft.com/windows/desktop/api/processenv/nf-processenv-getcommandlinea)

[GetMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmessage)

**Other Resources**

[PostQuitMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postquitmessage)

**Reference**

[TranslateMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-translatemessage)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)
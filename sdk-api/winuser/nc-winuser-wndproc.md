## Description

A callback function, which you define in your application, that processes messages sent to a window. The **WNDPROC** type defines a pointer to this callback function. The _WndProc_ name is a placeholder for the name of the function that you define in your application.

## Parameters

### `unnamedParam1`

Type: **[HWND](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A handle to the window. This parameter is typically named _hWnd_.

### `unnamedParam2`

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The message. This parameter is typically named _uMsg_.

For lists of the system-provided messages, see [System-defined messages](https://learn.microsoft.com/windows/win32/winmsg/about-messages-and-message-queues#system-defined-messages).

### `unnamedParam3`

Type: **[WPARAM](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Additional message information. This parameter is typically named _wParam_.

The contents of the _wParam_ parameter depend on the value of the _uMsg_ parameter.

### `unnamedParam4`

Type: **[LPARAM](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Additional message information. This parameter is typically named _lParam_.

The contents of the _lParam_ parameter depend on the value of the _uMsg_ parameter.

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The return value is the result of the message processing, and depends on the message sent.

## Remarks

> [!NOTE]
> The parameters are defined in the header with no names: `typedef LRESULT (CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);`. Therefore, the syntax block lists them as `unnamedParam1` - `unnamedParam4`. You can name these parameters anything in your app. However, they are usually named as shown in the parameter descriptions. Visual Studio project templates will use these names (or something similar, depending on the template).

If your application runs on a 32-bit version of Windows operating system, uncaught exceptions from the callback will be passed onto higher-level exception handlers of your application when available. The system then calls the unhandled exception filter to handle the exception prior to terminating the process. If the PCA is enabled, it will offer to fix the problem the next time you run the application.

However, if your application runs on a 64-bit version of Windows operating system or WOW64, you should be aware that a 64-bit operating system handles uncaught exceptions differently based on its 64-bit processor architecture, exception architecture, and calling convention. The following table summarizes all possible ways that a 64-bit Windows operating system or WOW64 handles uncaught exceptions.

|Behavior type|How the system handles uncaught exceptions|
|-|-|
|1|The system suppresses any uncaught exceptions.|
|2|The system first terminates the process, and then the Program Compatibility Assistant (PCA) offers to fix it the next time you run the application. You can disable the PCA mitigation by adding a Compatibility section to the [application manifest](https://learn.microsoft.com/windows/win32/win7appqual/compatibility---application-manifest).|
|3|The system calls the exception filters but suppresses any uncaught exceptions when it leaves the callback scope, without invoking the associated handlers.|

The following table shows how a 64-bit version of the Windows operating system, and WOW64, handles uncaught exceptions. Notice that behavior type 2 applies only to the 64-bit version of the Windows 7 operating system and later.

|Operating system|WOW64|64-bit Windows|
|-|-|-|
|Windows XP|3|1|
|Windows Server 2003|3|1|
|Windows Vista|3|1|
|Windows Vista SP1|1|1|
|Windows 7 and later|1|2|

> [!NOTE]
> On Windows 7 with SP1 (32-bit, 64-bit, or WOW64), the system calls the unhandled exception filter to handle the exception prior to terminating the process. If the Program Compatibility Assistant (PCA) is enabled, then it will offer to fix the problem the next time you run the application.

If you need to handle exceptions in your application, you can use structured exception handling to do so. For more information on how to use structured exception handling, see [Structured exception handling](https://learn.microsoft.com/windows/win32/debug/structured-exception-handling).

## See also

* [CallWindowProcW](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callwindowprocw)
* [DefWindowProcW](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-defwindowprocw)
* [RegisterClassExW](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-registerclassexw)
* [Window procedures](https://learn.microsoft.com/windows/win32/winmsg/window-procedures)
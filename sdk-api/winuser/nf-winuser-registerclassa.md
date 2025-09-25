# RegisterClassA function

## Description

Registers a window class for subsequent use in calls to the [CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa) or [CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa) function.

**Note** The **RegisterClass** function has been superseded by the [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa) function. You can still use **RegisterClass**, however, if you do not need to set the class small icon.

## Parameters

### `lpWndClass` [in]

Type: **const WNDCLASS***

A pointer to a [WNDCLASS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassa) structure. You must fill the structure with the appropriate class attributes before passing it to the function.

## Return value

Type: **ATOM**

If the function succeeds, the return value is a class atom that uniquely identifies the class being registered. This atom can only be used by the [CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa), [CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa), [GetClassInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclassinfoa), [GetClassInfoEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclassinfoexa), [FindWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-findwindowa), [FindWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-findwindowexa), and [UnregisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unregisterclassa) functions and the **IActiveIMMap::FilterClientWindows** method.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If you register the window class by using
**RegisterClassA**, the application tells the system that the windows of the created class expect messages with text or character parameters to use the ANSI character set; if you register it by using
**RegisterClassW**, the application requests that the system pass text parameters of messages as Unicode. The [IsWindowUnicode](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-iswindowunicode) function enables applications to query the nature of each window. For more information on ANSI and Unicode functions, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/desktop/Intl/conventions-for-function-prototypes).

All window classes that an application registers are unregistered when it terminates.

No window classes registered by a DLL are unregistered when the DLL is unloaded. A DLL must explicitly unregister its classes when it is unloaded.

#### Examples

For an example, see [Associating a Window Procedure with a Window Class](https://learn.microsoft.com/windows/desktop/winmsg/using-window-procedures).

> [!NOTE]
> The winuser.h header defines RegisterClass as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa)

[CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa)

[FindWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-findwindowa)

[FindWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-findwindowexa)

[GetClassInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclassinfoa)

[GetClassInfoEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclassinfoexa)

[GetClassName](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclassname)

**Reference**

[RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa)

[UnregisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unregisterclassa)

[WNDCLASS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassa)

[Window Classes](https://learn.microsoft.com/windows/desktop/winmsg/window-classes)

[WindowProc](https://learn.microsoft.com/windows/win32/api/winuser/nc-winuser-wndproc)
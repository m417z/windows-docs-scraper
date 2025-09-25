# FindWindowExA function

## Description

Retrieves a handle to a window whose class name and window name match the specified strings. The function searches child windows, beginning with the one following the specified child window. This function does not perform a case-sensitive search.

## Parameters

### `hWndParent` [in, optional]

Type: **HWND**

A handle to the parent window whose child windows are to be searched.

If *hwndParent* is **NULL**, the function uses the desktop window as the parent window. The function searches among windows that are child windows of the desktop.

If *hwndParent* is **HWND_MESSAGE**, the function searches all [message-only windows](https://learn.microsoft.com/windows/desktop/winmsg/window-features).

### `hWndChildAfter` [in, optional]

Type: **HWND**

A handle to a child window. The search begins with the next child window in the Z order. The child window must be a direct child window of *hwndParent*, not just a descendant window.

If *hwndChildAfter* is **NULL**, the search begins with the first child window of *hwndParent*.

Note that if both *hwndParent* and *hwndChildAfter* are **NULL**, the function searches all top-level and message-only windows.

### `lpszClass` [in, optional]

Type: **LPCSTR**

The class name or a class atom created by a previous call to the [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa) or [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa) function. The atom must be placed in the low-order word of *lpszClass*; the high-order word must be zero.

 If *lpszClass* is a string, it specifies the window class name. The class name can be any name registered with [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa) or [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa), or any of the predefined control-class names, or it can be `MAKEINTATOM(0x8000)`. In this latter case, 0x8000 is the atom for a menu class. For more information, see the Remarks section of this topic.

### `lpszWindow` [in, optional]

Type: **LPCSTR**

The window name (the window's title). If this parameter is **NULL**, all window names match.

## Return value

Type: **HWND**

If the function succeeds, the return value is a handle to the window that has the specified class and window names.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The FindWindowEx function searches only direct child windows. It does not search other descendants.

If the *lpszWindow* parameter is not **NULL**, **FindWindowEx** calls the [GetWindowText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowtexta) function to retrieve the window name for comparison. For a description of a potential problem that can arise, see the Remarks section of **GetWindowText**.

An application can call this function in the following way.

`FindWindowEx( NULL, NULL, MAKEINTATOM(0x8000), NULL );`

Note that 0x8000 is the atom for a menu class. When an application calls this function, the function checks whether a context menu is being displayed that the application created.

> [!NOTE]
> The winuser.h header defines FindWindowEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[EnumWindows](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumwindows)

[FindWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-findwindowa)

[GetClassName](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclassname)

[GetWindowText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowtexta)

**Reference**

[RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa)

[RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)
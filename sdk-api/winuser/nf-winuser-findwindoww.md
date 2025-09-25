# FindWindowW function

## Description

Retrieves a handle to the top-level window whose class name and window name match the specified strings. This function does not search child windows. This function does not perform a case-sensitive search.

To search child windows, beginning with a specified child window, use the [FindWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-findwindowexa) function.

## Parameters

### `lpClassName` [in, optional]

Type: **LPCTSTR**

The class name or a class atom created by a previous call to the [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa) or [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa) function. The atom must be in the low-order word of *lpClassName*; the high-order word must be zero.

If *lpClassName* points to a string, it specifies the window class name. The class name can be any name registered with [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa) or [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa), or any of the predefined control-class names.

If *lpClassName* is **NULL**, it finds any window whose title matches the *lpWindowName* parameter.

### `lpWindowName` [in, optional]

Type: **LPCTSTR**

The window name (the window's title). If this parameter is **NULL**, all window names match.

## Return value

Type: **HWND**

If the function succeeds, the return value is a handle to the window that has the specified class name and window name.

If the function fails, the return value is **NULL**. This function does not modify the last error value.

## Remarks

If the *lpWindowName* parameter is not **NULL**, **FindWindow** calls the [GetWindowText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowtexta) function to retrieve the window name for comparison. For a description of a potential problem that can arise, see the Remarks for **GetWindowText**.

#### Examples

For an example, see [Retrieving the Number of Mouse Wheel Scroll Lines](https://learn.microsoft.com/windows/desktop/inputdev/using-mouse-input).

> [!NOTE]
> The winuser.h header defines FindWindow as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[EnumWindows](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumwindows)

[FindWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-findwindowexa)

[GetClassName](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclassname)

[GetWindowText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowtexta)

**Reference**

[RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa)

[RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)
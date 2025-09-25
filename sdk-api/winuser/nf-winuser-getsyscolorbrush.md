# GetSysColorBrush function

## Description

The **GetSysColorBrush** function retrieves a handle identifying a logical brush that corresponds to the specified color index.

## Parameters

### `nIndex` [in]

A color index. This value corresponds to the color used to paint one of the window elements. See [GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor) for system color index values.

## Return value

The return value identifies a logical brush if the *nIndex* parameter is supported by the current platform. Otherwise, it returns **NULL**.

## Remarks

A brush is a bitmap that the system uses to paint the interiors of filled shapes. An application can retrieve the current system colors by calling the [GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor) function. An application can set the current system colors by calling the [SetSysColors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setsyscolors) function.

An application must not register a window class for a window using a system brush. To register a window class with a system color, see the documentation of the **hbrBackground** member of the [WNDCLASS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassa) or [WNDCLASSEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassexa) structures.

System color brushes track changes in system colors. In other words, when the user changes a system color, the associated system color brush automatically changes to the new color.

To paint with a system color brush, an application should use **GetSysColorBrush** (nIndex) instead of [CreateSolidBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createsolidbrush) ( [GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor) (nIndex)), because **GetSysColorBrush** returns a cached brush instead of allocating a new one.

System color brushes are owned by the system so you don't need to destroy them. Although you don't need to delete the logical brush that **GetSysColorBrush** returns, no harm occurs by calling [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject).

## See also

[Brush Functions](https://learn.microsoft.com/windows/desktop/gdi/brush-functions)

[Brushes Overview](https://learn.microsoft.com/windows/desktop/gdi/brushes)

[CreateSolidBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createsolidbrush)

[GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor)

[SetSysColors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setsyscolors)

[WNDCLASS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassa)

[WNDCLASSEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassexa)
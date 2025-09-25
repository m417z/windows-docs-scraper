# WNDCLASSA structure

## Description

Contains the window class attributes that are registered by the [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa) function.

This structure has been superseded by the [WNDCLASSEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassexa) structure used with the [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa) function. You can still use **WNDCLASS** and [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa) if you do not need to set the small icon associated with the window class.

## Members

### `style`

Type: **UINT**

The class style(s). This member can be any combination of the [Class Styles](https://learn.microsoft.com/windows/desktop/winmsg/about-window-classes#class-styles).

### `lpfnWndProc`

Type: **WNDPROC**

A pointer to the window procedure. You must use the [CallWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-callwindowproca) function to call the window procedure. For more information, see [WindowProc](https://learn.microsoft.com/windows/win32/api/winuser/nc-winuser-wndproc).

### `cbClsExtra`

Type: **int**

The number of extra bytes to allocate following the window-class structure. The system initializes the bytes to zero.

### `cbWndExtra`

Type: **int**

The number of extra bytes to allocate following the window instance. The system initializes the bytes to zero. If an application uses **WNDCLASS** to register a dialog box created by using the
**CLASS** directive in the resource file, it must set this member to **DLGWINDOWEXTRA**.

### `hInstance`

Type: **HINSTANCE**

A handle to the instance that contains the window procedure for the class.

### `hIcon`

Type: **HICON**

A handle to the class icon. This member must be a handle to an icon resource. If this member is **NULL**, the system provides a default icon.

### `hCursor`

Type: **HCURSOR**

A handle to the class cursor. This member must be a handle to a cursor resource. If this member is **NULL**, an application must explicitly set the cursor shape whenever the mouse moves into the application's window.

### `hbrBackground`

Type: **HBRUSH**

A handle to the class background brush. This member can be a handle to the physical brush to be used for painting the background, or it can be a color value. A color value must be one of the following standard system colors (the value 1 must be added to the chosen color). If a color value is given, you must convert it to one of the following
**HBRUSH** types:

* COLOR_ACTIVEBORDER
* COLOR_ACTIVECAPTION
* COLOR_APPWORKSPACE
* COLOR_BACKGROUND
* COLOR_BTNFACE
* COLOR_BTNSHADOW
* COLOR_BTNTEXT
* COLOR_CAPTIONTEXT
* COLOR_GRAYTEXT
* COLOR_HIGHLIGHT
* COLOR_HIGHLIGHTTEXT
* COLOR_INACTIVEBORDER
* COLOR_INACTIVECAPTION
* COLOR_MENU
* COLOR_MENUTEXT
* COLOR_SCROLLBAR
* COLOR_WINDOW
* COLOR_WINDOWFRAME
* COLOR_WINDOWTEXT

The system automatically deletes class background brushes when the class is unregistered by using [UnregisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unregisterclassa). An application should not delete these brushes.

When this member is **NULL**, an application must paint its own background whenever it is requested to paint in its client area. To determine whether the background must be painted, an application can either process the
[WM_ERASEBKGND](https://learn.microsoft.com/windows/desktop/winmsg/wm-erasebkgnd) message or test the
**fErase** member of the [PAINTSTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-paintstruct) structure filled by the [BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint) function.

### `lpszMenuName`

Type: **LPCTSTR**

The resource name of the class menu, as the name appears in the resource file. If you use an integer to identify the menu, use the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro. If this member is **NULL**, windows belonging to this class have no default menu.

### `lpszClassName`

Type: **LPCTSTR**

A pointer to a null-terminated string or is an atom. If this parameter is an atom, it must be a class atom created by a previous call to the [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa) or [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa) function. The atom must be in the low-order word of
**lpszClassName**; the high-order word must be zero.

If **lpszClassName** is a string, it specifies the window class name. The class name can be any name registered with [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa) or [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa), or any of the predefined control-class names.

The maximum length for **lpszClassName** is 256. If **lpszClassName** is greater than the maximum length, the [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa) function will fail.

## See also

[BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint)

**Conceptual**

[CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa)

[CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa)

[GetDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdc)

[MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)

**Other Resources**

[PAINTSTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-paintstruct)

**Reference**

[RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa)

[UnregisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unregisterclassa)

[WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint)

[WNDCLASSEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassexa)

[Window Classes](https://learn.microsoft.com/windows/desktop/winmsg/window-classes)

[WindowProc](https://learn.microsoft.com/windows/win32/api/winuser/nc-winuser-wndproc)

## Remarks

> [!NOTE]
> The winuser.h header defines WNDCLASS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
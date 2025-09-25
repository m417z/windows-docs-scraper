# WNDCLASSEXA structure

## Description

Contains window class information. It is used with the [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa) and [GetClassInfoEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclassinfoexa)
functions.

The **WNDCLASSEX** structure is similar to the [WNDCLASS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wndclassa) structure. There are two differences. **WNDCLASSEX** includes the **cbSize** member, which specifies the size of the structure, and the **hIconSm** member, which contains a handle to a small icon associated with the window class.

## Members

### `cbSize`

Type: **UINT**

The size, in bytes, of this structure. Set this member to `sizeof(WNDCLASSEX)`. Be sure to set this member before calling the [GetClassInfoEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclassinfoexa) function.

### `style`

Type: **UINT**

The class style(s). This member can be any combination of the [Class Styles](https://learn.microsoft.com/windows/win32/winmsg/window-class-styles).

### `lpfnWndProc`

Type: **WNDPROC**

A pointer to the window procedure. You must use the [CallWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-callwindowproca) function to call the window procedure. For more information, see [WindowProc](https://learn.microsoft.com/windows/win32/api/winuser/nc-winuser-wndproc).

### `cbClsExtra`

Type: **int**

The number of extra bytes to allocate following the window-class structure. The system initializes the bytes to zero.

### `cbWndExtra`

Type: **int**

The number of extra bytes to allocate following the window instance. The system initializes the bytes to zero. If an application uses **WNDCLASSEX** to register a dialog box created by using the
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

A handle to the class background brush. This member can be a handle to the brush to be used for painting the background, or it can be a color value. A color value must be one of the following standard system colors (the value 1 must be added to the chosen color). If a color value is given, you must convert it to one of the following
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

A pointer to a null-terminated character string that specifies the resource name of the class menu, as the name appears in the resource file. If you use an integer to identify the menu, use the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro. If this member is **NULL**, windows belonging to this class have no default menu.

### `lpszClassName`

Type: **LPCTSTR**

A pointer to a null-terminated string or is an atom. If this parameter is an atom, it must be a class atom created by a previous call to the [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa) or [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa) function. The atom must be in the low-order word of
**lpszClassName**; the high-order word must be zero.

If **lpszClassName** is a string, it specifies the window class name. The class name can be any name registered with [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa) or [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa), or any of the predefined control-class names.

The maximum length for **lpszClassName** is 256. If **lpszClassName** is greater than the maximum length, the [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa) function will fail.

### `hIconSm`

Type: **HICON**

A handle to a small icon that is associated with the window class. If this member is **NULL**, the system searches the icon resource specified by the
**hIcon** member for an icon of the appropriate size to use as the small icon.

## See also

**Conceptual**

[GetClassInfoEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclassinfoexa)

**Reference**

[RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa)

[UnregisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-unregisterclassa)

[Window Classes](https://learn.microsoft.com/windows/desktop/winmsg/window-classes)

## Remarks

> [!NOTE]
> The winuser.h header defines WNDCLASSEX as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
# CreateMDIWindowA function

## Description

Creates a multiple-document interface (MDI) child window.

## Parameters

### `lpClassName` [in]

Type: **LPCTSTR**

The window class of the MDI child window. The class name must have been registered by a call to the [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa) function.

### `lpWindowName` [in]

Type: **LPCTSTR**

The window name. The system displays the name in the title bar of the child window.

### `dwStyle` [in]

Type: **DWORD**

The style of the MDI child window. If the MDI client window is created with the **MDIS_ALLCHILDSTYLES** window style, this parameter can be any combination of the window styles listed in the [Window Styles](https://learn.microsoft.com/windows/desktop/winmsg/window-styles) page. Otherwise, this parameter is limited to one or more of the following values.

| Value | Meaning |
| --- | --- |
| **WS_MINIMIZE**<br><br>0x20000000L | Creates an MDI child window that is initially minimized. |
| **WS_MAXIMIZE**<br><br>0x01000000L | Creates an MDI child window that is initially maximized. |
| **WS_HSCROLL**<br><br>0x00100000L | Creates an MDI child window that has a horizontal scroll bar. |
| **WS_VSCROLL**<br><br>0x00200000L | Creates an MDI child window that has a vertical scroll bar. |

### `X` [in]

Type: **int**

The initial horizontal position, in client coordinates, of the MDI child window. If this parameter is **CW_USEDEFAULT** ((int)0x80000000), the MDI child window is assigned the default horizontal position.

### `Y` [in]

Type: **int**

The initial vertical position, in client coordinates, of the MDI child window. If this parameter is **CW_USEDEFAULT**, the MDI child window is assigned the default vertical position.

### `nWidth` [in]

Type: **int**

The initial width, in device units, of the MDI child window. If this parameter is **CW_USEDEFAULT**, the MDI child window is assigned the default width.

### `nHeight` [in]

Type: **int**

The initial height, in device units, of the MDI child window. If this parameter is set to **CW_USEDEFAULT**, the MDI child window is assigned the default height.

### `hWndParent` [in, optional]

Type: **HWND**

A handle to the MDI client window that will be the parent of the new MDI child window.

### `hInstance` [in, optional]

Type: **HINSTANCE**

A handle to the instance of the application creating the MDI child window.

### `lParam` [in]

Type: **LPARAM**

An application-defined value.

## Return value

Type: **HWND**

If the function succeeds, the return value is the handle to the created window.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

**Conceptual**

[CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa)

[Multiple Document Interface](https://learn.microsoft.com/windows/desktop/winmsg/multiple-document-interface)

**Reference**

[RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa)

[WM_MDICREATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-mdicreate)

## Remarks

> [!NOTE]
> The winuser.h header defines CreateMDIWindow as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
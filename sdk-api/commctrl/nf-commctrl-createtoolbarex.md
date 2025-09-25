# CreateToolbarEx function

## Description

Creates a toolbar window and adds the specified buttons to the toolbar.

**Note** This function is deprecated, because it does not support all features of toolbars. Use [CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa) instead. For examples, see [Using Toolbar Controls](https://learn.microsoft.com/windows/desktop/Controls/using-toolbar-controls).

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the parent window for the toolbar.

### `ws`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Window styles for the toolbar. The [WS_CHILD](https://learn.microsoft.com/windows/desktop/winmsg/window-styles) style is included by default. This parameter can also include a combination of styles as discussed in [Toolbar Control and Button Styles](https://learn.microsoft.com/windows/desktop/Controls/toolbar-control-and-button-styles).

### `wID`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Control identifier for the toolbar.

### `nBitmaps`

Type: **int**

Number of button images contained in the bitmap specified by
*hBMInst* and
*wBMID*.

### `hBMInst`

Type: **[HINSTANCE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Module instance with the executable file that contains the bitmap resource.

### `wBMID`

Type: **[UINT_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Resource identifier for the bitmap resource. If
*hBMInst* is **NULL**, this parameter must be a valid bitmap handle.

### `lpButtons`

Type: **LPCTBBUTTON**

Pointer to an array of [TBBUTTON](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tbbutton) structures that contain information about the buttons to add to the toolbar.

### `iNumButtons`

Type: **int**

Number of buttons to add to the toolbar.

### `dxButton`

Type: **int**

Width, in pixels, of the buttons to add to the toolbar.

### `dyButton`

Type: **int**

Height, in pixels, of the buttons to add to the toolbar.

### `dxBitmap`

Type: **int**

Width, in pixels, of the button images to add to the buttons in the toolbar.

### `dyBitmap`

Type: **int**

Height, in pixels, of the button images to add to the buttons in the toolbar.

### `uStructSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of a [TBBUTTON](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tbbutton) structure.

## Return value

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns the window handle to the toolbar if successful, or **NULL** otherwise. To retrieve extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Windows 95: The system can support a maximum of 16,364 window handles.
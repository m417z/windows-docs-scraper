# GetMenu function

## Description

Retrieves a handle to the menu assigned to the specified window.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window whose menu handle is to be retrieved.

## Return value

Type: **HMENU**

The return value is a handle to the menu. If the specified window has no menu, the return value is **NULL**. If the window is a child window, the return value is undefined.

## Remarks

**GetMenu** does not work on floating menu bars. Floating menu bars are custom controls that mimic standard menus; they are not menus. To get the handle on a floating menu bar, use the [Active Accessibility](https://learn.microsoft.com/previous-versions/ms971350(v=msdn.10)) APIs.

#### Examples

For an example, see [Adding Lines and Graphs to a Menu](https://learn.microsoft.com/windows/desktop/menurc/using-menus).

## See also

**Conceptual**

[GetSubMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsubmenu)

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**

[SetMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenu)
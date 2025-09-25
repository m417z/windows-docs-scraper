# ListView_GetViewRect macro

## Syntax

```cpp
BOOL ListView_GetViewRect(
   HWND hwnd,
   RECT *prc
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Gets the bounding rectangle of all items in the list-view control. The list view must be in icon or small icon view. You can use this macro or send the [LVM_GETVIEWRECT](https://learn.microsoft.com/windows/desktop/Controls/lvm-getviewrect) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `prc`

Type: **[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)***

A pointer to a [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that receives the bounding rectangle. All coordinates are relative to the visible area of the list-view control.
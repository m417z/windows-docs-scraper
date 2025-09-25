# ListView_GetFooterItemRect macro

## Syntax

```cpp
BOOL ListView_GetFooterItemRect(
  [in]      HWND hwnd,
  [in]      UINT iItem,
  [in, out] RECT *prc
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Gets the coordinates of a footer for a specified item in a list-view control. Use this macro or send the [LVM_GETFOOTERITEMRECT](https://learn.microsoft.com/windows/desktop/Controls/lvm-getfooteritemrect) message explicitly.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `iItem` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the item in the list-view control.

### `prc` [in, out]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure to receive the coordinates. The calling application is responsible for allocating this structure. The coordinates received are expressed as client coordinates.
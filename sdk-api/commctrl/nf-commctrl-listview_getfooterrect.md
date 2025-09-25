# ListView_GetFooterRect macro

## Syntax

```cpp
BOOL ListView_GetFooterRect(
  [in]      HWND hwnd,
  [in, out] RECT *prc
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Gets the coordinates of the footer for a specified list-view control. Use this macro or send the [LVM_GETFOOTERRECT](https://learn.microsoft.com/windows/desktop/Controls/lvm-getfooterrect) message explicitly.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `prc` [in, out]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure to receive the coordinates. The caller is responsible for allocating this structure. The coordinates received are expressed as client coordinates.
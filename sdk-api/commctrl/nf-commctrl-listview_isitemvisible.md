# ListView_IsItemVisible macro

## Syntax

```cpp
UINT ListView_IsItemVisible(
  [in] HWND hwnd,
  [in] UINT index
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if visible, or **FALSE** otherwise.

## Description

Indicates whether an item in the list-view control is visible. Use this macro or send the [LVM_ISITEMVISIBLE](https://learn.microsoft.com/windows/desktop/Controls/lvm-isitemvisible) message explicitly.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `index` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of item in list-view control.
# ListView_GetTopIndex macro

## Syntax

```cpp
int ListView_GetTopIndex(
   HWND hwndLV
);
```

## Return value

Type: **int**

Returns the index of the item if successful, or zero if the list-view control is in icon or small icon view.

## Description

Gets the index of the topmost visible item when in list or report view. You can use this macro or send the [LVM_GETTOPINDEX](https://learn.microsoft.com/windows/desktop/controls/lvm-gettopindex) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.
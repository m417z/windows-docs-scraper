# ListView_GetCountPerPage macro

## Syntax

```cpp
int ListView_GetCountPerPage(
   HWND hwndLV
);
```

## Return value

Type: **int**

Returns the number of fully visible items if successful. If the current view is icon or small icon view, the return value is the total number of items in the list-view control.

## Description

Calculates the number of items that can fit vertically in the visible area of a list-view control when in list or report view. Only fully visible items are counted. You can use this macro or send the [LVM_GETCOUNTPERPAGE](https://learn.microsoft.com/windows/desktop/Controls/lvm-getcountperpage) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.
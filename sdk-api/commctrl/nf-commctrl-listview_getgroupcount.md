# ListView_GetGroupCount macro

## Syntax

```cpp
int ListView_GetGroupCount(
   HWND hwnd
);
```

## Return value

Type: **int**

Returns the number of groups if successful, or -1 otherwise.

## Description

Gets the number of groups. You can use this macro or send the [LVM_GETGROUPCOUNT](https://learn.microsoft.com/windows/desktop/Controls/lvm-getgroupcount) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

## Remarks

To use **ListView_GetGroupCount**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).
# ListView_RemoveGroup macro

## Syntax

```cpp
int ListView_RemoveGroup(
   HWND hwnd,
   int  iGroupId
);
```

## Return value

Type: **int**

Returns the index of the group if successful, or -1 otherwise.

## Description

Removes a group from a list-view control. You can use this macro or send the [LVM_REMOVEGROUP](https://learn.microsoft.com/windows/desktop/Controls/lvm-removegroup) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `iGroupId`

Type: **int**

## Remarks

To use **ListView_RemoveGroup**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).
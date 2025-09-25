# ListView_HasGroup macro

## Syntax

```cpp
BOOL ListView_HasGroup(
   HWND hwnd,
   int  dwGroupId
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if the list-view control has the specified group, or **FALSE** otherwise.

## Description

Determines whether the list-view control has a specified group. You can use this macro or send the [LVM_HASGROUP](https://learn.microsoft.com/windows/desktop/Controls/lvm-hasgroup) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `dwGroupId`

Type: **int**

## Remarks

To use **ListView_HasGroup**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).
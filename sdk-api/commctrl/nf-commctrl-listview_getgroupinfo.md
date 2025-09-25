# ListView_GetGroupInfo macro

## Syntax

```cpp
int ListView_GetGroupInfo(
   HWND     hwnd,
   int      iGroupId,
   PLVGROUP pgrp
);
```

## Return value

Type: **int**

Returns the ID of the group if successful, or -1 otherwise.

## Description

Gets group information. You can use this macro or send the [LVM_GETGROUPINFO](https://learn.microsoft.com/windows/desktop/Controls/lvm-getgroupinfo) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `iGroupId`

Type: **int**

### `pgrp`

Type: **PLVGROUP**

[LVGROUP](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvgroup)

## Remarks

To use **ListView_GetGroupInfo**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).
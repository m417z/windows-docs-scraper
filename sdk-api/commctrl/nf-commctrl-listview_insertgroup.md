# ListView_InsertGroup macro

## Syntax

```cpp
int ListView_InsertGroup(
   HWND     hwnd,
   int      index,
   PLVGROUP pgrp
);
```

## Return value

Type: **int**

Returns the index of the item that the group was added to, or -1 if the operation failed.

## Description

Inserts a group into a list-view control. You can use this macro or send the [LVM_INSERTGROUP](https://learn.microsoft.com/windows/desktop/Controls/lvm-insertgroup) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `index`

Type: **int**

### `pgrp`

Type: **PLVGROUP**

[LVGROUP](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvgroup)

## Remarks

To turn on group mode, call [LVM_ENABLEGROUPVIEW](https://learn.microsoft.com/windows/desktop/Controls/lvm-enablegroupview) or [ListView_EnableGroupView](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_enablegroupview).

To use **ListView_InsertGroup**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).
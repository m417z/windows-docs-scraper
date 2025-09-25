# ListView_InsertGroupSorted macro

## Syntax

```cpp
void ListView_InsertGroupSorted(
   HWND                 hwnd,
   PLVINSERTGROUPSORTED structInsert
);
```

## Description

Inserts a group into an ordered list of groups. You can use this macro or send the [LVM_INSERTGROUPSORTED](https://learn.microsoft.com/windows/desktop/Controls/lvm-insertgroupsorted) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `structInsert`

Type: **PLVINSERTGROUPSORTED**

[LVINSERTGROUPSORTED](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvinsertgroupsorted)

## Remarks

To use **ListView_InsertGroupSorted**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).
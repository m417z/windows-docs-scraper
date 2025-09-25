# ListView_RemoveAllGroups macro

## Syntax

```cpp
void ListView_RemoveAllGroups(
   HWND hwnd
);
```

## Description

Removes all groups from a list-view control. You can use this macro or send the [LVM_REMOVEALLGROUPS](https://learn.microsoft.com/windows/desktop/Controls/lvm-removeallgroups) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

## Remarks

To use **ListView_RemoveAllGroups**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).
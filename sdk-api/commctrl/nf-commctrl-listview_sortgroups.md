# ListView_SortGroups macro

## Syntax

```cpp
int ListView_SortGroups(
   HWND              hwnd,
   PFNLVGROUPCOMPARE _pfnGroupCompate,
   LPVOID            _plv
);
```

## Return value

Type: **int**

Returns 1 if successful, or 0 otherwise.

## Description

Uses an application-defined comparison function to sort groups by ID within a list-view control. You can use this macro or send the [LVM_SORTGROUPS](https://learn.microsoft.com/windows/desktop/Controls/lvm-sortgroups) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `_pfnGroupCompate`

Type: **PFNLVGROUPCOMPARE**

### `_plv`

Type: **[LPVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

## Remarks

To use **ListView_SortGroups**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).
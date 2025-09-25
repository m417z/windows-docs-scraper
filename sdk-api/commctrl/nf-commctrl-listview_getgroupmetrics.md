# ListView_GetGroupMetrics macro

## Syntax

```cpp
void ListView_GetGroupMetrics(
   HWND            hwnd,
   PLVGROUPMETRICS pGroupMetrics
);
```

## Description

Gets information about the display of groups. You can use this macro or send the [LVM_GETGROUPMETRICS](https://learn.microsoft.com/windows/desktop/Controls/lvm-getgroupmetrics) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `pGroupMetrics`

Type: **PLVGROUPMETRICS**

[LVGROUPMETRICS](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvgroupmetrics)

## Remarks

To use **ListView_GetGroupMetrics**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).
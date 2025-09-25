# ListView_GetTileInfo macro

## Syntax

```cpp
void ListView_GetTileInfo(
   HWND        hwnd,
   PLVTILEINFO pti
);
```

## Description

Gets information about a tile in a list-view control. You can use this macro or send the [LVM_GETTILEINFO](https://learn.microsoft.com/windows/desktop/Controls/lvm-gettileinfo) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `pti`

Type: **PLVTILEINFO**

[LVTILEINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvtileinfo)

## Remarks

To use **ListView_GetTileInfo**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).
# ListView_GetTileViewInfo macro

## Syntax

```cpp
void ListView_GetTileViewInfo(
   HWND            hwnd,
   PLVTILEVIEWINFO ptvi
);
```

## Description

Gets information about a list-view control in tile view. You can use this macro or send the [LVM_GETTILEVIEWINFO](https://learn.microsoft.com/windows/desktop/Controls/lvm-gettileviewinfo) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `ptvi`

Type: **PLVTILEVIEWINFO**

[LVTILEVIEWINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvtileviewinfo)

## Remarks

To use **ListView_GetTileViewInfo**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).
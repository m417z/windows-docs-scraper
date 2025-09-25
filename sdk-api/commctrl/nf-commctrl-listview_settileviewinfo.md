# ListView_SetTileViewInfo macro

## Syntax

```cpp
BOOL ListView_SetTileViewInfo(
   HWND            hwnd,
   PLVTILEVIEWINFO ptvi
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Sets information that a list-view control uses in tile view. You can use this macro or send the [LVM_SETTILEVIEWINFO](https://learn.microsoft.com/windows/desktop/Controls/lvm-settileviewinfo) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `ptvi`

Type: **PLVTILEVIEWINFO**

[LVTILEVIEWINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvtileviewinfo)

## Remarks

To use **ListView_SetTileViewInfo**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).
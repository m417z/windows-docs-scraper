# ListView_SetTileInfo macro

## Syntax

```cpp
BOOL ListView_SetTileInfo(
   HWND        hwnd,
   PLVTILEINFO pti
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Sets information for an existing tile of a list-view control. You can use this macro or send the [LVM_SETTILEINFO](https://learn.microsoft.com/windows/desktop/Controls/lvm-settileinfo) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `pti`

Type: **PLVTILEINFO**

[LVTILEINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvtileinfo)

## Remarks

To use **ListView_SetTileInfo**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).
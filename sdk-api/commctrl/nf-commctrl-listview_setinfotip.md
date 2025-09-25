# ListView_SetInfoTip macro

## Syntax

```cpp
BOOL ListView_SetInfoTip(
   HWND          hwndLV,
   PLVSETINFOTIP plvInfoTip
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if the tooltip text is set successfully, or **FALSE** otherwise.

## Description

Sets tooltip text. You can use this macro or send the [LVM_SETINFOTIP](https://learn.microsoft.com/windows/desktop/Controls/lvm-setinfotip) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `plvInfoTip`

Type: **PLVSETINFOTIP**

[LVSETINFOTIP](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvsetinfotip)

## Remarks

To use **ListView_SetInfoTip**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).
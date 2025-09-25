# ListView_InsertMarkHitTest macro

## Syntax

```cpp
BOOL ListView_InsertMarkHitTest(
   HWND          hwnd,
   LPPOINT       point,
   PLVINSERTMARK lvim
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Retrieves the insertion point closest to a specified point. You can use this macro or send the [LVM_INSERTMARKHITTEST](https://learn.microsoft.com/windows/desktop/Controls/lvm-insertmarkhittest) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `point`

Type: **LPPOINT**

**POINT**

### `lvim`

Type: **PLVINSERTMARK**

[LVINSERTMARK](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvinsertmark)
*point*

## Remarks

To use **ListView_InsertMarkHitTest**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).
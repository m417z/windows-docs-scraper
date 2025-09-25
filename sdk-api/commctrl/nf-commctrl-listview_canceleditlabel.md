# ListView_CancelEditLabel macro

## Syntax

```cpp
void ListView_CancelEditLabel(
   HWND hwnd
);
```

## Description

Cancels an item text editing operation. You can use this macro or send the [LVM_CANCELEDITLABEL](https://learn.microsoft.com/windows/desktop/Controls/lvm-canceleditlabel) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

## Remarks

To use **ListView_CancelEditLabel**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).
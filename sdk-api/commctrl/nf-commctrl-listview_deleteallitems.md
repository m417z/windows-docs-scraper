# ListView_DeleteAllItems macro

## Syntax

```cpp
BOOL ListView_DeleteAllItems(
   HWND hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Removes all items from a list-view control. You can use this macro or send the [LVM_DELETEALLITEMS](https://learn.microsoft.com/windows/desktop/Controls/lvm-deleteallitems) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

## Remarks

When a list-view control receives the [LVM_DELETEALLITEMS](https://learn.microsoft.com/windows/desktop/Controls/lvm-deleteallitems) message, it sends the [LVN_DELETEALLITEMS](https://learn.microsoft.com/windows/desktop/Controls/lvn-deleteallitems) notification code to its parent window.
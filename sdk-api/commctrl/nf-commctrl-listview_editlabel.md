# ListView_EditLabel macro

## Syntax

```cpp
HWND ListView_EditLabel(
   HWND hwndLV,
   int  i
);
```

## Return value

Type: **[HWND](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the handle to the edit control that is used to edit the item text if successful, or **NULL** otherwise.

## Description

Begins in-place editing of the specified list-view item's text. The message implicitly selects and focuses the specified item. You can use this macro or send the [LVM_EDITLABEL](https://learn.microsoft.com/windows/desktop/Controls/lvm-editlabel) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `i`

Type: **int**

The index of the list-view item. To cancel editing, set *i* to -1.

## Remarks

When the user completes or cancels editing, the edit control is destroyed and the handle is no longer valid. You can subclass the edit control, but you should not destroy it.

The control must have the focus before you send this message to the control. Focus can be set using the [SetFocus](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setfocus) function.

## See also

[WM_CANCELMODE](https://learn.microsoft.com/windows/desktop/winmsg/wm-cancelmode)
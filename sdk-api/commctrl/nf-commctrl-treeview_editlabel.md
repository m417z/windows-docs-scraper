# TreeView_EditLabel macro

## Syntax

```cpp
HWND TreeView_EditLabel(
   HWND      hwnd,
   HTREEITEM hitem
);
```

## Return value

Type: **[HWND](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the handle to the edit control used to edit the item text if successful, or **NULL** otherwise.

## Description

Begins in-place editing of the specified item's text, replacing the text of the item with a single-line edit control containing the text. This macro implicitly selects and focuses the specified item. You can use this macro or send the [TVM_EDITLABEL](https://learn.microsoft.com/windows/desktop/Controls/tvm-editlabel) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `hitem`

Type: **HTREEITEM**

Handle to the item to edit.

## Remarks

This macro sends a [TVN_BEGINLABELEDIT](https://learn.microsoft.com/windows/desktop/Controls/tvn-beginlabeledit) notification code to the parent of the tree-view control.

When the user completes or cancels editing, the edit control is destroyed and the handle is no longer valid. You can subclass the edit control, but do not destroy it.

The control must have the focus before you call this macro. Focus can be set using the [SetFocus](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setfocus) function.
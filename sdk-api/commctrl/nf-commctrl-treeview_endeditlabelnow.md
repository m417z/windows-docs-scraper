# TreeView_EndEditLabelNow macro

## Syntax

```cpp
BOOL TreeView_EndEditLabelNow(
   HWND hwnd,
   BOOL fCancel
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Ends the editing of a tree-view item's label. You can use this macro or send the [TVM_ENDEDITLABELNOW](https://learn.microsoft.com/windows/desktop/Controls/tvm-endeditlabelnow) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `fCancel`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Variable that indicates whether the editing is canceled without being saved to the label. If this parameter is **TRUE**, the system cancels editing without saving the changes. Otherwise, the system saves the changes to the label.

## Remarks

This macro causes the [TVN_ENDLABELEDIT](https://learn.microsoft.com/windows/desktop/Controls/tvn-endlabeledit) notification code to be sent to the parent window of the tree-view control.
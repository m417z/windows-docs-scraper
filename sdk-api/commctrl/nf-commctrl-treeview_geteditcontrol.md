# TreeView_GetEditControl macro

## Syntax

```cpp
HWND TreeView_GetEditControl(
   HWND hwnd
);
```

## Description

Retrieves the handle to the edit control being used to edit a tree-view item's text. You can use this macro or send the [TVM_GETEDITCONTROL](https://learn.microsoft.com/windows/desktop/Controls/tvm-geteditcontrol) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

## Return value

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The handle to the edit control being used to edit a tree-view item's text, or NULL if no item is being edited.

## Remarks

When label editing begins, an edit control is created but not positioned or displayed. Before it is displayed, the tree-view control sends its parent window a [TVN_BEGINLABELEDIT](https://learn.microsoft.com/windows/desktop/Controls/tvn-beginlabeledit) notification code.

To customize label editing, implement a handler for [TVN_BEGINLABELEDIT](https://learn.microsoft.com/windows/desktop/Controls/tvn-beginlabeledit) and have it use **TreeView_GetEditControl** to send a [TVM_GETEDITCONTROL](https://learn.microsoft.com/windows/desktop/Controls/tvm-geteditcontrol) message to the tree-view control. If a label is being edited, the return value will be a handle to the edit control. Use this handle to customize the edit control by sending the usual EM_XXX messages.
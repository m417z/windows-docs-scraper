# TreeView_Expand macro

## Syntax

```cpp
BOOL TreeView_Expand(
   HWND      hwnd,
   HTREEITEM hitem,
   UINT      code
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if the operation was successful, or zero otherwise.

## Description

The **TreeView_Expand** macro expands or collapses the list of child items associated with the specified parent item, if any. You can use this macro or send the [TVM_EXPAND](https://learn.microsoft.com/windows/desktop/Controls/tvm-expand) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a tree-view control.

### `hitem`

Type: **HTREEITEM**

Handle to the parent item that will be expanded or collapsed.

### `code`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Action flag. For a list of possible values, see the description of the *wParam* parameter in [TVM_EXPAND](https://learn.microsoft.com/windows/desktop/Controls/tvm-expand).

## Remarks

Expanding a node that is already expanded, or collapsing a node that is already collapsed is considered a successful operation and the macro returns a nonzero value. Attempting to expand or collapse a node that has no children is considered a failure and the return value is zero.

When an item is first expanded by a [TVM_EXPAND](https://learn.microsoft.com/windows/desktop/Controls/tvm-expand) message, the action generates [TVN_ITEMEXPANDING](https://learn.microsoft.com/windows/desktop/Controls/tvn-itemexpanding) and [TVN_ITEMEXPANDED](https://learn.microsoft.com/windows/desktop/Controls/tvn-itemexpanded) notification codes and the item's [TVIS_EXPANDEDONCE](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-item-states) state flag is set. As long as this state flag remains set, subsequent **TVM_EXPAND** messages do not generate TVN_ITEMEXPANDING or TVN_ITEMEXPANDED notifications. To reset the **TVIS_EXPANDEDONCE** state flag, you must send a **TVM_EXPAND** message with the TVE_COLLAPSE and TVE_COLLAPSERESET flags set. Attempting to explicitly set **TVIS_EXPANDEDONCE** will result in unpredictable behavior.

The expand operation may fail if the owner of the treeview control denies the operation in response to a [TVN_ITEMEXPANDING](https://learn.microsoft.com/windows/desktop/Controls/tvn-itemexpanding) notification.
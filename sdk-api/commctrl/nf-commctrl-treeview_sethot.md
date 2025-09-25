# TreeView_SetHot macro

## Syntax

```cpp
LRESULT TreeView_SetHot(
   HWND      hwnd,
   HTREEITEM hitem
);
```

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

[Intended for internal use; not recommended for use in applications. This macro may not be supported in future versions of Windows.]

Sets the hot item for a tree-view control. You can use this macro or send the [TVM_SETHOT](https://learn.microsoft.com/windows/desktop/Controls/tvm-sethot) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `hitem`

Type: **HTREEITEM**

Handle to the new hot item. If this value is **NULL**, the tree-view control will be set to have no hot item.

## Remarks

The *hot item* is the item that the mouse is hovering over. The [TVM_SETHOT](https://learn.microsoft.com/windows/desktop/Controls/tvm-sethot) message sent by this macro makes an item look like it is the hot item even if the mouse is not hovering over it.

The [TVM_SETHOT](https://learn.microsoft.com/windows/desktop/Controls/tvm-sethot) message has no visible effect if the [TVS_TRACKSELECT](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-styles) style is not set.

If it succeeds, the [TVM_SETHOT](https://learn.microsoft.com/windows/desktop/Controls/tvm-sethot) message causes the hot item to be redrawn.

The [TVM_SETHOT](https://learn.microsoft.com/windows/desktop/Controls/tvm-sethot) message is ignored if *hitem* is **NULL** and the tree-view control is tracking the mouse.

## See also

[TVM_SETHOT](https://learn.microsoft.com/windows/desktop/Controls/tvm-sethot)
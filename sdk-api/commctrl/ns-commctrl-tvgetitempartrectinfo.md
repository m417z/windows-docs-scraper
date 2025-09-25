# TVGETITEMPARTRECTINFO structure

## Description

Contains information for identifying the "hit zone" for a specified part of a tree item. The structure is used with the [TVM_GETITEMPARTRECT](https://learn.microsoft.com/windows/desktop/Controls/tvm-getitempartrect) message and the [TreeView_GetItemPartRect](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getitempartrect) macro.

## Members

### `hti`

Type: **HTREEITEM**

Handle to the parent item.

### `prc`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure to receive the coordinates of the bounding rectangle. The sender of the message (the caller) is responsible for allocating this structure.

### `partID`

Type: **TVITEMPART**

ID of the item part. This value must be **TVGIPR_BUTTON** (0x0001).
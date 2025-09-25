# TVHITTESTINFO structure

## Description

Contains information used to determine the location of a point relative to a tree-view control. This structure is used with the [TVM_HITTEST](https://learn.microsoft.com/windows/desktop/Controls/tvm-hittest) message. The structure is identical to the
**TV_HITTESTINFO** structure, but it has been renamed to follow current naming conventions.

## Members

### `pt`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

Client coordinates of the point to test.

### `flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Variable that receives information about the results of a hit test. This member can be one or more of the following values:

| Value | Meaning |
| --- | --- |
| **TVHT_ABOVE** | Above the client area. |
| **TVHT_BELOW** | Below the client area. |
| **TVHT_NOWHERE** | In the client area, but below the last item. |
| **TVHT_ONITEM** | On the bitmap or label associated with an item. |
| **TVHT_ONITEMBUTTON** | On the button associated with an item. |
| **TVHT_ONITEMICON** | On the bitmap associated with an item. |
| **TVHT_ONITEMINDENT** | In the indentation associated with an item. |
| **TVHT_ONITEMLABEL** | On the label (string) associated with an item. |
| **TVHT_ONITEMRIGHT** | In the area to the right of an item. |
| **TVHT_ONITEMSTATEICON** | On the state icon for a tree-view item that is in a user-defined state. |
| **TVHT_TOLEFT** | To the left of the client area. |
| **TVHT_TORIGHT** | To the right of the client area. |

### `hItem`

Type: **HTREEITEM**

Handle to the item that occupies the point.
# LVHITTESTINFO structure

## Description

Contains information about a hit test. This structure has been extended to accommodate subitem hit-testing. It is used in association with the [LVM_HITTEST](https://learn.microsoft.com/windows/desktop/Controls/lvm-hittest) and [LVM_SUBITEMHITTEST](https://learn.microsoft.com/windows/desktop/Controls/lvm-subitemhittest) messages and their related macros. This structure supersedes the
**LVHITTESTINFO** structure.

## Members

### `pt`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The position to hit test, in client coordinates.

### `flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The variable that receives information about the results of a hit test. This member can be one or more of the following values:

You can use LVHT_ABOVE, LVHT_BELOW, LVHT_TOLEFT, and LVHT_TORIGHT to determine whether to scroll the contents of a list-view control. Two of these values may be combined. For example, if the position is above and to the left of the client area, you could use both LVHT_ABOVE and LVHT_TOLEFT.

You can test for LVHT_ONITEM to determine whether a specified position is over a list-view item. This value is a bitwise-OR operation on LVHT_ONITEMICON, LVHT_ONITEMLABEL, and LVHT_ONITEMSTATEICON.

| Value | Meaning |
| --- | --- |
| **LVHT_ABOVE** | The position is above the control's client area. |
| **LVHT_BELOW** | The position is below the control's client area. |
| **LVHT_NOWHERE** | The position is inside the list-view control's client window, but it is not over a list item. |
| **LVHT_ONITEMICON** | The position is over a list-view item's icon. |
| **LVHT_ONITEMLABEL** | The position is over a list-view item's text. |
| **LVHT_ONITEMSTATEICON** | The position is over the state image of a list-view item. |
| **LVHT_TOLEFT** | The position is to the left of the list-view control's client area. |
| **LVHT_TORIGHT** | The position is to the right of the list-view control's client area. |
| **LVHT_EX_GROUP_HEADER** | **Windows Vista.** The point is within the group header. |
| **LVHT_EX_GROUP_FOOTER** | **Windows Vista.** The point is within the group footer. |
| **LVHT_EX_GROUP_COLLAPSE** | **Windows Vista.** The point is within the collapse/expand button of the group. |
| **LVHT_EX_GROUP_BACKGROUND** | **Windows Vista.** The point is within the area of the group where items are displayed. |
| **LVHT_EX_GROUP_STATEICON** | **Windows Vista.** The point is within the state icon of the group. |
| **LVHT_EX_GROUP_SUBSETLINK** | **Windows Vista.** The point is within the subset link of the group. |
| **LVHT_EX_GROUP** | **Windows Vista.** LVHT_EX_GROUP_BACKGROUND \| LVHT_EX_GROUP_COLLAPSE \| LVHT_EX_GROUP_FOOTER \| LVHT_EX_GROUP_HEADER \| LVHT_EX_GROUP_STATEICON \| LVHT_EX_GROUP_SUBSETLINK. |
| **LVHT_EX_ONCONTENTS** | **Windows Vista.** The point is within the icon or text content of the item and not on the background. |
| **LVHT_EX_FOOTER** | **Windows Vista.** The point is within the footer of the list-view control. |

### `iItem`

Type: **int**

Receives the index of the matching item. Or if hit-testing a subitem, this value represents the subitem's parent item.

### `iSubItem`

Type: **int**

[Version 4.70](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Receives the index of the matching subitem. When hit-testing an item, this member will be zero.

### `iGroup`

Type: **int**

[Windows Vista](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Group index of the item hit (read only). Valid only for owner data. If the point is within an item that is displayed in multiple groups then **iGroup** will specify the group index of the item.
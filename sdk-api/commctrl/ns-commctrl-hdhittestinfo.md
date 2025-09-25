# HDHITTESTINFO structure

## Description

Contains information about a hit test. This structure is used with the [HDM_HITTEST](https://learn.microsoft.com/windows/desktop/Controls/hdm-hittest) message and it supersedes the **HD_HITTESTINFO** structure.

## Members

### `pt`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

A [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that contains the point to be hit test, in client coordinates.

### `flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The variable that receives information about the results of a hit test. This member can be one or more of the values listed below. Two of these values can be combined, such as when the position is above and to the left of the client area.

| Value | Meaning |
| --- | --- |
| **HHT_ABOVE** | The point is above the header control's bounding rectangle. |
| **HHT_BELOW** | The point is below the header control's bounding rectangle. |
| **HHT_NOWHERE** | The point is inside the header control's bounding rectangle but is not over a header item. |
| **HHT_ONDIVIDER** | The point is on the divider between two header items. |
| **HHT_ONDIVOPEN** | The point is on the divider of an item that has a width of zero. Dragging the divider reveals the item instead of resizing the item to the left of the divider. |
| **HHT_ONHEADER** | The point is inside the header control's bounding rectangle. |
| **HHT_ONFILTER** | [Version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) The point is over the filter area. |
| **HHT_ONFILTERBUTTON** | [Version 5.80](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) The point is on the filter button. |
| **HHT_TOLEFT** | The point is to the left of the header control's bounding rectangle. |
| **HHT_TORIGHT** | The point is to the right of the header control's bounding rectangle. |
| **HHT_ONITEMSTATEICON** | [Version 6.00](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) and **Windows Vista.**  The point is within the state icon of the item. If style [HDS_CHECKBOXES](https://learn.microsoft.com/windows/desktop/Controls/header-control-styles) is specified, the point is within the checkbox of the item. |
| **HHT_ONDROPDOWN** | [Version 6.00](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) and **Windows Vista.** The point is within the split button of the item. The style HDF_SPLITBUTTON must be set on the item. |
| **HHT_ONOVERFLOW** | [Version 6.00](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) and **Windows Vista.** The point is within the overflow button of the header control. The style [HDS_OVERFLOW](https://learn.microsoft.com/windows/desktop/Controls/header-control-styles) must be set on the header control. |

### `iItem`

Type: **int**

If the hit test is successful, contains the index of the item at the hit test point.
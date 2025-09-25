# ListView_GetGroupRect macro

## Syntax

```cpp
BOOL ListView_GetGroupRect(
  [in]      HWND hwnd,
  [in]      int  iGroupId,
  [in]      LONG type,
  [in, out] RECT *prc
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Gets the rectangle for a specified group. Use this macro or send the [LVM_GETGROUPRECT](https://learn.microsoft.com/windows/desktop/Controls/lvm-getgrouprect) message explicitly.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `iGroupId` [in]

Type: **int**

Specifies the group by **iGroupId** (see [LVGROUP](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvgroup) structure).

### `type` [in]

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the type of rectangle to retrieve. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **LVGGR_GROUP** | Coordinates of the entire expanded group. |
| **LVGGR_HEADER** | Coordinates of the header only (collapsed group). |
| **LVGGR_LABEL** | Coordinates of the label only. |
| **LVGGR_SUBSETLINK** | Coordinates of the subset link only (markup subset). A list-view control can limit the number of visible items displayed in each group. A link is presented to the user to allow the user to expand the group. This flag will return the bounding rectangle of the subset link if the group is a subset (group state of LVGS_SUBSETED, see structure [LVGROUP](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvgroup), member **state**). This flag is provided so that accessibility applications can locate the link. |

### `prc` [in, out]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure to receive information on the group specified by *iGroupId*. The message receiver is responsible for setting the structure members with information for the group specified by *iGroupId*. The calling application is responsible for allocating memory for the structure.
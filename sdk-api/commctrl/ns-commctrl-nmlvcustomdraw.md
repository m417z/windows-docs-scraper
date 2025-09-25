# NMLVCUSTOMDRAW structure

## Description

Contains information specific to an [NM_CUSTOMDRAW (list view)](https://learn.microsoft.com/windows/desktop/Controls/nm-customdraw-list-view) notification code sent by a list-view control.

## Members

### `nmcd`

Type: **[NMCUSTOMDRAW](https://learn.microsoft.com/windows/win32/api/commctrl/ns-commctrl-nmcustomdraw)**

[NMCUSTOMDRAW](https://learn.microsoft.com/windows/win32/api/commctrl/ns-commctrl-nmcustomdraw) structure that contains general custom draw information.

### `clrText`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**COLORREF** value representing the color that will be used to display text foreground in the list-view control.

### `clrTextBk`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**COLORREF** value representing the color that will be used to display text background in the list-view control. In [Version 6.0.,](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions)  this member is ignored if the background image is set with the [LVM_SETBKIMAGE](https://learn.microsoft.com/windows/desktop/Controls/lvm-setbkimage) message.

### `iSubItem`

Type: **int**

[Version 4.71.](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) Index of the subitem that is being drawn. If the main item is being drawn, this member will be zero.

### `dwItemType`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 6.0.](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions)
**DWORD** that contains the type of the item to draw. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **LVCDI_ITEM** | An item is to be drawn. |
| **LVCDI_GROUP** | A group is to be drawn. |
| **LVCDI_ITEMSLIST** | Every item is to be drawn. |

### `clrFace`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 6.0.](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions)
**COLORREF** value representing the color that will be used to display the face of an item.

### `iIconEffect`

Type: **int**

[Version 6.0.](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions)
Value of type **int** that specifies the effect that is applied to an icon, such as Glow, Shadow, or Pulse.

### `iIconPhase`

Type: **int**

[Version 6.0.](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions)
Value of type **int** that specifies the phase of an icon.

### `iPartId`

Type: **int**

[Version 6.0.](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions)
Value of type **int** that specifies the ID of the part of an item to draw.

### `iStateId`

Type: **int**

[Version 6.0.](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions)
Value of type **int** that specifies the ID of the state of an item to draw.

### `rcText`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

[Version 6.0.](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions)
**RECT** that specifies the rectangle in which the text is to be drawn.

### `uAlign`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 6.0.](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions)
**UINT** that specifies how a group should be aligned. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **LVGA_HEADER_CENTER** | Center the group. |
| **LVGA_HEADER_LEFT** | Align the group on the left. |
| **LVGA_HEADER_RIGHT** | Align the group on the right. |

## Remarks

**Note** Comctl32.dll version 6 is not redistributable but it is included in Windows or later. To use Comctl32.dll version 6, specify it in a manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).
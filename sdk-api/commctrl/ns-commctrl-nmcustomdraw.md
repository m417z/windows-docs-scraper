# NMCUSTOMDRAW structure

## Description

Contains information specific to an [NM_CUSTOMDRAW](https://learn.microsoft.com/windows/desktop/Controls/nm-customdraw) notification code.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

An [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about this notification code.

### `dwDrawStage`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The current drawing stage. This is one of the following values.

| Value | Meaning |
| --- | --- |
| **Global Values:** |  |
| **CDDS_POSTERASE** | After the erasing cycle is complete. |
| **CDDS_POSTPAINT** | After the painting cycle is complete. |
| **CDDS_PREERASE** | Before the erasing cycle begins. |
| **CDDS_PREPAINT** | Before the painting cycle begins. |
| **Item-specific Values:** |  |
| **CDDS_ITEM** | Indicates that the **dwItemSpec**, **uItemState**, and **lItemlParam** members are valid. |
| **CDDS_ITEMPOSTERASE** | After an item has been erased. |
| **CDDS_ITEMPOSTPAINT** | After an item has been drawn. |
| **CDDS_ITEMPREERASE** | Before an item is erased. |
| **CDDS_ITEMPREPAINT** | Before an item is drawn. |
| **CDDS_SUBITEM** | Flag combined with CDDS_ITEMPREPAINT or CDDS_ITEMPOSTPAINT if a subitem is being drawn. This will only be set if [CDRF_NOTIFYITEMDRAW](https://learn.microsoft.com/windows/desktop/Controls/cdrf-constants) is returned from CDDS_PREPAINT. |

### `hdc`

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control's device context. Use this HDC to perform any GDI functions.

### `rc`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

The [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that describes the bounding rectangle of the area being drawn. This member is initialized only by the CDDS_ITEMPREPAINT notification. [Version 5.80.](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) This member is also initialized by the CDDS_PREPAINT notification.

### `dwItemSpec`

Type: **[DWORD_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The item number. What is contained in this member will depend on the type of control that is sending the notification. See the [NM_CUSTOMDRAW](https://learn.microsoft.com/windows/desktop/Controls/nm-customdraw) notification reference for the specific control to determine what, if anything, is contained in this member.

### `uItemState`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The current item state. This value is a combination of the following flags.

| Value | Meaning |
| --- | --- |
| **CDIS_CHECKED** | The item is checked. |
| **CDIS_DEFAULT** | The item is in its default state. |
| **CDIS_DISABLED** | The item is disabled. |
| **CDIS_FOCUS** | The item is in focus. |
| **CDIS_GRAYED** | The item is grayed. |
| **CDIS_HOT** | The item is currently under the pointer ("hot"). |
| **CDIS_INDETERMINATE** | The item is in an indeterminate state. |
| **CDIS_MARKED** | The item is marked. The meaning of this is determined by the implementation. |
| **CDIS_SELECTED** | The item is selected.<br><br>**Note** This flag does not work correctly for owner-drawn list-view controls that have the [LVS_SHOWSELALWAYS](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) style. For these controls, you can determine whether an item is selected by using [LVM_GETITEMSTATE](https://learn.microsoft.com/windows/desktop/Controls/lvm-getitemstate) (or [ListView_GetItemState](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_getitemstate)) and checking for the **LVIS_SELECTED** flag. |
| **CDIS_SHOWKEYBOARDCUES** | [Version 6.0.](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions)The item is showing its keyboard cues. <br><br> <br><br>Note that Comctl32 version 6 is not redistributable. operating systems. To use Comctl32.dll version 6, specify it in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview). |
| **CDIS_NEARHOT** | The item is part of a control that is currently under the mouse pointer ("hot"), but the item is not "hot" itself. The meaning of this is determined by the implementation. |
| **CDIS_OTHERSIDEHOT** | The item is part of a splitbutton that is currently under the mouse pointer ("hot"), but the item is not "hot" itself. The meaning of this is determined by the implementation. |
| **CDIS_DROPHILITED** | The item is currently the drop target of a drag-and-drop operation. |

### `lItemlParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-defined item data.

## Remarks

The value your application returns depends on the current drawing stage. The **dwDrawStage** member of the associated **NMCUSTOMDRAW** structure holds a value that specifies the drawing stage. When the **dwDrawStage** member equals CDDS_PREPAINT and CDDS_PREERASE, some controls send the CDDS_PREERASE message first and expect the return value to indicate which subsequent messages will be sent. For a code sample that illustrates states and drawing stages, see [Customizing a Control's Appearance Using Custom Draw](https://learn.microsoft.com/windows/desktop/Controls/custom-draw).
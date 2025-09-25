# LVITEMA structure

## Description

Specifies or receives the attributes of a list-view item. This structure has been updated to support a new mask value (LVIF_INDENT) that enables item indenting. This structure supersedes the **LV_ITEM** structure.

## Members

### `mask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Set of flags that specify which members of this structure contain data to be set or which members are being requested. This member can have one or more of the following flags set:

| Value | Meaning |
| --- | --- |
| **LVIF_COLFMT** | **Windows Vista and later.** The **piColFmt** member is valid or must be set. If this flag is used, the **cColumns** member is valid or must be set. |
| **LVIF_COLUMNS** | The **cColumns** member is valid or must be set. |
| **LVIF_DI_SETITEM** | The operating system should store the requested list item information and not ask for it again. This flag is used only with the [LVN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/lvn-getdispinfo) notification code. |
| **LVIF_GROUPID** | The **iGroupId** member is valid or must be set. If this flag is not set when an [LVM_INSERTITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-insertitem) message is sent, the value of **iGroupId** is assumed to be I_GROUPIDCALLBACK. |
| **LVIF_IMAGE** | The **iImage** member is valid or must be set. |
| **LVIF_INDENT** | The **iIndent** member is valid or must be set. |
| **LVIF_NORECOMPUTE** | The control will not generate [LVN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/lvn-getdispinfo) to retrieve text information if it receives an [LVM_GETITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-getitem) message. Instead, the **pszText** member will contain LPSTR_TEXTCALLBACK. |
| **LVIF_PARAM** | The **lParam** member is valid or must be set. |
| **LVIF_STATE** | The **state** member is valid or must be set. |
| **LVIF_TEXT** | The **pszText** member is valid or must be set. |

### `iItem`

Type: **int**

Zero-based index of the item to which this structure refers.

### `iSubItem`

Type: **int**

One-based index of the subitem to which this structure refers, or zero if this structure refers to an item rather than a subitem.

### `state`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Indicates the item's state, state image, and overlay image. The
**stateMask** member indicates the valid bits of this member.

Bits 0 through 7 of this member contain the item state flags. This can be one or more of the [item state](https://learn.microsoft.com/windows/desktop/Controls/list-view-item-states) values.

Bits 8 through 11 of this member specify the one-based overlay image index. Both the full-sized icon image list and the small icon image list can have overlay images. The overlay image is superimposed over the item's icon image. If these bits are zero, the item has no overlay image. To isolate these bits, use the [LVIS_OVERLAYMASK](https://learn.microsoft.com/windows/desktop/Controls/list-view-item-states) mask. To set the overlay image index in this member, you should use the [INDEXTOOVERLAYMASK](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-indextooverlaymask) macro. The image list's overlay images are set with the [ImageList_SetOverlayImage](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_setoverlayimage) function.

Bits 12 through 15 of this member specify the state image index. The state image is displayed next to an item's icon to indicate an application-defined state. If these bits are zero, the item has no state image. To isolate these bits, use the [LVIS_STATEIMAGEMASK](https://learn.microsoft.com/windows/desktop/Controls/list-view-item-states) mask. To set the state image index, use the [INDEXTOSTATEIMAGEMASK](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-indextostateimagemask) macro. The state image index specifies the index of the image in the state image list that should be drawn. The state image list is specified with the [LVM_SETIMAGELIST](https://learn.microsoft.com/windows/desktop/Controls/lvm-setimagelist) message.

### `stateMask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value specifying which bits of the
**state** member will be retrieved or modified. For example, setting this member to [LVIS_SELECTED](https://learn.microsoft.com/windows/desktop/Controls/list-view-item-states) will cause only the item's selection state to be retrieved.

This member allows you to modify one or more item states without having to retrieve all of the item states first. For example, setting this member to **LVIS_SELECTED** and **state** to zero will cause the item's selection state to be cleared, but none of the other states will be affected.

To retrieve or modify all of the states, set this member to (**UINT**)-1.

You can use the macro [ListView_SetItemState](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-listview_setitemstate) both to set and to clear bits.

### `pszText`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the structure specifies item attributes, **pszText** is a pointer to a null-terminated string containing the item text. When responding to an [LVN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/lvn-getdispinfo) notification, be sure that this pointer remains valid until after the next notification has been received.

If the structure receives item attributes, **pszText** is a pointer to a buffer that receives the item text. Note that although the list-view control allows any length string to be stored as item text, only the first 259 **TCHAR**s are displayed.

If the value of **pszText** is LPSTR_TEXTCALLBACK, the item is a [callback item](https://learn.microsoft.com/windows/desktop/Controls/list-view-controls-overview). If the callback text changes, you must explicitly set **pszText** to LPSTR_TEXTCALLBACK and notify the list-view control of the change by sending an [LVM_SETITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-setitem) or [LVM_SETITEMTEXT](https://learn.microsoft.com/windows/desktop/Controls/lvm-setitemtext) message.

Do not set **pszText** to LPSTR_TEXTCALLBACK if the list-view control has the [LVS_SORTASCENDING](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) or [LVS_SORTDESCENDING](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) style.

### `cchTextMax`

Type: **int**

Number of **TCHAR****s** in the buffer pointed to by **pszText**, including the terminating **NULL**.

This member is only used when the structure receives item attributes. It is ignored when the structure specifies item attributes. For example, **cchTextMax** is ignored during [LVM_SETITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-setitem) and [LVM_INSERTITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-insertitem). It is read-only during [LVN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/lvn-getdispinfo) and other LVN_ notifications.

**Note** Never copy more than **cchTextMax** **TCHAR****s**—where **cchTextMax** includes the terminating **NULL**—into **pszText** during an LVN_ notification, otherwise your program can fail.

### `iImage`

Type: **int**

Index of the item's icon in the control's image list. This applies to both the large and small image list. If this member is the I_IMAGECALLBACK value, the parent window is responsible for storing the index. In this case, the list-view control sends the parent an [LVN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/lvn-getdispinfo) notification code to retrieve the index when it needs to display the image.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value specific to the item. If you use the [LVM_SORTITEMS](https://learn.microsoft.com/windows/desktop/Controls/lvm-sortitems) message, the list-view control passes this value to the application-defined comparison function. You can also use the [LVM_FINDITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-finditem) message to search a list-view control for an item with a specified **lParam** value.

### `iIndent`

Type: **int**

[Version 4.70](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Number of image widths to indent the item. A single indentation equals the width of an item image. Therefore, the value 1 indents the item by the width of one image, the value 2 indents by two images, and so on. Note that this field is supported only for items. Attempting to set subitem indentation will cause the calling function to fail.

### `iGroupId`

Type: **int**

[Version 6.0](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) Identifier of the group that the item belongs to, or one of the following values.

| Value | Meaning |
| --- | --- |
| **I_GROUPIDCALLBACK** | The listview control sends the parent an [LVN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/lvn-getdispinfo) notification code to retrieve the index of the group. |
| **I_GROUPIDNONE** | The item does not belong to a group. |

### `cColumns`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 6.0](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions)  Number of data columns (subitems) to display for this item in tile view. The maximum value is 20. If this value is I_COLUMNSCALLBACK, the size of the column array and the array itself (**puColumns**) are obtained by sending a [LVN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/lvn-getdispinfo) notification.

### `puColumns`

Type: **[PUINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Version 6.0](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions)  A pointer to an array of column indices, specifying which columns are displayed for this item, and the order of those columns.

### `piColFmt`

Type: **int***

**Windows Vista:** Not implemented. **Windows 7 and later:** A pointer to an array of the following flags (alone or in combination), specifying the format of each subitem in extended tile view.

| Value | Meaning |
| --- | --- |
| **LVCFMT_LINE_BREAK** | Forces the column to wrap to the top of the next list of columns. |
| **LVCFMT_FILL** | Fills the remainder of the tile area. Might have a title. |
| **LVCFMT_WRAP** | Allows the column to wrap within the remaining space in its list of columns. |
| **LVCFMT_NO_TITLE** | Removes the title from the subitem. |
| **LVCFMT_TILE_PLACEMENTMASK** | Equivalent to a combination of LVCFMT_LINE_BREAK and LVCFMT_FILL. |

### `iGroup`

Type: **int**

[Windows Vista](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions): Group index of the item. Valid only for owner data/callback (single item in multiple groups).

## Remarks

The **LVITEM** structure is used with several messages, including [LVM_GETITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-getitem), [LVM_SETITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-setitem), [LVM_INSERTITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-insertitem), and [LVM_DELETEITEM](https://learn.microsoft.com/windows/desktop/Controls/lvm-deleteitem).

In tile view, the item name is displayed to the right of the icon. You can specify additional subitems (corresponding to columns in the details view), to be displayed on lines below the item name. The **puColumns** array contains the indices of subitems to be displayed. Indices should be greater than 0, because subitem 0, the item name, is already displayed. Column information can also be set in the [LVTILEINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvtileinfo) structure when modifying the list item.

For example code, see [Using List-View Controls](https://learn.microsoft.com/windows/desktop/Controls/using-list-view-controls).

**Note** Comctl32.dll version 6 is not redistributable but it is included in Windows or later. To use Comctl32.dll version 6, specify it in a manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).

> [!NOTE]
> The commctrl.h header defines LVITEM as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
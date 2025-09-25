# TVITEMW structure

## Description

Specifies or receives attributes of a tree-view item. This structure is identical to the
**TV_ITEM** structure, but it has been renamed to follow current naming conventions. New applications should use this structure.

## Members

### `mask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of flags that indicate which of the other structure members contain valid data. When this structure is used with the [TVM_GETITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-getitem) message, the **mask** member indicates the item attributes to retrieve. If used with the [TVM_SETITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-setitem) message, the **mask** indicates the attributes to set. This member can be one or more of the following values:

| Value | Meaning |
| --- | --- |
| **TVIF_CHILDREN** | The **cChildren** member is valid. |
| **TVIF_DI_SETITEM** | The tree-view control will retain the supplied information and will not request it again. This flag is valid only when processing the [TVN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/tvn-getdispinfo) notification. |
| **TVIF_HANDLE** | The **hItem** member is valid. |
| **TVIF_IMAGE** | The **iImage** member is valid. |
| **TVIF_PARAM** | The **lParam** member is valid. |
| **TVIF_SELECTEDIMAGE** | The **iSelectedImage** member is valid. |
| **TVIF_STATE** | The **state** and **stateMask** members are valid. |
| **TVIF_TEXT** | The **pszText** and **cchTextMax** members are valid. |

### `hItem`

Type: **HTREEITEM**

Handle to the item.

### `state`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Set of bit flags and image list indexes that indicate the item's state. When setting the state of an item, the
**stateMask** member indicates the valid bits of this member. When retrieving the state of an item, this member returns the current state for the bits indicated in the
**stateMask** member.

Bits 0 through 7 of this member contain the item state flags. For a list of possible item state flags, see [Tree-View Control Item States](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-item-states).

The overlay image is superimposed over the item's icon image. Bits 8 through 11 of this member specify the one-based overlay image index. If these bits are zero, the item has no overlay image. To isolate these bits, use the [TVIS_OVERLAYMASK](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-item-states) mask. To set the overlay image index in this member, use the [INDEXTOOVERLAYMASK](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-indextooverlaymask) macro. The image list's overlay images are set with the [ImageList_SetOverlayImage](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_setoverlayimage) function.

A state image is displayed next to an item's icon to indicate an application-defined state. Specify the state image list by sending a [TVM_SETIMAGELIST](https://learn.microsoft.com/windows/desktop/Controls/tvm-setimagelist) message. To set an item's state image, include the [TVIS_STATEIMAGEMASK](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-item-states) value in the
**stateMask** member of the **TVITEM** structure. Bits 12 through 15 of the structure's
**state** member specify the index in the state image list of the image to be drawn.

To set the state image index, use [INDEXTOSTATEIMAGEMASK](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-indextostateimagemask). This macro takes an index and sets bits 12 through 15 appropriately. To indicate that the item has no state image, set the index to zero. This convention means that image zero in the state image list cannot be used as a state image. To isolate bits 12 through 15 of the
**state** member, use the [TVIS_STATEIMAGEMASK](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-item-states) mask.

### `stateMask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Bits of the
**state** member that are valid. If you are retrieving an item's state, set the bits of the
**stateMask** member to indicate the bits to be returned in the
**state** member. If you are setting an item's state, set the bits of the
**stateMask** member to indicate the bits of the
**state** member that you want to set. To set or retrieve an item's overlay image index, set the [TVIS_OVERLAYMASK](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-item-states) bits. To set or retrieve an item's state image index, set the [TVIS_STATEIMAGEMASK](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-item-states) bits.

### `pszText`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a null-terminated string that contains the item text if the structure specifies item attributes. If this member is the LPSTR_TEXTCALLBACK value, the parent window is responsible for storing the name. In this case, the tree-view control sends the parent window a [TVN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/tvn-getdispinfo) notification code when it needs the item text for displaying, sorting, or editing and a [TVN_SETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/tvn-setdispinfo) notification code when the item text changes. If the structure is receiving item attributes, this member is the address of the buffer that receives the item text. Note that although the tree-view control allows any length string to be stored as item text, only the first 260 characters are displayed.

### `cchTextMax`

Type: **int**

Size of the buffer pointed to by the
**pszText** member, in characters. If this structure is being used to set item attributes, this member is ignored.

### `iImage`

Type: **int**

Index in the tree-view control's image list of the icon image to use when the item is in the nonselected state. If this member is the I_IMAGECALLBACK value, the parent window is responsible for storing the index. In this case, the tree-view control sends the parent a [TVN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/tvn-getdispinfo) notification code to retrieve the index when it needs to display the image.

### `iSelectedImage`

Type: **int**

Index in the tree-view control's image list of the icon image to use when the item is in the selected state. If this member is the I_IMAGECALLBACK value, the parent window is responsible for storing the index. In this case, the tree-view control sends the parent a [TVN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/tvn-getdispinfo) notification code to retrieve the index when it needs to display the image.

### `cChildren`

Type: **int**

Flag that indicates whether the item has associated child items. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **zero** | The item has no child items. |
| **one** | The item has one or more child items. |
| **I_CHILDRENCALLBACK** | The parent window keeps track of whether the item has child items. In this case, when the tree-view control needs to display the item, the control sends the parent a [TVN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/tvn-getdispinfo) notification code to determine whether the item has child items. <br><br>If the tree-view control has the [TVS_HASBUTTONS](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-styles) style, it uses this member to determine whether to display the button indicating the presence of child items. You can use this member to force the control to display the button even though the item does not have any child items inserted. This allows you to display the button while minimizing the control's memory usage by inserting child items only when the item is visible or expanded. |
| **I_CHILDRENAUTO** | [Version 6.0](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) **Intended for internal use; not recommended for use in applications.** The tree-view control automatically determines whether the item has child items. <br><br>**Note** This flag may not be supported in future versions of Comctl32.dll. Also, this flag is not defined in commctrl.h. Add the following definition to the source files of your application to use the flag: <br><br>``` #define I_CHILDRENAUTO (-2) ``` |

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value to associate with the item.

## Remarks

> [!NOTE]
> The commctrl.h header defines TVITEM as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
# NMTVDISPINFOW structure

## Description

Contains and receives display information for a tree-view item. This structure is identical to the
**TV_DISPINFO** structure, but it has been renamed to follow current naming conventions.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about this notification.

### `item`

Type: **[TVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitema)**

[TVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitema) structure that identifies and contains information about the tree-view item. The
**mask** member of the **TVITEM** structure specifies which information is being set or retrieved. It can be one or more of the following values:

| Value | Meaning |
| --- | --- |
| **TVIF_CHILDREN** | The **cChildren** member specifies, or is to receive, a value that indicates whether the item has child items. |
| **TVIF_IMAGE** | The **iImage** member specifies, or is to receive, the index of the item's nonselected icon in the image list. |
| **TVIF_SELECTEDIMAGE** | The **iSelectedImage** member specifies, or is to receive, the index of the item's selected icon in the image list. |
| **TVIF_TEXT** | The **pszText** member specifies the new item text or the address of a buffer that is to receive the item text. If the structure is receiving item text, you typically copy the text to the buffer pointed to by the **pszText** member of the [TVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitema) structure. However, you can return a string in the **pszText** member instead. If you do so, you cannot change or delete the string until the corresponding item text is deleted or until two additional [TVN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/tvn-getdispinfo) notification codes have been sent. |

## See also

**Reference**

[TVN_SETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/tvn-setdispinfo)

[WM_NOTIFY](https://learn.microsoft.com/windows/desktop/Controls/wm-notify)

## Remarks

> [!NOTE]
> The commctrl.h header defines NMTVDISPINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
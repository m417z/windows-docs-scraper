# NMTVGETINFOTIPW structure

## Description

Contains and receives tree-view item information needed to display a tooltip for an item. This structure is used with the [TVN_GETINFOTIP](https://learn.microsoft.com/windows/desktop/Controls/tvn-getinfotip) notification code.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about this notification.

### `pszText`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Address of a character buffer that contains the text to be displayed. If you want to change the text displayed in the tooltip, you will need to modify the contents of this buffer. The size of this buffer is specified by the
**cchTextMax** structure.

### `cchTextMax`

Type: **int**

Size of the buffer at
**pszText**, in characters. Although you should never assume that this buffer will be of any particular size, the INFOTIPSIZE value can be used for design purposes.

### `hItem`

Type: **HTREEITEM**

Tree handle to the item for which the tooltip is being displayed.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-defined data associated with the item for which the tooltip is being displayed.

## Remarks

> [!NOTE]
> The commctrl.h header defines NMTVGETINFOTIP as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
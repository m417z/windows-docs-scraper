# NMLVGETINFOTIPW structure

## Description

Contains and receives list-view item information needed to display a tooltip for an item. This structure is used with the [LVN_GETINFOTIP](https://learn.microsoft.com/windows/desktop/Controls/lvn-getinfotip) notification code.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information on this notification code.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Either zero or LVGIT_UNFOLDED. See Remarks.

### `pszText`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Address of a string buffer that receives any additional text information. If
**dwFlags** is zero, this member will contain the existing item text. In this case, you should append any additional text onto the end of this string. The size of this buffer is specified by the
**cchTextMax** structure.

### `cchTextMax`

Type: **int**

Size, in characters, of the buffer pointed to by
**pszText**. Although you should never assume that this buffer will be of any particular size, the INFOTIPSIZE value can be used for design purposes.

### `iItem`

Type: **int**

Zero-based index of the item to which this structure refers.

### `iSubItem`

Type: **int**

One-based index of the subitem to which this structure refers. If this member is zero, the structure is referring to the item and not a subitem. This member is not currently used and will always be zero.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-defined value associated with the item. This member is not currently used and will always be zero.

## Remarks

An item is said to be folded when the currently displayed text is truncated. If LVGIT_UNFOLDED is returned in **dwFlags**, the full text of the item is already displayed, so there is no need to display it in the tooltip.

> [!NOTE]
> The commctrl.h header defines NMLVGETINFOTIP as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
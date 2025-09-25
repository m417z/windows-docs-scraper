# NMTBDISPINFOA structure

## Description

Contains and receives display information for a toolbar item. This structure is used with the [TBN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/tbn-getdispinfo) notification code.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains additional information about the notification.

### `dwMask`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Set of flags that indicate which members of this structure are being requested. This can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **TBNF_IMAGE** | The item's image index is being requested. The image index must be placed in the **iImage** member. |
| **TBNF_TEXT** | Not currently implemented. |
| **TBNF_DI_SETITEM** | Set this flag when processing [TBN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/tbn-getdispinfo); the toolbar control will retain the supplied information and not request it again. |

### `idCommand`

Type: **int**

Command identifier of the item for which display information is being requested. This member is filled in by the control before it sends the notification code.

### `lParam`

Type: **[DWORD_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-defined value associated with the item for which display information is being requested. This member is filled in by the control before sending the notification code.

### `iImage`

Type: **int**

Image index for the item.

### `pszText`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a character buffer that receives the item's text.

### `cchText`

Type: **int**

Size of the
**pszText** buffer, in characters.

## Remarks

> [!NOTE]
> The commctrl.h header defines NMTBDISPINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
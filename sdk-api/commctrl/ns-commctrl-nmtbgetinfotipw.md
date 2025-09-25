# NMTBGETINFOTIPW structure

## Description

Contains and receives infotip information for a toolbar item. This structure is used with the [TBN_GETINFOTIP](https://learn.microsoft.com/windows/desktop/Controls/tbn-getdispinfo) notification code.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains additional information about the notification.

### `pszText`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Address of a character buffer that receives the infotip text.

### `cchTextMax`

Type: **int**

Size of the buffer, in characters, at
**pszText**. In most cases, the buffer will be INFOTIPSIZE characters in size, but you should always make sure that your application does not copy more than
**cchTextMax** characters to the buffer at
**pszText**.

### `iItem`

Type: **int**

The command identifier of the item for which infotip information is being requested. This member is filled in by the control before sending the notification code.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The application-defined value associated with the item for which infotip information is being requested. This member is filled in by the control before sending the notification code.

## Remarks

> [!NOTE]
> The commctrl.h header defines NMTBGETINFOTIP as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
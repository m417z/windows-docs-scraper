# NMTOOLBARW structure

## Description

Contains information used to process toolbar notification codes. This structure supersedes the
**TBNOTIFY** structure.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains additional information about the notification.

### `iItem`

Type: **int**

Command identifier of the button associated with the notification code.

### `tbButton`

Type: **[TBBUTTON](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tbbutton)**

[TBBUTTON](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tbbutton) structure that contains information about the toolbar button associated with the notification code. This member only contains valid information with the [TBN_QUERYINSERT](https://learn.microsoft.com/windows/desktop/Controls/tbn-queryinsert) and [TBN_QUERYDELETE](https://learn.microsoft.com/windows/desktop/Controls/tbn-querydelete) notification codes.

### `cchText`

Type: **int**

Count of characters in the button text.

### `pszText`

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Address of a character buffer that contains the button text.

### `rcButton`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

[Version 5.80.](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions) A [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that defines the area covered by the button.

## Remarks

> [!NOTE]
> The commctrl.h header defines NMTOOLBAR as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
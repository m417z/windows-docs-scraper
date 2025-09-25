# NMCBEDRAGBEGINW structure

## Description

Contains information used with the [CBEN_DRAGBEGIN](https://learn.microsoft.com/windows/desktop/Controls/cben-dragbegin) notification code.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

An [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about the notification code.

### `iItemid`

Type: **int**

The zero-based index of the item being dragged. This value will always be -1, indicating that the item being dragged is the item displayed in the edit portion of the control.

### `szText`

Type: **[TCHAR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The character buffer that contains the text of the item being dragged.

## Remarks

> [!NOTE]
> The commctrl.h header defines NMCBEDRAGBEGIN as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
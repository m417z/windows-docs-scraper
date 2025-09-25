# NMTVDISPINFOEXW structure

## Description

Contains information pertaining to extended TreeView notification information.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about this notification.

### `item`

Type: **[TVITEMEX](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitemexa)**

Specifies or receives attributes of a TreeView item.

## Remarks

> [!NOTE]
> The commctrl.h header defines NMTVDISPINFOEX as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
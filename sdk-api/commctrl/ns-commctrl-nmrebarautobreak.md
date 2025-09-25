# NMREBARAUTOBREAK structure

## Description

Contains information used with the [RBN_AUTOBREAK](https://learn.microsoft.com/windows/desktop/Controls/rbn-autobreak) notification code.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that provides additional information about this notification code.

### `uBand`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Zero-based index of the band affected by the notification. This is -1 if no band is affected.

### `wID`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-defined ID of the band.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-defined value from the **lParam** member of the [REBARBANDINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-rebarbandinfoa) structure that defines the rebar band.

### `uMsg`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

ID of the message.

### `fStyleCurrent`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Style of the specified band.

### `fAutoBreak`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**BOOL** that indicates whether a break should occur.
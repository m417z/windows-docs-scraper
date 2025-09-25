# NMREBARCHEVRON structure

## Description

Contains information used in handling the [RBN_CHEVRONPUSHED](https://learn.microsoft.com/windows/desktop/Controls/rbn-chevronpushed) notification code.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains additional information about the notification.

### `uBand`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the band sending the notification.

### `wID`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-defined identifier for the band.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-defined value associated with the band.

### `rc`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that defines the area covered by the chevron.

### `lParamNM`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An application-defined value. If the [RBN_CHEVRONPUSHED](https://learn.microsoft.com/windows/desktop/Controls/rbn-chevronpushed) notification was sent as a result of an [RB_PUSHCHEVRON](https://learn.microsoft.com/windows/desktop/Controls/rb-pushchevron) message, this member contains the message's
*lAppValue* value. Otherwise, it is set to zero.
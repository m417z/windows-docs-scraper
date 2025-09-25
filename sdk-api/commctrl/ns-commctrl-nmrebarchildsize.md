# NMREBARCHILDSIZE structure

## Description

Contains information used in handling the [RBN_CHILDSIZE](https://learn.microsoft.com/windows/desktop/Controls/rbn-childsize) notification code.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains additional information about the notification.

### `uBand`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Zero-based index of the band affected by the notification. This will be -1 if no band is affected.

### `wID`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-defined identifier of the band.

### `rcChild`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the new size of the child window. This member can be changed during the notification to modify the child window's position and size.

### `rcBand`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the new size of the band.
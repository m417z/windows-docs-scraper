# NMTTCUSTOMDRAW structure

## Description

Contains information specific to an [NM_CUSTOMDRAW](https://learn.microsoft.com/windows/desktop/Controls/nm-customdraw-tooltip) notification code sent by a tooltip control.

## Members

### `nmcd`

Type: **[NMCUSTOMDRAW](https://learn.microsoft.com/windows/win32/api/commctrl/ns-commctrl-nmcustomdraw)**

Contains general custom draw information.

### `uDrawFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies how tooltip text will be formatted when it is displayed. An application may change this field to alter the way text is drawn. This value is passed to the [DrawText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawtext) function internally. All values for the
*uFormat* parameter of **DrawText** are valid.
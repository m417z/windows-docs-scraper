# NMRBAUTOSIZE structure

## Description

Contains information used in handling the [RBN_AUTOSIZE](https://learn.microsoft.com/windows/desktop/Controls/rbn-autosize) notification codes.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains additional information about the notification.

### `fChanged`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Member that indicates if the size or layout of the rebar control has changed (nonzero if a change occurred or zero otherwise).

### `rcTarget`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the rectangle to which the rebar control tried to size itself.

### `rcActual`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the rectangle to which the rebar control actually sized itself.
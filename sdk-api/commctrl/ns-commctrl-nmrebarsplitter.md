# NMREBARSPLITTER structure

## Description

Contains information used to handle an [RBN_SPLITTERDRAG](https://learn.microsoft.com/windows/desktop/Controls/rbn-splitterdrag) notification code.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

An [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains additional information about this notification.

### `rcSizing`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

An [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that indicates the size the rebar will be after the drag operation completes.
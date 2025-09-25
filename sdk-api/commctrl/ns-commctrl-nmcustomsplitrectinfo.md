# NMCUSTOMSPLITRECTINFO structure

## Description

Contains information about the two rectangles of a split button. Sent with the [NM_GETCUSTOMSPLITRECT](https://learn.microsoft.com/windows/desktop/Controls/nm-getcustomsplitrect) notification.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

An [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about the notification.

### `rcClient`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

A [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that describes the client area the button occupies.

### `rcButton`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

A [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that describes the rectangle that does not contain the drop-down arrow.

### `rcSplit`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

A [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that describes the rectangle that contains the drop-down arrow.

## Remarks

This information is used to draw the button. The button must be of style [BS_SPLITBUTTON](https://learn.microsoft.com/windows/desktop/Controls/button-styles) or [BS_DEFSPLITBUTTON](https://learn.microsoft.com/windows/desktop/Controls/button-styles)
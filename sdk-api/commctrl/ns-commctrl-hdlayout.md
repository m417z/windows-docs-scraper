# HDLAYOUT structure

## Description

Contains information used to set the size and position of a header control. **HDLAYOUT** is used with the [HDM_LAYOUT](https://learn.microsoft.com/windows/desktop/Controls/hdm-layout) message. This structure supersedes the
**HD_LAYOUT** structure.

## Members

### `prc`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Structure that contains the coordinates of a rectangle that the header control will occupy.

### `pwpos`

Type: **[WINDOWPOS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-windowpos)***

Structure that receives information about the appropriate size and position of the header control.
# MINIMIZEDMETRICS structure

## Description

Contains the scalable metrics associated with minimized windows. This structure is used with the
[SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) function when the SPI_GETMINIMIZEDMETRICS or SPI_SETMINIMIZEDMETRICS action value is specified.

## Members

### `cbSize`

The size of the structure, in bytes. The caller must set this to `sizeof(MINIMIZEDMETRICS)`.

### `iWidth`

The width of minimized windows, in pixels.

### `iHorzGap`

The horizontal space between arranged minimized windows, in pixels.

### `iVertGap`

The vertical space between arranged minimized windows, in pixels.

### `iArrange`

The starting position and direction used when arranging minimized windows. The starting position must be one of the following values.

| Value | Meaning |
| --- | --- |
| **ARW_BOTTOMLEFT**<br><br>0x0000L | Start at the lower-left corner of the work area. |
| **ARW_BOTTOMRIGHT**<br><br>0x0001L | Start at the lower-right corner of the work area. |
| **ARW_TOPLEFT**<br><br>0x0002L | Start at the upper-left corner of the work area. |
| **ARW_TOPRIGHT**<br><br>0x0003L | Start at the upper-right corner of the work area. |

The direction must be one of the following values.

| Value | Meaning |
| --- | --- |
| **ARW_LEFT**<br><br>0x0000L | Arrange left (valid with ARW_BOTTOMRIGHT and ARW_TOPRIGHT only). |
| **ARW_RIGHT**<br><br>0x0000L | Arrange right (valid with ARW_BOTTOMLEFT and ARW_TOPLEFT only). |
| **ARW_UP**<br><br>0x0004L | Arrange up (valid with ARW_BOTTOMLEFT and ARW_BOTTOMRIGHT only). |
| **ARW_DOWN**<br><br>0x0004L | Arrange down (valid with ARW_TOPLEFT and ARW_TOPRIGHT only). |
| **ARW_HIDE**<br><br>0x0008L | Hide minimized windows by moving them off the visible area of the screen. |

## See also

[SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa)
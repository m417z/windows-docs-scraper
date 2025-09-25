# EMRSETDIBITSTODEVICE structure

## Description

The **EMRSETDIBITSTODEVICE** structure contains members for the [SetDIBitsToDevice](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibitstodevice) enhanced metafile record.

## Members

### `emr`

The base structure for all record types.

### `rclBounds`

Bounding rectangle, in device units.

### `xDest`

Logical x-coordinate of the upper-left corner of the destination rectangle.

### `yDest`

Logical y-coordinate of the upper-left corner of the destination rectangle.

### `xSrc`

Logical x-coordinate of the lower-left corner of the source device-independent bitmap (DIB).

### `ySrc`

Logical y-coordinate of the lower-left corner of the source DIB.

### `cxSrc`

Width of the source rectangle, in logical units.

### `cySrc`

Height of the source rectangle, in logical units.

### `offBmiSrc`

Offset to the source [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure.

### `cbBmiSrc`

Size of the source [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure.

### `offBitsSrc`

Offset to source bitmap bits.

### `cbBitsSrc`

Size of source bitmap bits.

### `iUsageSrc`

Value of the **bmiColors** member of the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure. The **iUsageSrc** member can be either the DIB_PAL_COLORS or DIB_RGB_COLORS value.

### `iStartScan`

First scan line in the array.

### `cScans`

Number of scan lines.

## See also

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[SetDIBitsToDevice](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibitstodevice)
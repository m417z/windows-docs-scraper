# ICDRAWBEGIN structure

## Description

The **ICDRAWBEGIN** structure contains decompression parameters used with the [ICM_DRAW_BEGIN](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-begin) message.

## Members

### `dwFlags`

Applicable flags. The following values are defined:

| Name | Description |
| --- | --- |
| **ICDRAW_ANIMATE** | Application can animate the palette. |
| **ICDRAW_BUFFER** | Buffers this data off-screen; it will need to be updated. |
| **ICDRAW_CONTINUE** | Drawing is a continuation of the previous frame. |
| **ICDRAW_FULLSCREEN** | Draws the decompressed data on the full screen. |
| **ICDRAW_HDC** | Draws the decompressed data to a window or a DC. |
| **ICDRAW_MEMORYDC** | DC is off-screen. |
| **ICDRAW_QUERY** | Determines if the decompressor can handle the decompression. The driver does not actually decompress the data. |
| **ICDRAW_RENDER** | Renders but does not draw the data. |
| **ICDRAW_UPDATING** | Current frame is being updated rather than played. |

### `hpal`

Handle to the palette used for drawing.

### `hwnd`

Handle to the window used for drawing.

### `hdc`

Handle to the DC used for drawing. Specify **NULL** to use a DC associated with the specified window.

### `xDst`

The x-coordinate of the destination rectangle.

### `yDst`

The y-coordinate of the destination rectangle.

### `dxDst`

Width of the destination rectangle.

### `dyDst`

Height of the destination rectangle.

### `lpbi`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure containing the input format.

### `xSrc`

The x-coordinate of the source rectangle.

### `ySrc`

The y-coordinate of the source rectangle.

### `dxSrc`

Width of the source rectangle.

### `dySrc`

Height of the source rectangle.

### `dwRate`

Decompression rate in an integer format. To obtain the rate in frames per second, divide this value by the value in **dwScale**.

### `dwScale`

Value used to scale **dwRate** to frames per second.

## See also

[ICM_DRAW_BEGIN](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-begin)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)

[Video Compression Structures](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-structures)
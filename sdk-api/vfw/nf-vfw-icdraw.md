# ICDraw function

## Description

The **ICDraw** function decompresses an image for drawing.

## Parameters

### `hic`

Handle to a decompressor.

### `dwFlags`

Decompression flags. The following values are defined.

| Value | Meaning |
| --- | --- |
| **ICDRAW_HURRYUP** | Data is buffered and not drawn to the screen. Use this flag for fastest decompression. |
| **ICDRAW_NOTKEYFRAME** | Current frame is not a key frame. |
| **ICDRAW_NULLFRAME** | Current frame does not contain any data and the previous frame should be redrawn. |
| **ICDRAW_PREROLL** | Current frame of video occurs before playback should start. For example, if playback will begin on frame 10, and frame 0 is the nearest previous key frame, frames 0 through 9 are sent to the driver with the **ICDRAW_PREROLL** flag set. The driver needs this data to display frame 10 properly. |
| **ICDRAW_UPDATE** | Updates the screen based on previously received data. Set *lpData* to **NULL** when this flag is used. |

### `lpFormat`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure containing the input format of the data.

### `lpData`

Pointer to the input data.

### `cbData`

Size of the input data, in bytes.

### `lTime`

Time, in samples, to draw this frame. The units for video data are frames. For a definition of the playback rate, see the **dwRate** and **dwScale** members of the [ICDRAWBEGIN](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-icdrawbegin) structure.

## Return value

Returns **ICERR_OK** if successful or an error otherwise.

## Remarks

You can initiate drawing the frames by sending the [ICM_DRAW_START](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw-start) message (or by using the [ICDrawStart](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icdrawstart) macro). The application should be sure to buffer the required number of frames before drawing is started. Send the **KM_GETBUFFERSWANTED** message (or use the [ICGetBuffersWanted](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icgetbufferswanted) macro) to obtain this value.

## See also

[Video Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-functions)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
# ICDRAW structure

## Description

The **ICDRAW** structure contains parameters for drawing video data to the screen. This structure is used with the [ICM_DRAW](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw) message.

## Members

### `dwFlags`

Flags from the AVI file index. The following values are defined:

| Name | Description |
| --- | --- |
| **ICDRAW_HURRYUP** | Data is buffered and not drawn to the screen. Use this flag for fastest decompression. |
| **ICDRAW_NOTKEYFRAME** | Current frame is not a key frame. |
| **ICDRAW_NULLFRAME** | Current frame does not contain any data, and the previous frame should be redrawn. |
| **ICDRAW_PREROLL** | Current frame of video occurs before playback should start. For example, if playback will begin on frame 10, and frame 0 is the nearest previous key frame, frames 0 through 9 are sent to the driver with this flag set. The driver needs this data to display frame 10 properly. |
| **ICDRAW_UPDATE** | Updates the screen based on data previously received. In this case, **lpData** should be ignored. |

### `lpFormat`

Pointer to a structure containing the data format. For video streams, this is a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure.

### `lpData`

Pointer to the data to render.

### `cbData`

Number of data bytes to render.

### `lTime`

Time, in samples, when this data should be drawn. For video data this is normally a frame number.

## See also

[ICM_DRAW](https://learn.microsoft.com/windows/desktop/Multimedia/icm-draw)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)

[Video Compression Structures](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-structures)
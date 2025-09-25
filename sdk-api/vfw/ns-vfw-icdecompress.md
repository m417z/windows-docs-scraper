# ICDECOMPRESS structure

## Description

The **ICDECOMPRESS** structure contains decompression parameters used with the [ICM_DECOMPRESS](https://learn.microsoft.com/windows/desktop/Multimedia/icm-decompress) message.

## Members

### `dwFlags`

Applicable flags. The following values are defined:

| Name | Description |
| --- | --- |
| **ICDECOMPRESS_HURRYUP** | Tries to decompress at a faster rate. When an application uses this flag, the driver should buffer the decompressed data but not draw the image. |
| **ICDECOMPRESS_NOTKEYFRAME** | Current frame is not a key frame. |
| **ICDECOMPRESS_NULLFRAME** | Current frame does not contain data and the decompressed image should be left the same. |
| **ICDECOMPRESS_PREROLL** | Current frame precedes the point in the movie where playback starts and, therefore, will not be drawn. |
| **ICDECOMPRESS_UPDATE** | Screen is being updated or refreshed. |

### `lpbiInput`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure containing the input format.

### `lpInput`

Pointer to a buffer containing the input data.

### `lpbiOutput`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure containing the output format.

### `lpOutput`

Pointer to a buffer where the driver should write the decompressed image.

### `ckid`

Chunk identifier from the AVI file.

## See also

[BITMAPINFOHEADER](https://learn.microsoft.com/previous-versions//ms532290(v=vs.85))

[ICM_DECOMPRESS](https://learn.microsoft.com/windows/desktop/Multimedia/icm-decompress)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)

[Video Compression Structures](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-structures)
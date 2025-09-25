# ICDECOMPRESSEX structure

## Description

The **ICDECOMPRESSEX** structure contains decompression parameters used with the [ICM_DECOMPRESSEX](https://learn.microsoft.com/windows/desktop/Multimedia/icm-decompressex) message

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

### `lpbiSrc`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/previous-versions//ms532290(v=vs.85)) structure containing the input format.

### `lpSrc`

Pointer to a buffer containing the input data.

### `lpbiDst`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/previous-versions//ms532290(v=vs.85)) structure containing the output format.

### `lpDst`

Pointer to a buffer where the driver should write the decompressed image.

### `xDst`

The x-coordinate of the destination rectangle within the DIB specified by **lpbiDst**.

### `yDst`

The y-coordinate of the destination rectangle within the DIB specified by **lpbiDst**.

### `dxDst`

Width of the destination rectangle.

### `dyDst`

Height of the destination rectangle.

### `xSrc`

The x-coordinate of the source rectangle within the DIB specified by **lpbiSrc**.

### `ySrc`

The y-coordinate of the source rectangle within the DIB specified by **lpbiSrc**.

### `dxSrc`

Width of the source rectangle.

### `dySrc`

Height of the source rectangle.

## See also

[BITMAPINFOHEADER](https://learn.microsoft.com/previous-versions//ms532290(v=vs.85))

[ICM_DECOMPRESSEX](https://learn.microsoft.com/windows/desktop/Multimedia/icm-decompressex)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)

[Video Compression Structures](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-structures)
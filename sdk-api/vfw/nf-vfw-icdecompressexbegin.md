# ICDecompressExBegin function

## Description

The **ICDecompressExBegin** function prepares a decompressor for decompressing data.

## Parameters

### `hic`

Handle to the decompressor to use.

### `dwFlags`

Decompression flags. The following values are defined.

| Value | Meaning |
| --- | --- |
| **ICDECOMPRESS_HURRYUP** | Tries to decompress at a faster rate. When an application uses this flag, the driver should buffer the decompressed data but not draw the image. |
| **ICDECOMPRESS_NOTKEYFRAME** | Current frame is not a key frame. |
| **ICDECOMPRESS_NULLFRAME** | Current frame does not contain data and the decompressed image should be left the same. |
| **ICDECOMPRESS_PREROLL** | Current frame precedes the point in the movie where playback starts and, therefore, will not be drawn. |
| **ICDECOMPRESS_UPDATE** | Screen is being updated or refreshed. |

### `lpbiSrc`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure containing the format of the compressed data.

### `lpSrc`

Pointer to the input data.

### `xSrc`

The x-coordinate of the source rectangle for the DIB specified by *lpbiSrc*.

### `ySrc`

The y-coordinate of the source rectangle for the DIB specified by *lpbiSrc*.

### `dxSrc`

Width of the source rectangle.

### `dySrc`

Height of the source rectangle.

### `lpbiDst`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure containing the output format.

### `lpDst`

Pointer to a buffer that is large enough to contain the decompressed data.

### `xDst`

The x-coordinate of the destination rectangle for the DIB specified by *lpbiDst*.

### `yDst`

The y-coordinate of the destination rectangle for the DIB specified by *lpbiDst*.

### `dxDst`

Width of the destination rectangle.

### `dyDst`

Height of the destination rectangle.

## Return value

Returns **ICERR_OK** if successful or an error otherwise.

## See also

[Video Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-functions)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
# ICDecompressExQuery function

## Description

The **ICDecompressExQuery** function determines if a decompressor can decompress data with a specific format.

## Parameters

### `hic`

Handle to the decompressor to use.

### `dwFlags`

Reserved; do not use.

### `lpbiSrc`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure containing the format of the compressed data to decompress.

### `lpSrc`

Reserved; must be **NULL**.

### `xSrc`

The x-coordinate of the source rectangle for the DIB specified by *lpbiSrc*.

### `ySrc`

The y-coordinate of the source rectangle for the DIB specified by *lpbiSrc*.

### `dxSrc`

Width of the source rectangle.

### `dySrc`

Height of the source rectangle.

### `lpbiDst`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure containing the output format. If the value of this parameter is **NULL**, the function determines whether the input format is supported and this parameter is ignored.

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
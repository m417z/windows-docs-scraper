# ICGetDisplayFormat function

## Description

The **ICGetDisplayFormat** function determines the best format available for displaying a compressed image. The function also opens a compressor if a handle of an open compressor is not specified.

## Parameters

### `hic`

Handle to the compressor to use. Specify **NULL** to have VCM select and open an appropriate compressor.

### `lpbiIn`

Pointer to [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure containing the compressed format.

### `lpbiOut`

Pointer to a buffer to return the decompressed format. The buffer should be large enough for a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure and 256 color entries.

### `BitDepth`

Preferred bit depth, if nonzero.

### `dx`

Width multiplier to stretch the image. If this parameter is zero, that dimension is not stretched.

### `dy`

Height multiplier to stretch the image. If this parameter is zero, that dimension is not stretched.

## Return value

Returns a handle to a decompressor if successful or zero otherwise.

## See also

[Video Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-functions)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
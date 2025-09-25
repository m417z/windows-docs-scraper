# ICImageCompress function

## Description

The **ICImageCompress** function compresses an image to a given size. This function does not require initialization functions.

## Parameters

### `hic`

Handle to a compressor opened with the [ICOpen](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icopen) function. Specify **NULL** to have VCM select an appropriate compressor for the compression format. An application can have the user select the compressor by using the [ICCompressorChoose](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressorchoose) function, which opens the selected compressor and returns a handle of the compressor in this parameter.

### `uiFlags`

Reserved; must be zero.

### `lpbiIn`

Pointer to the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure containing the input data format.

### `lpBits`

Pointer to input data bits to compress. The data bits exclude header and format information.

### `lpbiOut`

Pointer to the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure containing the compressed output format. Specify **NULL** to have the compressor use an appropriate format.

### `lQuality`

Quality value used by the compressor. Values range from 0 to 10,000.

### `plSize`

Maximum size desired for the compressed image. The compressor might not be able to compress the data to fit within this size. When the function returns, this parameter points to the size of the compressed image. Image sizes are specified in bytes.

## Return value

Returns a handle to a compressed DIB. The image data follows the format header.

## Remarks

To obtain the format information from the [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure, use the [GlobalLock](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-globallock) function to lock the data. Use the [GlobalFree](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-globalfree) function to free the DIB when you are finished.

## See also

[Video Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-functions)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
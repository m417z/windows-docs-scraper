# ICImageDecompress function

## Description

The **ICImageDecompress** function decompresses an image without using initialization functions.

## Parameters

### `hic`

Handle to a decompressor opened with the [ICOpen](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icopen) function. Specify **NULL** to have VCM select an appropriate decompressor for the compressed image.

### `uiFlags`

Reserved; must be zero.

### `lpbiIn`

Compressed input data format.

### `lpBits`

Pointer to input data bits to compress. The data bits exclude header and format information.

### `lpbiOut`

Decompressed output format. Specify **NULL** to let decompressor use an appropriate format.

## Return value

Returns a handle to an uncompressed DIB in the CF_DIB format if successful or **NULL** otherwise. Image data follows the format header.

## Remarks

To obtain the format information from the **LPBITMAPINFOHEADER** structure, use the **GlobalLock** function to lock the data. Use the **GlobalFree** function to free the DIB when you are finished.

## See also

[Video Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-functions)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
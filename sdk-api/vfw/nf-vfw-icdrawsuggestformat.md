# ICDrawSuggestFormat function

## Description

The **ICDrawSuggestFormat** function notifies the drawing handler to suggest the input data format.

## Parameters

### `hic`

Handle to the driver to use.

### `lpbiIn`

Pointer to a structure containing the format of the compressed data. For bitmaps, this is a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure.

### `lpbiOut`

Pointer to a structure to return the suggested format. The drawing handler can receive and draw data from this format. For bitmaps, this is a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure.

### `dxSrc`

Width of the source rectangle.

### `dySrc`

Height of the source rectangle.

### `dxDst`

Width of the destination rectangle.

### `dyDst`

Height of the destination rectangle.

### `hicDecomp`

Decompressor that can use the format of data in *lpbiIn*.

## Return value

Returns **ICERR_OK** if successful or an error otherwise.

## Remarks

Applications can use this function to determine alternative input formats that a drawing handler can decompress and if the drawing handler can stretch data. If the drawing handler cannot stretch data as requested, the application might have to stretch the data.

If the drawing handler cannot decompress a format provided by an application, use the [ICDecompress](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icdecompress), [ICDecompressEx](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icdecompressex), j, [ICDecompressExQuery](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icdecompressexquery), and [ICDecompressOpen](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icdecompressopen) functions to obtain alternate formats.

## See also

[ICDecompressEx](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icdecompressex)

[ICDecompressExBegin](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icdecompressexbegin)

[ICDecompressExQuery](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icdecompressexquery)

[Video Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-functions)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
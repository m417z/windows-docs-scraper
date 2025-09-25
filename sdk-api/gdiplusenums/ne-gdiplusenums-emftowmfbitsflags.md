# EmfToWmfBitsFlags enumeration

## Description

Specifies options for the [Metafile::EmfToWmfBits](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-metafile-emftowmfbits) method, which converts an Enhanced Metafile (EMF) metafile to a Windows Metafile Format (WMF) metafile.

## Constants

### `EmfToWmfBitsFlagsDefault:0x00000000`

Specifies the default conversion.

### `EmfToWmfBitsFlagsEmbedEmf:0x00000001`

Specifies that the source EMF metafile is embedded as a comment in the resulting WMF metafile.

### `EmfToWmfBitsFlagsIncludePlaceable:0x00000002`

Specifies that the resulting WMF metafile is in the placeable metafile format; that is, it has the additional 22-byte header required by a placeable metafile.

### `EmfToWmfBitsFlagsNoXORClip:0x00000004`

Specifies that the clipping region is stored in the metafile in the traditional way. If you do not set this flag, the [Metafile::EmfToWmfBits](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-metafile-emftowmfbits) method applies an optimization that stores the clipping region as a path and simulates clipping by using the XOR operator.

## See also

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[Metafile::EmfToWmfBits](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-metafile-emftowmfbits)
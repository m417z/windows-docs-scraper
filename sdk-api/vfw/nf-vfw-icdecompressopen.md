# ICDecompressOpen macro

## Syntax

```cpp
HIC ICDecompressOpen(
    DWORD fccType,
    DWORD fccHandler,
    LPBITMAPINFOHEADER lpbiIn,
    LPBITMAPINFOHEADER lpbiOut
);
```

## Return value

Type: **HIC**

Returns a handle of a decompressor if successful or zero otherwise.

## Description

The **ICDecompressOpen** macro opens a decompressor that is compatible with the specified formats.

## Parameters

### `fccType`

Four-character code indicating the type of compressor to open. For video streams, the value of this parameter is "VIDC" or ICTYPE_VIDEO.

### `fccHandler`

Four-character code indicating the preferred stream handler to use. Typically, this information is stored in the stream header in an AVI file.

### `lpbiIn`

Pointer to a structure defining the input format. A decompressor handle is not returned unless it can decompress this format. For bitmaps, this parameter refers to a BITMAPINFOHEADER structure.

### `lpbiOut`

Pointer to a structure defining an optional decompression format. You can also specify zero to use the default output format associated with the input format.

If this parameter is nonzero, a compressor handle is not returned unless it can create this output format. For bitmaps, this parameter refers to a BITMAPINFOHEADER structure.

## Remarks

The **ICDecompressOpen** macro is defined as follows:

```cpp

#define ICDecompressOpen(fccType, fccHandler, lpbiIn, lpbiOut) \
    ICLocate(fccType, fccHandler, lpbiIn, lpbiOut, ICMODE_DECOMPRESS);

```

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
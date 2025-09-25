# ICDecompressGetFormat macro

## Syntax

```cpp
DWORD ICDecompressGetFormat(
     hic,
     lpbiInput,
     lpbiOutput
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If _lpbiOutput_ is zero, returns the size of the structure.If _lpbiOutput_ is nonzero, returns ICERR_OK if successful or an error otherwise.

## Description

The **ICDecompressGetFormat** macro requests the output format of the decompressed data from a video decompression driver. You can use this macro or explicitly call the [ICM_DECOMPRESS_GET_FORMAT](https://learn.microsoft.com/windows/desktop/Multimedia/icm-decompress-get-format) message.

## Parameters

### `hic`

Handle to a decompressor.

### `lpbiInput`

Pointer to a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure containing the input format.

### `lpbiOutput`

Pointer to a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure to contain the output format. You can specify zero to request only the size of the output format, as in the [ICDecompressGetFormatSize](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icdecompressgetformatsize) macro.

## Remarks

If *lpbiOutput* is nonzero, the driver should fill the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure with the default output format corresponding to the input format specified for *lpbiInput*. If the compressor can produce several formats, the default format should be the one that preserves the greatest amount of information.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
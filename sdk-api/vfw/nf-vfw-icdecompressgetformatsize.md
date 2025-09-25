# ICDecompressGetFormatSize macro

## Syntax

```cpp
DWORD ICDecompressGetFormatSize(
     hic,
     lpbi
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the size of the structure.

## Description

The **ICDecompressGetFormatSize** macro requests the size of the output format of the decompressed data from a video decompression driver. You can use this macro or explicitly call the [ICM_DECOMPRESS_GET_FORMAT](https://learn.microsoft.com/windows/desktop/Multimedia/icm-decompress-get-format) message.

## Parameters

### `hic`

Handle to a decompressor.

### `lpbi`

Pointer to a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure containing the input format.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
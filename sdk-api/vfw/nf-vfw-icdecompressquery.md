# ICDecompressQuery macro

## Syntax

```cpp
DWORD ICDecompressQuery(
     hic,
     lpbiInput,
     lpbiOutput
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if the specified decompression is supported or ICERR_BADFORMAT otherwise.

## Description

The **ICDecompressQuery** macro queries a video decompression driver to determine if it supports a specific input format or if it can decompress a specific input format to a specific output format. You can use this macro or explicitly call the [ICM_DECOMPRESS_QUERY](https://learn.microsoft.com/windows/desktop/Multimedia/icm-decompress-query) message.

## Parameters

### `hic`

Handle to a decompressor.

### `lpbiInput`

Pointer to a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure containing the input format.

### `lpbiOutput`

Pointer to a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure containing the output format. You can specify zero for this parameter to indicate any output format is acceptable.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
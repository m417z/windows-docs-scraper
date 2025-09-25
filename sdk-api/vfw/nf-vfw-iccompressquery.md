# ICCompressQuery macro

## Syntax

```cpp
DWORD ICCompressQuery(
     hic,
     lpbiInput,
     lpbiOutput
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if the specified compression is supported or ICERR_BADFORMAT otherwise.

## Description

The **ICCompressQuery** macro queries a video compression driver to determine if it supports a specific input format or if it can compress a specific input format to a specific output format. You can use this macro or explicitly call the [ICM_COMPRESS_QUERY](https://learn.microsoft.com/windows/desktop/Multimedia/icm-compress-query) message.

## Parameters

### `hic`

Handle to a compressor.

### `lpbiInput`

Pointer to a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure containing the input format.

### `lpbiOutput`

Pointer to a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure containing the output format. You can specify zero for this parameter to indicate any output format is acceptable.

## Remarks

When a driver receives this message, it should examine the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure associated with *lpbiInput* to determine if it can compress the input format.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
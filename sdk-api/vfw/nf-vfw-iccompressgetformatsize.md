# ICCompressGetFormatSize macro

## Syntax

```cpp
DWORD ICCompressGetFormat(
     hic,
     lpbi
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the size of the structure.

## Description

The **ICCompressGetFormatSize** macro requests the size of the output format of the compressed data from a video compression driver. You can use this macro or explicitly call the [ICM_COMPRESS_GET_FORMAT](https://learn.microsoft.com/windows/desktop/Multimedia/icm-compress-get-format) message.

## Parameters

### `hic`

Handle of the compressor.

### `lpbi`

Pointer to a **BITMAPINFO** structure containing the input format.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
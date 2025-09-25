# ICCompressGetFormat macro

## Syntax

```cpp
DWORD ICCompressGetFormat(
     hic,
     lpbiInput,
     lpbiOutput
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If _lpbiOutput_ is zero, returns the size of the structure. If _lpbiOutput_ is nonzero, returns ICERR_OK if successful or an error otherwise.

## Description

The **ICCompressGetFormat** macro requests the output format of the compressed data from a video compression driver. You can use this macro or explicitly call the [ICM_COMPRESS_GET_FORMAT](https://learn.microsoft.com/windows/desktop/Multimedia/icm-compress-get-format) message.

## Parameters

### `hic`

Handle of the compressor.

### `lpbiInput`

Pointer to a BITMAPINFO structure containing the input format.

### `lpbiOutput`

Pointer to a BITMAPINFO structure containing the output format.

## Remarks

If *lpbiOutput* is nonzero, the driver should fill the **BITMAPINFO** structure with the default output format corresponding to the input format specified for *lpbiInput*. If the compressor can produce several formats, the default format should be the one that preserves the greatest amount of information.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
# ICCompressGetSize macro

## Syntax

```cpp
DWORD ICCompressGetSize(
     hic,
     lpbiInput,
     lpbiOutput
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the maximum number of bytes a single compressed frame can occupy.

## Description

The **ICCompressGetSize** macro requests that the video compression driver supply the maximum size of one frame of data when compressed into the specified output format. You can use this macro or explicitly call the [ICM_COMPRESS_GET_SIZE](https://learn.microsoft.com/windows/desktop/Multimedia/icm-compress-get-size) message.

## Parameters

### `hic`

Handle to a compressor.

### `lpbiInput`

Pointer to a BITMAPINFO structure containing the input format.

### `lpbiOutput`

Pointer to a BITMAPINFO structure containing the output format.

## Remarks

Typically, applications send this message to determine how large a buffer to allocate for the compressed frame.

The driver should calculate the size of the largest possible frame based on the input and output formats.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
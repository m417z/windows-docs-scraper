# ICCompressBegin macro

## Syntax

```cpp
DWORD ICCompressBegin(
     hic,
     lpbiInput,
     lpbiOutput
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if the specified compression is supported or ICERR_BADFORMAT if the input or output format is not supported.

## Description

The ICCompressBegin macro notifies a video compression driver to prepare to compress data. You can use this macro or explicitly call the [ICM_COMPRESS_BEGIN](https://learn.microsoft.com/windows/desktop/Multimedia/icm-compress-begin) message.

## Parameters

### `hic`

Handle to a compressor.

### `lpbiInput`

Pointer to a [BITMAPINFO](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure containing the input format.

### `lpbiOutput`

Pointer to a [BITMAPINFO](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) structure containing the output format.

## Remarks

The driver should allocate and initialize any tables or memory that it needs for compressing the data formats when it receives the [ICM_COMPRESS](https://learn.microsoft.com/windows/desktop/Multimedia/icm-compress) message.

VCM saves the settings of the most recent **ICCompressBegin** macro. The **ICCompressBegin** and **ICCompressEnd** messages do not nest. If your driver receives **ICM_COMPRESS_BEGIN** before compression is stopped with **ICM_COMPRESS_END**, it should restart compression with new parameters.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
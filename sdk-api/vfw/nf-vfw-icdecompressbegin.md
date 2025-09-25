# ICDecompressBegin macro

## Syntax

```cpp
DWORD ICDecompressBegin(
     hic,
     lpbiInput,
     lpbiOutput
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if the specified decompression is supported or ICERR_BADFORMAT otherwise.

## Description

The **ICDecompressBegin** macro notifies a video decompression driver to prepare to decompress data. You can use this macro or explicitly call the [ICM_DECOMPRESS_BEGIN](https://learn.microsoft.com/windows/desktop/Multimedia/icm-decompress-begin) message.

## Parameters

### `hic`

Handle to a decompressor.

### `lpbiInput`

Pointer to a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure containing the input format.

### `lpbiOutput`

Pointer to a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure containing the output format.

## Remarks

When the driver receives this message, it should allocate buffers and do any time-consuming operations so that it can process [ICM_DECOMPRESS](https://learn.microsoft.com/windows/desktop/Multimedia/icm-decompress) messages efficiently.

The **ICDecompressBegin** and [ICDecompressEnd](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icdecompressend) macros do not nest. If your driver receives [ICM_DECOMPRESS_BEGIN](https://learn.microsoft.com/windows/desktop/Multimedia/icm-decompress-begin) before decompression is stopped with [ICM_DECOMPRESS_END](https://learn.microsoft.com/windows/desktop/Multimedia/icm-decompress-end), it should restart decompression with new parameters.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
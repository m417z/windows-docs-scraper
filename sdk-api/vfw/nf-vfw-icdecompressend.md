# ICDecompressEnd macro

## Syntax

```cpp
DWORD ICDecompressEnd(
     hic
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if successful or an error otherwise.

## Description

The **ICDecompressEnd** macro notifies a video decompression driver to end decompression and free resources allocated for decompression. You can use this macro or explicitly call the [ICM_DECOMPRESS_END](https://learn.microsoft.com/windows/desktop/Multimedia/icm-decompress-end) message.

## Parameters

### `hic`

Handle to a decompressor.

## Remarks

The driver should free any resources allocated for the [ICM_DECOMPRESS_BEGIN](https://learn.microsoft.com/windows/desktop/Multimedia/icm-decompress-begin) message.

The [ICDecompressBegin](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icdecompressbegin) and **ICDecompressEnd** macros do not nest. If your driver receives [ICM_DECOMPRESS_BEGIN](https://learn.microsoft.com/windows/desktop/Multimedia/icm-decompress-begin) before decompression is stopped with [ICM_DECOMPRESS_END](https://learn.microsoft.com/windows/desktop/Multimedia/icm-decompress-end), it should restart decompression with new parameters.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
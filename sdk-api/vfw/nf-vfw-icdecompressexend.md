# ICDecompressExEnd macro

## Syntax

```cpp
DWORD ICDecompressExEnd(
     hic
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if successful or an error otherwise.

## Description

The **ICDecompressExEnd** macro notifies a video decompression driver to end decompression and free resources allocated for decompression. You can use this macro or explicitly call the [ICM_DECOMPRESSEX_END](https://learn.microsoft.com/windows/desktop/Multimedia/icm-decompressex-end) message.

## Parameters

### `hic`

Handle to a decompressor.

## Remarks

The driver frees any resources allocated for the [ICM_DECOMPRESSEX_BEGIN](https://learn.microsoft.com/windows/desktop/Multimedia/icm-decompressex-begin) message.

[ICM_DECOMPRESSEX_BEGIN](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icdecompressexbegin) and [ICM_DECOMPRESSEX_END](https://learn.microsoft.com/windows/desktop/Multimedia/icm-decompressex-end) do not nest. If your driver receives [ICM_DECOMPRESSEX_BEGIN](https://learn.microsoft.com/windows/desktop/Multimedia/icm-decompressex-begin) before decompression is stopped with **ICM_DECOMPRESSEX_END**, it should restart decompression with new parameters.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
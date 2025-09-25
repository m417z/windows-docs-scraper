# ICCompressEnd macro

## Syntax

```cpp
DWORD ICCompressEnd(
     hic
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns ICERR_OK if successful or an error otherwise.

## Description

The **ICCompressEnd** macro notifies a video compression driver to end compression and free resources allocated for compression. You can use this macro or explicitly call the [ICM_COMPRESS_END](https://learn.microsoft.com/windows/desktop/Multimedia/icm-compress-end) message.

## Parameters

### `hic`

Handle of the compressor.

## Remarks

VCM saves the settings of the most recent **ICCompressBegin** macro. **ICCompressBegin** and **ICCompressEnd** do not nest. If your driver receives the **ICM_COMPRESS_BEGIN** message before compression is stopped with the **ICM_COMPRESS_END** message, it should restart compression with new parameters.

## See also

[Video Compression Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-macros)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
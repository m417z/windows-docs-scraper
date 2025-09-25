# ICLocate function

## Description

The **ICLocate** function finds a compressor or decompressor that can handle images with the specified formats, or finds a driver that can decompress an image with a specified format directly to hardware.

## Parameters

### `fccType`

Four-character code indicating the type of compressor or decompressor to open. For video streams, the value of this parameter is 'VIDC'.

### `fccHandler`

Preferred handler of the specified type. Typically, the handler type is stored in the stream header in an AVI file. Specify **NULL** if your application can use any handler type or it does not know the handler type to use.

### `lpbiIn`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure defining the input format. A compressor handle is not returned unless it supports this format.

### `lpbiOut`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure defining an optional decompressed format. You can also specify zero to use the default output format associated with the input format.

If this parameter is nonzero, a compressor handle is not returned unless it can create this output format.

### `wFlags`

Flags that describe the search criteria for a compressor or decompressor. The following values are defined:

| Value | Meaning |
| --- | --- |
| **ICMODE_COMPRESS** | Finds a compressor that can compress an image with a format defined by *lpbiIn* to the format defined by *lpbiOut*. |
| **ICMODE_DECOMPRESS** | Finds a decompressor that can decompress an image with a format defined by *lpbiIn* to the format defined by *lpbiOut*. |
| **ICMODE_DRAW** | Finds a decompressor that can decompress an image with a format defined by *lpbiIn* and draw it directly to hardware. |
| **ICMODE_FASTCOMPRESS** | Has the same meaning as **ICMODE_COMPRESS** except the compressor is used for a real-time operation and emphasizes speed over quality. |
| **ICMODE_FASTDECOMPRESS** | Has the same meaning as **ICMODE_DECOMPRESS** except the decompressor is used for a real-time operation and emphasizes speed over quality. |

## Return value

Returns a handle to a compressor or decompressor if successful or zero otherwise.

## See also

[Video Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-functions)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
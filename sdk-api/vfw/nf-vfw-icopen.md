# ICOpen function

## Description

The **ICOpen** function opens a compressor or decompressor.

## Parameters

### `fccType`

Four-character code indicating the type of compressor or decompressor to open. For video streams, the value of this parameter is "VIDC".

### `fccHandler`

Preferred handler of the specified type. Typically, the handler type is stored in the stream header in an AVI file.

### `wMode`

Flag defining the use of the compressor or decompressor. The following values are defined.

| Value | Meaning |
| --- | --- |
| ICMODE_COMPRESS | Compressor will perform normal compression. |
| ICMODE_DECOMPRESS | Decompressor will perform normal decompression. |
| ICMODE_DRAW | Decompressor will decompress and draw the data directly to hardware. |
| ICMODE_FASTCOMPRESS | Compressor will perform fast (real-time) compression. |
| ICMODE_FASTDECOMPRESS | Decompressor will perform fast (real-time) decompression. |
| ICMODE_QUERY | Queries the compressor or decompressor for information. |

## Return value

Returns a handle to a compressor or decompressor if successful or zero otherwise.

## See also

[Video Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-functions)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
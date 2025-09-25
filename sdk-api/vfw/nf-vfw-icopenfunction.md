# ICOpenFunction function

## Description

The **ICOpenFunction** function opens a compressor or decompressor defined as a function.

## Parameters

### `fccType`

Type of compressor to open. For video, the value of this parameter is ICTYPE_VIDEO.

### `fccHandler`

Preferred handler of the specified type. Typically, this comes from the stream header in an AVI file.

### `wMode`

Flag to define the use of the compressor or decompressor. The following values are defined.

| Value | Meaning |
| --- | --- |
| ICMODE_COMPRESS | Compressor will perform normal compression. |
| ICMODE_DECOMPRESS | Decompressor will perform normal decompression. |
| ICMODE_DRAW | Decompressor will decompress and draw the data directly to hardware. |
| ICMODE_FASTCOMPRESS | Compressor will perform fast (real-time) compression. |
| ICMODE_FASTDECOMPRESS | Decompressor will perform fast (real-time) decompression. |
| ICMODE_QUERY | Queries the compressor or decompressor for information. |

### `lpfnHandler`

Pointer to the function used as the compressor or decompressor.

## Return value

Returns a handle to a compressor or decompressor if successful or zero otherwise.

## See also

[Video Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-functions)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
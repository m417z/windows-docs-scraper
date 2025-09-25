# ICCompress function

## Description

The **ICCompress** function compresses a single video image.

## Parameters

### `hic`

Handle to the compressor to use.

### `dwFlags`

Compression flag. The following value is defined:

#### ICCOMPRESS_KEYFRAME

Compressor should make this frame a key frame.

### `lpbiOutput`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure containing the output format.

### `lpData`

Pointer to an output buffer large enough to contain a compressed frame.

### `lpbiInput`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure containing the input format.

### `lpBits`

Pointer to the input buffer.

### `lpckid`

Reserved; do not use.

### `lpdwFlags`

Pointer to the return flags used in the AVI index. The following value is defined:

#### AVIIF_KEYFRAME

Current frame is a key frame.

### `lFrameNum`

Frame number.

### `dwFrameSize`

Requested frame size, in bytes. Specify a nonzero value if the compressor supports a suggested frame size, as indicated by the presence of the **VIDCF_CRUNCH** flag returned by the [ICGetInfo](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icgetinfo) function. If this flag is not set or a data rate for the frame is not specified, specify zero for this parameter.

A compressor might have to sacrifice image quality or make some other trade-off to obtain the size goal specified in this parameter.

### `dwQuality`

Requested quality value for the frame. Specify a nonzero value if the compressor supports a suggested quality value, as indicated by the presence of the **VIDCF_QUALITY** flag returned by [ICGetInfo](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icgetinfo). Otherwise, specify zero for this parameter.

### `lpbiPrev`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure containing the format of the previous frame.

### `lpPrev`

Pointer to the uncompressed image of the previous frame. This parameter is not used for fast temporal compression. Specify **NULL** for this parameter when compressing a key frame, if the compressor does not support temporal compression, or if the compressor does not require an external buffer to store the format and data of the previous image.

## Return value

Returns **ICERR_OK** if successful or an error otherwise.

## Remarks

You can obtain the required by size of the output buffer by sending the [ICM_COMPRESS_GET_SIZE](https://learn.microsoft.com/windows/desktop/Multimedia/icm-compress-get-size) message (or by using the [ICCompressGetSize](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressgetsize) macro).

The compressor sets the contents of *lpdwFlags* to **AVIIF_KEYFRAME** when it creates a key frame. If your application creates AVI files, it should save the information returned for *lpckid* and *lpdwFlags* in the file.

Compressors use *lpbiPrev* and *lpPrev* to perform temporal compression and require an external buffer to store the format and data of the previous frame. Specify **NULL** for *lpbiPrev* and *lpPrev* when compressing a key frame, when performing fast compression, or if the compressor has its own buffer to store the format and data of the previous image. Specify non-**NULL** values for these parameters if [ICGetInfo](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icgetinfo) returns the **VIDCF_TEMPORAL** flag, the compressor is performing normal compression, and the frame to compress is not a key frame.

## See also

[Video Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-functions)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
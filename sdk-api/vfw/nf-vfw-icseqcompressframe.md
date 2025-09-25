# ICSeqCompressFrame function

## Description

The **ICSeqCompressFrame** function compresses one frame in a sequence of frames.

## Parameters

### `pc`

Pointer to a [COMPVARS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-compvars) structure initialized with information about the compression.

### `uiFlags`

Reserved; must be zero.

### `lpBits`

Pointer to the data bits to compress. (The data bits exclude header or format information.)

### `pfKey`

Returns whether or not the frame was compressed into a key frame.

### `plSize`

Maximum size desired for the compressed image. The compressor might not be able to compress the data to fit within this size. When the function returns, the parameter points to the size of the compressed image. Images sizes are specified in bytes.

## Return value

Returns the address of the compressed bits if successful or **NULL** otherwise.

## Remarks

This function uses a [COMPVARS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-compvars) structure to provide settings for the specified compressor and intersperses key frames at the rate specified by the [ICSeqCompressorFrameStart](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icseqcompressframestart) function. You can specify values for the data rate for the sequence and the key-frame frequency by using the appropriate members of **COMPVARS**.

Use this function instead of the [ICCompress](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompress) function to compress a video sequence.

You can allow the user to specify a compressor and initialize a [COMPVARS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-compvars) structure by using the [ICCompressorChoose](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressorchoose) function. Or, you can initialize a **COMPVARS** structure manually.

Use the [ICSeqCompressFrameStart](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icseqcompressframestart), **ICSeqCompressFrame**, and [ICSeqCompressFrameEnd](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icseqcompressframeend) functions to compress a sequence of frames to a specified data rate and number of key frames. Use **ICSeqCompressFrame** once for each frame to be compressed.

When finished with compression, use the [ICCompressorFree](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressorfree) function to release the resources specified by [COMPVARS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-compvars).

## See also

[Video Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-functions)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
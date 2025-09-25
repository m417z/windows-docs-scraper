# ICSeqCompressFrameStart function

## Description

The **ICSeqCompressFrameStart** function initializes resources for compressing a sequence of frames using the [ICSeqCompressFrame](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icseqcompressframe) function.

## Parameters

### `pc`

Pointer to a [COMPVARS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-compvars) structure initialized with information for compression.

### `lpbiIn`

Format of the data to be compressed.

## Return value

Returns **TRUE** if successful or **FALSE** otherwise.

## Remarks

This function uses a [COMPVARS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-compvars) structure to provide settings for the specified compressor and intersperses key frames at the rate specified by the **lKey** member of **COMPVARS**. You can specify values for the data rate for the sequence and the key-frame frequency by using the appropriate members of **COMPVARS**.

Use the **ICSeqCompressFrameStart**, [ICSeqCompressFrame](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icseqcompressframe), and [ICSeqCompressFrameEnd](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icseqcompressframeend) functions to compress a sequence of frames to a specified data rate and number of key frames.

When finished with compression, use the [ICCompressorFree](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressorfree) function to release the resources specified in [COMPVARS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-compvars).

[COMPVARS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-compvars) needs to be initialized before you use this function. You can initialize the structure manually or you can allow the user to specify a compressor and initialize a **COMPVARS** structure by using the [ICCompressorChoose](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressorchoose) function.

## See also

[Video Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-functions)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
# ICSeqCompressFrameEnd function

## Description

The **ICSeqCompressFrameEnd** function ends sequence compression that was initiated by using the [ICSeqCompressFrameStart](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icseqcompressframestart) and [ICSeqCompressFrame](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icseqcompressframe) functions.

## Parameters

### `pc`

Pointer to a [COMPVARS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-compvars) structure used during sequence compression.

## Return value

This function does not return a value.

## Remarks

When finished with compression, use the [ICCompressorFree](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressorfree) function to release the resources specified by [COMPVARS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-compvars).

## See also

[Video Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-functions)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
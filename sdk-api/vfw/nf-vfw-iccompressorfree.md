# ICCompressorFree function

## Description

The **ICCompressorFree** function frees the resources in the [COMPVARS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-compvars) structure used by other VCM functions.

## Parameters

### `pc`

Pointer to the [COMPVARS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-compvars) structure containing the resources to be freed.

## Return value

This function does not return a value.

## Remarks

Use this function to release the resources in the [COMPVARS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-compvars) structure after using the [ICCompressorChoose](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressorchoose), [ICSeqCompressFrameStart](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icseqcompressframestart), [ICSeqCompressFrame](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icseqcompressframe), and [ICSeqCompressFrameEnd](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icseqcompressframeend) functions.

## See also

[Video Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-functions)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
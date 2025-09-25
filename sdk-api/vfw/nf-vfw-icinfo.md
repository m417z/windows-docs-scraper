# ICInfo function

## Description

The **ICInfo** function retrieves information about specific installed compressors or enumerates the installed compressors.

## Parameters

### `fccType`

Four-character code indicating the type of compressor. Specify zero to match all compressor types.

### `fccHandler`

Four-character code identifying a specific compressor or a number between zero and the number of installed compressors of the type specified by *fccType*.

### `lpicinfo`

Pointer to a [ICINFO](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-icinfo) structure to return information about the compressor.

## Return value

Returns **TRUE** if successful or an error otherwise.

## Remarks

To enumerate the compressors or decompressors, specify an integer for *fccHandler*. This function returns information for integers between zero and the number of installed compressors or decompressors of the type specified for *fccType*.

## See also

[Video Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-functions)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
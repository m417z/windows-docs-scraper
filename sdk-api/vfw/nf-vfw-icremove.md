# ICRemove function

## Description

The **ICRemove** function removes an installed compressor.

## Parameters

### `fccType`

Four-character code indicating the type of data used by the compressor or decompressor. Specify "VIDC" for a video compressor or decompressor.

### `fccHandler`

Four-character code identifying a specific compressor or a number between zero and the number of installed compressors of the type specified by *fccType*.

### `wFlags`

Reserved; do not use.

## Return value

Returns **TRUE** if successful or **FALSE** otherwise.

## See also

[Video Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-functions)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
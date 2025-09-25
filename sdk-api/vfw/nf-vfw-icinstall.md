# ICInstall function

## Description

The **ICInstall** function installs a new compressor or decompressor.

## Parameters

### `fccType`

Four-character code indicating the type of data used by the compressor or decompressor. Specify "VIDC" for a video compressor or decompressor.

### `fccHandler`

Four-character code identifying a specific compressor or decompressor.

### `lParam`

Pointer to a null-terminated string containing the name of the compressor or decompressor, or the address of a function used for compression or decompression. The contents of this parameter are defined by the flags set for *wFlags*.

### `szDesc`

Reserved; do not use.

### `wFlags`

Flags defining the contents of *lParam*. The following values are defined.

| Value | Meaning |
| --- | --- |
| ICINSTALL_DRIVER | The *lParam* parameter contains the address of a null-terminated string that names the compressor to install. |
| ICINSTALL_FUNCTION | The *lParam* parameter contains the address of a compressor function. This function should be structured like the [DriverProc](https://learn.microsoft.com/previous-versions/dd797918(v=vs.85)) entry point function used by compressors. |

## Return value

Returns ICERR_OK if successful or an error otherwise.

## Remarks

Applications must open an installed compressor or decompressor before using it.

If your application installs a function as a compressor or decompressor, it should remove the function with the [ICRemove](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icremove) function before it terminates. This prevents other applications from trying to access the function when it is not available.

## See also

[Video Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-functions)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
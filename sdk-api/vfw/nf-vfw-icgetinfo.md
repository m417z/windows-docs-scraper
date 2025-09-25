# ICGetInfo function

## Description

The **ICGetInfo** function obtains information about a compressor.

## Parameters

### `hic`

Handle to a compressor.

### `picinfo`

Pointer to the [ICINFO](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-icinfo) structure to return information about the compressor.

### `cb`

Size, in bytes, of the structure pointed to by *lpicinfo*.

## Return value

Returns the number of bytes copied into the structure or zero if an error occurs.

## See also

[Video Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-functions)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)
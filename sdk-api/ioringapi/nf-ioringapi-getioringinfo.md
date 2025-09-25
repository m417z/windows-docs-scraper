## Description

Gets information about the API version and queue sizes of an I/O ring.

## Parameters

### `ioRing`

An **HIORING** representing a handle to the I/O ring for which information is being queried.

### `info`

Receives a pointer to an [IORING_INFO](https://learn.microsoft.com/windows/win32/api/ioringapi/ns-ioringapi-ioring_info) structure specifying API version and queue sizes for the specified I/O ring.

## Return value

S_OK on success.

## Remarks

## See also
# AVIFileReadData function

## Description

The **AVIFileReadData** function reads optional header data that applies to the entire file, such as author or copyright information.

## Parameters

### `pfile`

Handle to an open AVI file.

### `ckid`

RIFF chunk identifier (four-character code) of the data.

### `lpData`

Pointer to the buffer used to return the data read.

### `lpcbData`

Pointer to a location indicating the size of the memory block referenced by *lpData*. If the data is read successfully, the value is changed to indicate the amount of data read.

## Return value

Returns zero if successful or an error otherwise. The return value AVIERR_NODATA indicates that data with the requested chunk identifier does not exist.

## Remarks

The optional header information is custom and does not have a set format.

The argument *pfile* is a pointer to an [IAVIFile](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavifile) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)
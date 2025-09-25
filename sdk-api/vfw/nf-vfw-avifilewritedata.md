# AVIFileWriteData function

## Description

The **AVIFileWriteData** function writes supplementary data (other than normal header, format, and stream data) to the file.

## Parameters

### `pfile`

Handle to an open AVI file.

### `ckid`

RIFF chunk identifier (four-character code) of the data.

### `lpData`

Pointer to the buffer used to write the data.

### `cbData`

Size, in bytes, of the memory block referenced by *lpData*.

## Return value

Returns zero if successful or an error otherwise. In an application has read-only access to the file, the error code AVIERR_READONLY is returned.

## Remarks

Use the [AVIStreamWriteData](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avistreamwritedata) function to write data that applies to an individual stream.

The argument *pfile* is a pointer to an [IAVIFile](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavifile) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)
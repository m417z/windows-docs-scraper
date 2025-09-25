# AVIFileCreateStream function

## Description

The **AVIFileCreateStream** function creates a new stream in an existing file and creates an interface to the new stream.

## Parameters

### `pfile`

Handle to an open AVI file.

### `ppavi`

Pointer to the new stream interface.

### `psi`

Pointer to a structure containing information about the new stream, including the stream type and its sample rate.

## Return value

Returns zero if successful or an error otherwise. Unless the file has been opened with write permission, this function returns AVIERR_READONLY.

## Remarks

This function starts a reference count for the new stream.

The argument *pfile* is a pointer to an [IAVIFile](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavifile) interface. The argument *ppavi* is a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIStreamInfo](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avistreaminfoa)
# AVIFileCreateStreamA function

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

> [!NOTE]
> The vfw.h header defines AVIFileCreateStream as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIStreamInfo](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avistreaminfoa)
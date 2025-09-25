# AVIStreamInfoW function

## Description

The **AVIStreamInfo** function obtains stream header information.

## Parameters

### `pavi`

Handle to an open stream.

### `psi`

Pointer to a structure to contain the stream information.

### `lSize`

Size, in bytes, of the structure used for psi.

## Return value

Returns zero if successful or an error otherwise.

The argument *pavi* is a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

## Remarks

> [!NOTE]
> The vfw.h header defines AVISTREAMINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
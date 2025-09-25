# AVIFileInfoA function

## Description

The **AVIFileInfo** function obtains information about an AVI file.

## Parameters

### `pfile`

Handle to an open AVI file.

### `pfi`

Pointer to the structure used to return file information. Typically, this parameter points to an [AVIFILEINFO](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-avifileinfoa) structure.

### `lSize`

Size, in bytes, of the structure.

## Return value

Returns zero if successful or an error otherwise.

## Remarks

The argument *pfile* is a pointer to an [IAVIFile](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavifile) interface.

> [!NOTE]
> The vfw.h header defines AVIFILEINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)
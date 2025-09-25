# AVIFileInfo function

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

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)
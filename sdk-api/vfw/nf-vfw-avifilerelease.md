# AVIFileRelease function

## Description

The **AVIFileRelease** function decrements the reference count of an AVI file interface handle and closes the file if the count reaches zero.

This function supersedes the obsolete **AVIFileClose** function.

## Parameters

### `pfile`

Handle to an open AVI file.

## Return value

Returns the reference count of the file. This return value should be used only for debugging purposes.

## Remarks

The argument *pfile* is a pointer to an [IAVIFile](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavifile) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)
# AVIStreamRelease function

## Description

The **AVIStreamRelease** function decrements the reference count of an AVI stream interface handle, and closes the stream if the count reaches zero.

This function supersedes the obsolete **AVIStreamClose** function.

## Parameters

### `pavi`

Handle to an open stream.

## Return value

Returns the current reference count of the stream. This value should be used only for debugging purposes.

The argument *pavi* is a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)
# AVIMakeFileFromStreams function

## Description

The **AVIMakeFileFromStreams** function constructs an AVIFile interface pointer from separate streams.

## Parameters

### `ppfile`

Pointer to a buffer that receives the new file interface pointer.

### `nStreams`

Count of the number of streams in the array of stream interface pointers referenced by papStreams.

### `papStreams`

Pointer to an array of stream interface pointers.

## Return value

Returns zero if successful or an error otherwise.

## Remarks

Use the [AVIFileRelease](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avifilerelease) function to close the file.

Other functions can use the AVIFile interface created by this function to copy and edit the streams associated with the interface. For example, you can retrieve a specific stream by using [AVIFileGetStream](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avifilegetstream) with the file interface pointer.

The argument *pfile* is the address of a pointer to an [IAVIFile](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavifile) interface. The argument *papStreams* is the address of a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFileGetStream](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avifilegetstream)

[AVIFileRelease](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avifilerelease)
## Description

Commits the image represented by the image handle.

## Parameters

### `cimImageHandle`

Type: **CIMFS_IMAGE_HANDLE**
An opaque handle that represents a writer for the image. This handle is created using CimCreateImage.

## Return value

**[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
E_INVALIDARG – The image handle is invalid
HRESULT_FROM_WIN32(ERROR_SHARING_VIOLATION) – The image handle is still in use by another stream handle or the parent image may be mounted. An image cannot be committed while an open stream handle exists and cannot be overwritten when mounted.

## Remarks
Once the image is committed no additional operations can be performed on the image using the image handle. The handle must still be closed to free its associated resources.

The name of the image committed is determined by the parameters to CimCreateImage. Note, it is an error to commit an image while an open stream handle exists for the image.

## See also
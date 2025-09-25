## Description

Removes the file, stream, directory or hardlink at a path relative to the image represented by the image handle.

## Parameters

### `cimImageHandle`

Type: **CIMFS_IMAGE_HANDLE**
An opaque handle that represents a writer for the image. This handle is created using CimCreateImage.

### `imageRelativePath`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
A path relative to the image root for the file, directory, alternate stream or hardlink to be deleted. If the path refers to an existing directory, the directory and its entire contents are deleted.

## Return value

**[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
E_INVALIDARG – The image handle is invalid, the relative path is not a valid relative path for file.
HRESULT_FROM_WIN32(ERROR_PATH_NOT_FOUND) – The path specified does not exist in the image.
HRESULT_FROM_WIN32(ERROR_SHARING_VIOLATION) – The image handle is in use by another stream handle. Only one stream handle may exist per image handle.

## Remarks

Internally CimDeletePath opens and closes a stream handle and only one stream handle can be opened for a given image at a given time. It is an error to call CimDeletePath while a stream handle is opened on the image. Close any open stream handle before deleting a path.

## See also
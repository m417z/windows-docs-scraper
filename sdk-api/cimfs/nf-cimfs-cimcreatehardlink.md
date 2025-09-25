## Description

Adds a hard link to an existing path relative to the image represented by the image handle.

## Parameters

### `cimImageHandle`

Type: **CIMFS_IMAGE_HANDLE**
An opaque handle that represents a writer for the image. This handle is created using CimCreateImage.

### `imageRelativePath`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
A path relative to the image root where the new hard link will be created. If the path refers to an existing file, that file will be replaced with a link to the file specified.

### `existingImageRelativePath`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
An existing path relative to the image root that will be hard linked. The path must refer to an existing file in the image. It is an error to pass a path to a directory or alternate stream.

## Return value

**[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
E_INVALIDARG – The image handle is invalid, the imageRelativePath or existingImageRelative path is not a valid relative path for file.
HRESULT_FROM_WIN32(ERROR_PATH_NOT_FOUND) – existingImageRelativePath does not exist in the image.
HRESULT_FROM_WIN32(ERROR_SHARING_VIOLATION) – The image handle is in use by another stream handle. Only one stream handle may exist per image handle.
E_ACCESSDENIED – The existingImageRelativePath is a directory.

## Remarks

Internally CimCreateHardLink opens and closes a stream handle and only one stream handle can be opened for a given image at a given time. It is an error to call CimCreateHardLink while a stream handle is opened on the image. Close any open stream handle before adding a hard link.

## See also
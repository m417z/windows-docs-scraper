## Description

Adds an alternate stream with the specified size at a path relative to the image represented by the image handle. Provides a handle to the stream which can be used to write data to the stream.

## Parameters

### `cimImageHandle`

Type: **CIMFS_IMAGE_HANDLE**
An opaque handle that represents a writer for the image. This handle is created using CimCreateImage.
Only one stream handle can be opened for a given image at a given time. Close the stream handle before opening another stream.

### `imageRelativePath`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
A path relative to the image root where the new stream will be created. The path must refer to an existing file or directory in the image and the stream name must be separated by a ‘:’ character.

### `streamSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The size of the stream in bytes. The stream may be written only up to this size. Once the stream is created its size cannot be extended. To extend the stream it must be re-created. The stream will be sparsely allocated in the image such that ranges that are never written contains zeros when read.

### `cimStreamHandle`

Type: **CIMFS_STREAM_HANDLE\***
An opaque handle that represents a writer for the stream. This handle may be passed in subsequent routines to write the stream.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
E_INVALIDARG – The image handle is invalid, the relative path is not a valid relative path for an alternate stream. The stream name must have the format imageRelativeFilePath:StreamName.
HRESULT_FROM_WIN32(ERROR_PATH_NOT_FOUND) – parent file or directory for the path specified does not exist in the image.
HRESULT_FROM_WIN32(ERROR_SHARING_VIOLATION) – The image handle is in use by another stream handle. Only one stream handle may exist per image handle.

## Remarks

## See also
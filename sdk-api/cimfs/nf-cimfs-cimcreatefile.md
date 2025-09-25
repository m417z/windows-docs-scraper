## Description

Adds a new file or directory with the specified metadata at a path relative to the image represented by the image handle. Returns a stream handle to the primary stream. The stream handle can be used to write data to a file. If the path already exists in the image it is overwritten.
Only one stream handle can be opened for a given image at a given time. Close any existing stream handle before creating another stream.

## Parameters

### `cimImageHandle`

Type: **CIMFS_IMAGE_HANDLE**
An opaque handle that represents a writer for the image. This handle is created using CimCreateImage.

### `imageRelativePath`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
A path relative to the image root where the new file or directory will be created. A leading backslash in the path is allowed. If the path refers to an existing file or directory in the image, the existing item will be overwritten.

### `fileMetadata`

Type: **CIMFS_FILE_METADATA\***
Pointer to a structure that contains the metadata for the new file or directory. For files, a size is provided in the metadata. The file may be written up to this size. Once the file is created its size cannot be extended. To extend the file it must be re-created. Ranges in the file that are never written will be read as zero.

### `cimStreamHandle`

Type: **CIMFS_STREAM_HANDLE\***
Receives an opaque handle that represents a writer for the stream. This handle may be passed in subsequent routines to write the stream.

## Return value

**[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
E_INVALIDARG – The image handle is invalid, the relative path is not a valid relative path or the fileMetadata fields are malformed.
HRESULT_FROM_WIN32(ERROR_SHARING_VIOLATION) – The image handle is in use by another stream handle. Only one stream handle may exist per image handle.

## Remarks

## See also
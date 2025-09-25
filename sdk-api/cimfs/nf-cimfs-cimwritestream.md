## Description

Writes data from the specified buffer to the stream represented by the stream handle.

## Parameters

### `cimStreamHandle`

Type: **CIMFS_STREAM_HANDLE**
An opaque handle that represents a writer for the stream created with CimCreateFile or CimCreateAlternateStream.

### `buffer`

TYPE: **void\***
A caller allocated buffer that contains the data to be written

### `bufferSize`

Type **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The size of the caller allocated buffer. The contents of the buffer will be written to the stream up to but not exceeding the stream size provided when the stream was created.

## Return value

**[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
E_INVALIDARG – The stream handle is invalid or the handle provided refers to a directory rather than a file or alternate stream.
E_POINTER – The buffer pointer is NULL
HRESULT_FROM_WIN32(ERROR_HANDLE_EOF) – The write extends past the file size specified when the stream was created. The data written was truncated at the end of file.

## Remarks

## See also
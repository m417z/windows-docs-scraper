# PRJ_GET_FILE_DATA_CB callback function

## Description

Requests the contents of a file's primary data stream.

## Parameters

### `callbackData` [in]

Information about the operation. The following *callbackData* members are necessary to implement this callback:

**FilePathName** Identifies the path to the file in the provider’s backing store for which data should be returned. Note that this reflects the name the file had when its placeholder was first created. If it has been renamed since then, **FilePathName** identifies the original (pre-rename) name, not the current (post-rename) name.

**DataStreamId**The unique value to associate with this file stream. The provider must pass this value in the *dataStreamId* parameter of [PrjWriteFileData](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjwritefiledata) when providing file data as part of handling this callback.

**VersionInfo** Provides the [PRJ_PLACEHOLDER_VERSION_INFO](https://learn.microsoft.com/windows/desktop/api/projectedfslib/ns-projectedfslib-prj_placeholder_version_info) information that the provider supplied when it created the placeholder for this file. This may help the provider determine which version of the file contents to return. If the file has been renamed and the provider tracks renames, this may also help the provider determine which file’s contents are being requested.

The provider can access this buffer only while the callback is running. If it wishes to pend the operation and it requires data from this buffer, it must make its own copy of it.

### `byteOffset` [in]

Offset of the requested data, in bytes, from the beginning of the file. The provider must return file data starting at or before this offset

### `length` [in]

Number of bytes of file data requested. The provider must return at least this many bytes of file data beginning with byteOffset.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The provider successfully returned all the requested data. |
| **HRESULT_FROM_WIN32(ERROR_IO_PENDING)** | The provider wishes to complete the operation at a later time. |

An appropriate HRESULT error code if the provider fails the operation.

## Remarks

When ProjFS receives the data it will write it to the file to convert it into a hydrated placeholder.

To handle this callback, the provider issues one or more calls to [PrjWriteFileData](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjwritefiledata) to give ProjFS the requested contents of the file's primary data stream. Then the provider completes the callback.
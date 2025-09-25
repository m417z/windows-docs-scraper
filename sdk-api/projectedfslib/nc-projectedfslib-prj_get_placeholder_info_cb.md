# PRJ_GET_PLACEHOLDER_INFO_CB callback function

## Description

Requests information for a file or directory from the provider.

## Parameters

### `callbackData` [in]

Information about the operation. The following *callbackData* members are necessary to implement this callback:

**FilePathName** Identifies the path to the file or directory in the provider's store for which ProjFS is requesting information.

The provider uses this to determine whether the name exists in its backing store. It should use the [PrjFileNameMatch](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjfilenamematch) function to compare this name to the names in its store. If it finds a matching name, it uses that name as the *destinationFileName* parameter of the [PrjWritePlaceholderInfo](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjwriteplaceholderinfo) function.

**VersionInfo** Provides version information for the parent directory of the requested item.

The provider can access this buffer only while the callback is running. If it wishes to pend the operation and it requires data from this buffer, it must make its own copy of it.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The file exists in the provider's store and it successfully gave the file's information to ProjFS. |
| **HRESULT_FROM_WIN32(ERROR_IO_PENDING)** | The provider wishes to complete the operation at a later time. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)** | The file does not exist in the provider's store. |

Another appropriate HRESULT error code if the provider fails the operation.

## Remarks

ProjFS will use the information provided in this callback to create a placeholder for the requested item.

To handle this callback, the provider calls [PrjWritePlaceholderInfo](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjwriteplaceholderinfo) to give ProjFS the information for the requested file name. Then the provider completes the callback.
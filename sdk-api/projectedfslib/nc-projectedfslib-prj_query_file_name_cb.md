# PRJ_QUERY_FILE_NAME_CB callback function

## Description

Determines whether a given file path exists in the provider's backing store.

## Parameters

### `callbackData` [in]

Information about the operation.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The queried file path exists in the provider's store. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)** | The queried file path does not exist in the provider's store. |
| **HRESULT_FROM_WIN32(ERROR_IO_PENDING)** | The provider wishes to complete the operation at a later time. |

An appropriate HRESULT error code if the provider fails the operation.

## Remarks

This callback is optional. If the provider does not supply an implementation of this callback, ProjFS will invoke the provider’s directory enumeration callbacks to determine the existence of a file path in the provider's store.

The provider should use [PrjFileNameCompare](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjfilenamecompare) as the comparison routine when searching its backing store for the specified file.
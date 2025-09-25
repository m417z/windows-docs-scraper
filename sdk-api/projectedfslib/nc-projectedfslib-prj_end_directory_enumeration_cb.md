# PRJ_END_DIRECTORY_ENUMERATION_CB callback function

## Description

Informs the provider that a directory enumeration is over.

## Parameters

### `callbackData` [in]

Information about the operation.

The provider can access this buffer only while the callback is running. If it wishes to pend the operation and it requires data from this buffer, it must make its own copy of it.

### `enumerationId` [in]

An identifier for this enumeration session. See the Remarks section of [PRJ_START_DIRECTORY_ENUMERATION_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_start_directory_enumeration_cb) for more information.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The provider successfully completed the operation. |
| **HRESULT_FROM_WIN32(ERROR_IO_PENDING)** | The provider wishes to complete the operation at a later time. |

The provider should not return any other value from this callback.

## Remarks

For a user-initiated enumeration ProjFS invokes this callback when the file handle used to enumerate the directory is closed. For a ProjFS-initiated enumeration, this callback is invoked when ProjFS completes the enumeration.
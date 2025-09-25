# PRJ_START_DIRECTORY_ENUMERATION_CB callback function

## Description

Informs the provider that a directory enumeration is starting.

## Parameters

### `callbackData` [in]

Information about the operation. The following *callbackData* members are necessary to implement this callback:

**FilePathName** Identifies the directory to be enumerated.

**VersionInfo** Provides version information for the directory to be enumerated.

The provider can access this buffer only while the callback is running. If it wishes to pend the operation and it requires data from this buffer, it must make its own copy of it.

### `enumerationId` [in]

An identifier for this enumeration session.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The provider successfully completed the operation. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)** | The directory to be enumerated does not exist in the provider’s backing store. |
| **HRESULT_FROM_WIN32(ERROR_IO_PENDING)** | The provider wishes to complete the operation at a later time. |

An appropriate HRESULT error code if the provider fails the operation.

## Remarks

ProjFS requests a directory enumeration from the provider by first invoking this callback, then one or more [PRJ_GET_DIRECTORY_ENUMERATION_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_directory_enumeration_cb) callbacks, then the [PRJ_END_DIRECTORY_ENUMERATION_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_end_directory_enumeration_cb) callback. Because multiple enumerations may occur in parallel in the same location, ProjFS uses the *enumerationId* argument to associate the callback invocations into a single enumeration session, meaning that a given set of calls to the enumeration callbacks will use the same value for *enumerationId* for the same session.
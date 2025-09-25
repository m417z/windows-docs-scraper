# PRJ_GET_DIRECTORY_ENUMERATION_CB callback function

## Description

Requests directory enumeration information from the provider.

## Parameters

### `callbackData` [in]

Information about the operation. The following *callbackData* members are necessary to implement this callback:

**FilePathName** Identifies the directory to be enumerated.

**VersionInfo** Provides version information for the directory to be enumerated.

**Flags** Flags to control what is returned in the enumeration. Valid values are:

|  |  |
| --- | --- |
| PRJ_CB_DATA_FLAG_ENUM_RETURN_SINGLE_ENTRY | This bit is set if the user is requesting only one entry from the enumeration. The provider may treat this as a hint, and may opt to return more than one entry to make an enumeration that returns one item at a time more efficient. In such a case ProjFS will return single entry to the user, invoking the provider only when it needs more entries. |
| PRJ_CB_DATA_FLAG_ENUM_RESTART_SCAN | This bit is set if the enumeration is to start at the first entry in the directory. On the first invocation of this callback for an enumeration session the provider must treat this flag as set, regardless of its value. All enumerations must start at the first entry. On subsequent invocations of this callback the provider must honor this value. |

The provider can access this buffer only while the callback is running. If it wishes to pend the operation and it requires data from this buffer, it must make its own copy of it.

### `enumerationId` [in]

An identifier for this enumeration session.

### `searchExpression` [in, optional]

A pointer to a null-terminated Unicode string specifying a search expression. The search expression may include wildcard characters. The provider should use the [PrjDoesNameContainWildCards](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjdoesnamecontainwildcards) function to determine whether wildcards are present in **searchExpression**, and it should use the [PrjFileNameMatch](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjfilenamematch) function to determine whether an entry in its backing store matches a search expression containing wildcards.

This parameter is optional and may be NULL.

* If this parameter is not NULL, the provider must return only those directory entries whose names match the search expression.
* If this parameter is NULL, the provider must return all directory entries.

The provider should capture the value of this parameter on the first invocation of this callback for an enumeration session and use it on subsequent invocations, ignoring this parameter on those invocations unless **PRJ_CB_DATA_FLAG_ENUM_RESTART_SCAN** is specified in the **Flags** member of **callbackData**. In that case the provider must re-capture the value of **searchExpression.**

### `dirEntryBufferHandle` [in]

An opaque handle to a structure that receives the results of the enumeration from the provider. The provider uses the [PrjFillDirEntryBuffer](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjfilldirentrybuffer) routine to fill the structure.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The provider successfully added at least one entry to dirEntryBufferHandle, or no entries in the provider’s store match searchExpression. |
| **HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)** | The provider received this error from [PrjFillDirEntryBuffer](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjfilldirentrybuffer) for the first file or directory it tried to add to dirEntryBufferHandle. |
| **HRESULT_FROM_WIN32(ERROR_IO_PENDING)** | The provider wishes to complete the operation at a later time. |

An appropriate HRESULT error code if the provider fails the operation.

## Remarks

ProjFS invokes this callback one or more times after invoking [PRJ_START_DIRECTORY_ENUMERATION_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_start_directory_enumeration_cb). See the Remarks section of *PRJ_START_DIRECTORY_ENUMERATION_CB* for more information.
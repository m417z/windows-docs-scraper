# PssQuerySnapshot function

## Description

Queries the snapshot.

## Parameters

### `SnapshotHandle` [in]

A handle to the snapshot to query.

### `InformationClass` [in]

An enumerator member that selects what information to query. For more information, see [PSS_QUERY_INFORMATION_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ne-processsnapshot-pss_query_information_class).

### `Buffer` [out]

The information that this function provides.

### `BufferLength` [in]

The size of *Buffer*, in bytes.

## Return value

This function returns **ERROR_SUCCESS** on success or one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_BAD_LENGTH** | The specified buffer length is invalid. |
| **ERROR_INVALID_HANDLE** | The specified handle is invalid. |
| **ERROR_INVALID_PARAMETER** | The specified information class is invalid. |
| **ERROR_NOT_FOUND** | The requested information is not in the snapshot. |

All error codes are defined in winerror.h. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) with the **FORMAT_MESSAGE_FROM_SYSTEM** flag to get a message for an error code.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)
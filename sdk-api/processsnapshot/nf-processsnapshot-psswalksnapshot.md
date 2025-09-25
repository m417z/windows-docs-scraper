# PssWalkSnapshot function

## Description

Returns information from the current walk position and advances the walk marker to the next position.

## Parameters

### `SnapshotHandle` [in]

A handle to the snapshot.

### `InformationClass` [in]

The type of information to return. For more information, see [PSS_WALK_INFORMATION_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ne-processsnapshot-pss_walk_information_class).

### `WalkMarkerHandle` [in]

A handle to a walk marker. The walk marker indicates the walk position from which data is to be returned. **PssWalkSnapshot** advances the walk marker to the next walk position in time order before returning to the caller.

### `Buffer` [out]

The snapshot information that this function returns.

### `BufferLength` [in]

The size of *Buffer*, in bytes.

## Return value

This function returns **ERROR_SUCCESS** on success or one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_BAD_LENGTH** | The specified buffer length is invalid. |
| **ERROR_INVALID_HANDLE** | The specified handle is invalid. |
| **ERROR_INVALID_PARAMETER** | The specified information class is invalid. |
| **ERROR_MORE_DATA** | *Buffer* is **NULL**, and there is data at the current position to return. |
| **ERROR_NO_MORE_ITEMS** | The walk has completed and there are no more items to return. |
| **ERROR_NOT_FOUND** | The requested information is not in the snapshot. |

All error codes are defined in winerror.h. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) with the **FORMAT_MESSAGE_FROM_SYSTEM** flag to get a message for an error code.

## Remarks

For snapshot data types that have a variable number of instances within a snapshot, you use the **PssWalkSnapshot** function to obtain the instances one after another. You set the *InformationClass* parameter to specify the type of data.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)
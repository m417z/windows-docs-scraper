# PssWalkMarkerCreate function

## Description

Creates a walk marker.

## Parameters

### `Allocator` [in, optional]

A structure that provides functions to allocate and free memory. If you provide the structure, **PssWalkMarkerCreate** uses the functions to allocate the internal walk marker structures. Otherwise it uses the default process heap. For more information, see [PSS_ALLOCATOR](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ns-processsnapshot-pss_allocator).

### `WalkMarkerHandle` [out]

A handle to the walk marker that this function creates.

## Return value

This function returns **ERROR_SUCCESS** on success or the following error code.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | Could not allocate memory for the walk marker. |

All error codes are defined in winerror.h. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) with the **FORMAT_MESSAGE_FROM_SYSTEM** flag to get a message for an error code.

## Remarks

The walk marker maintains the state of a walk, and can be used to reposition or rewind the walk.

The *Allocator* structure that provides the custom functions should remain valid for the lifetime of the walk marker. The custom functions are called from **PssWalkMarkerCreate**, [PssWalkMarkerFree](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalkmarkerfree) and [PssWalkSnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalksnapshot) using the same thread that calls **PssWalkMarkerCreate**, **PssWalkMarkerFree** and **PssWalkSnapshot**. Therefore the custom functions need not be multi-threaded.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)
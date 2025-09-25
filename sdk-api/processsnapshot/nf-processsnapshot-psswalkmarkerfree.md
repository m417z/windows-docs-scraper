# PssWalkMarkerFree function

## Description

Frees a walk marker created by [PssWalkMarkerCreate](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalkmarkercreate).

## Parameters

### `WalkMarkerHandle` [in]

A handle to the walk marker.

## Return value

This function returns **ERROR_SUCCESS** on success.

All error codes are defined in winerror.h. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) with the **FORMAT_MESSAGE_FROM_SYSTEM** flag to get a message for an error code.

## Remarks

If [PssWalkMarkerCreate](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalkmarkercreate) used **AllocRoutine** of a custom allocator to create the walk marker, **PssWalkMarkerFree** uses the **FreeRoutine** of the allocator.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)
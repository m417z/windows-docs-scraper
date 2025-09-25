# PssWalkMarkerSetPosition function

## Description

Sets the position of a walk marker.

## Parameters

### `WalkMarkerHandle` [in]

A handle to the walk marker.

### `Position` [in]

The position to set. This is a position that the [PssWalkMarkerGetPosition](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalkmarkergetposition) function provided.

## Return value

This function returns **ERROR_SUCCESS** on success or one of the following error codes.

All error codes are defined in winerror.h. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) with the **FORMAT_MESSAGE_FROM_SYSTEM** flag to get a message for an error code.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)
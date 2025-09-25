# PssWalkMarkerGetPosition function

## Description

Returns the current position of a walk marker.

## Parameters

### `WalkMarkerHandle` [in]

A handle to the walk marker.

### `Position` [out]

The walk marker position that this function returns.

## Return value

This function returns **ERROR_SUCCESS** on success.

All error codes are defined in winerror.h. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) with the **FORMAT_MESSAGE_FROM_SYSTEM** flag to get a message for an error code.

## Remarks

The position value compared to the values of other positions is not of any significance. The only valid use of the position is to set the current position using the [PssWalkMarkerSetPosition](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalkmarkersetposition) function.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)
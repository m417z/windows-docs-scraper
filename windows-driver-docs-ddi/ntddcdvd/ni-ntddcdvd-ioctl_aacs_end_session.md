# IOCTL_AACS_END_SESSION IOCTL

## Description

Releases the Authentication Grant Identifier (AGID) that was obtained by [IOCTL_AACS_START_SESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_start_session).

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a value of type [DVD_SESSION_ID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff553743(v=vs.85)) that specifies an Authentication Grant Identifier (AGID). The AGID identifies the secure session to release. Caller can release all AGIDs for both Advanced Access Content System (AACS) and Content-Scrambling System (CSS) secure sessions by specifying a value DVD_END_ALL_SESSIONS.

### Input buffer length

Size of a [DVD_SESSION_ID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff553743(v=vs.85)).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes transferred. The **Status** field is set to STATUS_SUCCESS or possibly STATUS_INSUFFICIENT_RESOURCES.
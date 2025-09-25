# IOCTL_DVD_START_SESSION IOCTL

## Description

Returns an authentication grant ID (AGID) as a DVD session ID, which a caller must pass to the device in all subsequent operations in a DVD session.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns an integer authentication grant ID of type DVD_SESSION_ID in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

Length of a [DVD_SESSION_ID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff553743(v=vs.85)).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to **sizeof**(DVD_SESSION_ID). The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INSUFFICIENT_RESOURCES.
# IOCTL_DVD_END_SESSION IOCTL

## Description

Ends a DVD session by invalidating its authentication grant ID (AGID).

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains the session ID.

### Input buffer length

Length of a session ID.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero. The **Status** field is set to STATUS_SUCCESS.
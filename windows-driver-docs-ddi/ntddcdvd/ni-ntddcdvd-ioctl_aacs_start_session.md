# IOCTL_AACS_START_SESSION IOCTL

## Description

Retrieves an Authentication Grant Identifier (AGID) that identifies a secure session.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a value of type [DVD_SESSION_ID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff553743(v=vs.85)) that specifies an Authentication Grant Identifier (AGID). The AGID identifies the secure session.

### Output buffer length

Length of a [DVD_SESSION_ID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff553743(v=vs.85)).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes transferred. The **Status** field is set to STATUS_SUCCESS or possibly STATUS_INSUFFICIENT_RESOURCES.

## Remarks

The IOCTL_AACS_START_SESSION request corresponds to one of the steps of the Advanced Access Content System (AACS) authentication algorithm (AACS-Auth). For a complete description of AACS-Auth, see the *Advanced Access Content System, Introduction and Common Cryptographic Elements* specification that is published by Advanced Access Content System Licensing Administrator (AACS LA).

After obtaining the AGID, host software uses the AGID to associate subsequent AACS IOCTLs with the secure session. Unlike the AGID that is used with DVD Content-Scrambling System (CSS) encryption, the AACS AGID is valid for the transfer of only one piece of protected information.
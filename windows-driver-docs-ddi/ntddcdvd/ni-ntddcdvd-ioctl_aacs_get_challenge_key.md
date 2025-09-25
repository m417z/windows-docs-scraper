# IOCTL_AACS_GET_CHALLENGE_KEY IOCTL

## Description

Queries the logical unit for the device's challenge key. The challenge key consists of a point on an elliptic curve and its associated signature.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a value of type [DVD_SESSION_ID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff553743(v=vs.85)) that specifies an Authentication Grant Identifier (AGID). The AGID identifies the secure session.

### Input buffer length

Length of a [DVD_SESSION_ID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff553743(v=vs.85)).

### Output buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains the drive challenge key with a format of [AACS_CHALLENGE_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_challenge_key).

### Output buffer length

Length of an [AACS_CHALLENGE_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_challenge_key).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes transferred. The **Status** field is set to STATUS_SUCCESS or possibly STATUS_INSUFFICIENT_RESOURCES.

## Remarks

 The IOCTL_AACS_GET_CHALLENGE_KEY request corresponds to the step in the Advanced Access Content System (AACS) authentication algorithm (AACS-Auth) in which the drive provides the host with a point on the curve. For a complete description of AACS-Auth, see the *Advanced Access Content System, Introduction and Common Cryptographic Elements* specification that is published by Advanced Access Content System Licensing Administrator (AACS LA).
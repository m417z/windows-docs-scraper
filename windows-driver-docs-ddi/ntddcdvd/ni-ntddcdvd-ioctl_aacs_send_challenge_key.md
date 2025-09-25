# IOCTL_AACS_SEND_CHALLENGE_KEY IOCTL

## Description

Sends the host's challenge key to the logical unit. The host's challenge key consists of a point on an elliptic curve and its associated signature.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a [AACS_SEND_CHALLENGE_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_send_challenge_key) structure.

### Input buffer length

Length of an [AACS_SEND_CHALLENGE_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_send_challenge_key) structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes transferred. The **Status** field is set to STATUS_SUCCESS or possibly STATUS_INSUFFICIENT_RESOURCES.

## Remarks

The IOCTL_AACS_SEND_CHALLENGE_KEY request corresponds to the step in the Advanced Access Content System (AACS) authentication algorithm (AACS-Auth) in which the host provides the drive a point on the curve. For a complete description of AACS-Auth, see the *Advanced Access Content System, Introduction and Common Cryptographic Elements* specification that is published by Advanced Access Content System Licensing Administrator (AACS LA).
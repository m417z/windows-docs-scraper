# IOCTL_AACS_SEND_CERTIFICATE IOCTL

## Description

Sends the host certificate to the logical unit.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains host certificate of type [AACS_SEND_CERTIFICATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_send_certificate).

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location indicates the size, in bytes, of the buffer, which must be >= **sizeof**(AACS_SEND_CERTIFICATE).

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location indicates the size, in bytes, of the buffer, which must be >= **sizeof**(AACS_SEND_CERTIFICATE).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes transferred. The **Status** field is set to STATUS_SUCCESS or possibly STATUS_INSUFFICIENT_RESOURCES.

## Remarks

The IOCTL_AACS_SEND_CERTIFICATE request corresponds to the step in the Advanced Access Content System (AACS) authentication algorithm (AACS-Auth) in which the host sends its certificate and nonce to the drive. For a complete description of AACS-Auth, see the *Advanced Access Content System, Introduction and Common Cryptographic Elements* specification that is published by Advanced Access Content System Licensing Administrator (AACS LA).
# IOCTL_AACS_READ_MEDIA_ID IOCTL

## Description

Reads the Advanced Access Content System (AACS)-specific media identifier data.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a value of type [DVD_SESSION_ID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff553743(v=vs.85)) that specifies an Authentication Grant Identifier (AGID).

### Input buffer length

Length of a [DVD_SESSION_ID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff553743(v=vs.85)).

### Output buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains the value of type [AACS_MEDIA_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_media_id) that specifies the media ID.

### Output buffer length

Length of a [AACS_MEDIA_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_media_id).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes transferred. The **Status** field is set to STATUS_SUCCESS or possibly STATUS_INSUFFICIENT_RESOURCES.

## Remarks

The IOCTL_AACS_READ_MEDIA_ID request corresponds to the part of the AACS authentication protocol that is responsible for transferring the media identifier. For a complete description of this protocol, see the *Advanced Access Content System, Introduction and Common Cryptographic Elements* specification that is published by Advanced Access Content System Licensing Administrator (AACS LA).

The AGID is automatically released after the IOCTL_AACS_READ_MEDIA_ID request completes.
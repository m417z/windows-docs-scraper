# IOCTL_AACS_READ_BINDING_NONCE IOCTL

## Description

Reads the Advanced Access Content System (AACS) binding nonce starting at the specified byte offset on the disc, as part of the protocol for reading a protected data area.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a structure of type [AACS_READ_BINDING_NONCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_read_binding_nonce) that specifies the [DVD_SESSION_ID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff553743(v=vs.85)), the starting logical block address and the number of sectors for which the logical unit should generate a binding nonce.

### Input buffer length

Length of a [AACS_READ_BINDING_NONCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_read_binding_nonce) structure.

### Output buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains the value of type [AACS_BINDING_NONCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_binding_nonce) that specifies the binding nonce.

### Output buffer length

Length of a [AACS_READ_BINDING_NONCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_read_binding_nonce) structure.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes transferred. The **Status** field is set to STATUS_SUCCESS or possibly STATUS_INSUFFICIENT_RESOURCES.

## Remarks

The IOCTL_AACS_READ_BINDING_NONCE request corresponds to the part of the AACS authentication protocol that is responsible for reading a protected data area. For a complete description of this protocol, see the *Advanced Access Content System, Introduction and Common Cryptographic Elements* specification that is published by Advanced Access Content System Licensing Administrator (AACS LA).

The AGID is automatically released after the IOCTL_AACS_READ_BINDING_NONCE request completes.

Clients that do not use file system support must set the **Handle** member of [AACS_READ_BINDING_NONCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_read_binding_nonce) to INVALID_HANDLE_VALUE and specify explicit values for the **StartLBA** and **NumberOfSectors** members.

When the CDROM driver receives the IOCTL, it will fail the IOCTL immediately with STATUS_INVALID_PARAMETER if either the **StartLBA** field is set to MAXULONGLONG or the **NumberOfSectors** field is set to MAXULONG. In this case, the caller should release the AGID manually.
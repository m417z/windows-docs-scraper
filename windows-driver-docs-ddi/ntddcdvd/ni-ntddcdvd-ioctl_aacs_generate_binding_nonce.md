# IOCTL_AACS_GENERATE_BINDING_NONCE IOCTL

## Description

Reads the Advanced Access Content System (AACS) binding nonce starting at the specified byte offset on the disc, as part of the protocol for writing to a protected data area.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a structure of type [AACS_READ_BINDING_NONCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_read_binding_nonce) that specifies the [DVD_SESSION_ID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff553743(v=vs.85)), the starting logical block address and the number of sectors for which the logical unit should generate a binding nonce.

### Input buffer length

Length of an [AACS_READ_BINDING_NONCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_read_binding_nonce).

### Output buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains the value of type [AACS_BINDING_NONCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_binding_nonce) that specifies the binding nonce.

### Output buffer length

Length of an [AACS_BINDING_NONCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_binding_nonce).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes transferred. The **Status** field is set to STATUS_SUCCESS or possibly STATUS_INSUFFICIENT_RESOURCES.

## Remarks

The IOCTL_AACS_GENERATE_BINDING_NONCE request corresponds to the part of the AACS authentication protocol that is responsible for writing to a protected data area. For a complete description of this protocol, see the *Advanced Access Content System, Introduction and Common Cryptographic Elements* specification that is published by Advanced Access Content System Licensing Administrator (AACS LA).

The IOCTL_AACS_GENERATE_BINDING_NONCE request requires a single available AGID during its processing, and the AGID is ***not*** automatically released after the request completes. The AGID remains valid until it is explicitly invalidated or until the drive generates a power-on reset, hard reset, or media ejection event. However, the AGID cannot be reused with other requests.

It is recommended that you wait for the completion of all other requests that use secure sessions with AGIDs before making an IOCTL_AACS_GENERATE_BINDING_NONCE request.

Clients that do not use file system support must set the **Handle** member of [AACS_READ_BINDING_NONCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_read_binding_nonce) to INVALID_HANDLE_VALUE and specify explicit values for the **StartLBA** and **NumberOfSectors** members.
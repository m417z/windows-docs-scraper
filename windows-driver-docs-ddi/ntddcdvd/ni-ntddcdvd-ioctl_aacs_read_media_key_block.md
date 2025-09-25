# IOCTL_AACS_READ_MEDIA_KEY_BLOCK IOCTL

## Description

Queries the logical unit for the Media Key Block (MKB).

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains the AACS_LAYER_NUMBER number of the layer. The AACS_LAYER_NUMBER is an unsigned long integer value in the range 0 to 255 inclusive that specifies the layer of the media to which a command applies.

`typedef ULONG AACS_LAYER_NUMBER, *PAACS_LAYER_NUMBER;`

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location indicates the size, in bytes, of the buffer, which must be >= **sizeof**(AACS_LAYER_NUMBER).

### Output buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains an opaque, variable-length MKB. The size of the MKB is always a multiple of 32,768 (0x8000).

### Output buffer length

Length of a variable-length MKB.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes transferred. The **Status** field is set to STATUS_SUCCESS if the operation succeeds. If **Irp->AssociatedIrp.SystemBuffer** is **NULL** or the buffer at **Irp->AssociatedIrp.SystemBuffer** is not sufficient to contain the full MKB, the operation fails and returns a status of STATUS_BUFFER_TOO_SMALL, and the required buffer size is returned in **IoStatus.Information**.

## Remarks

The storage stack uses a READ DISC STRUCTURE command (format 0x17) with Advanced Access Control System (AACS) extensions to retrieve the MKB. IOCTL_AACS_READ_MEDIA_KEY_BLOCK request will not work if the media in the logical unit is not AACS protected.

Unlike the MKB that is used with Content-Scrambling System (CSS) encryption, AACS MKBs are self-protected with digital signatures. The MKB structure is fully documented in the *Advanced Access Content System, Introduction and Common Cryptographic Elements* specification that is published by Advanced Access Content System Licensing Administrator (AACS LA).

The IOCTL_AACS_READ_MEDIA_KEY_BLOCK request corresponds to one of the steps of the Advanced Access Content System (AACS) authentication algorithm (AACS-Auth). For a complete description of AACS-Auth, see the *Advanced Access Content System, Introduction and Common Cryptographic Elements* specification.
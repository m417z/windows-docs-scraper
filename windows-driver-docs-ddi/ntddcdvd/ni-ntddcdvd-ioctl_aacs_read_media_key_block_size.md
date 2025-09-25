# IOCTL_AACS_READ_MEDIA_KEY_BLOCK_SIZE IOCTL

## Description

Queries the logical unit for the size of the buffer that is required to hold the Advanced Access Control System (AACS) Media Key Block (MKB).

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains the AACS_LAYER_NUMBER number of the layer. The AACS_LAYER_NUMBER is an unsigned long integer value in the range 0 to 255 inclusive that specifies the layer of the media to which a command applies.

`typedef ULONG AACS_LAYER_NUMBER, *PAACS_LAYER_NUMBER;`

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location indicates the size, in bytes, of the buffer, which must be >= **sizeof**(AACS_LAYER_NUMBER).

### Output buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a ULONG that holds the size in bytes of the full AACS MKB for this media.

### Output buffer length

Use this value to determine the size of the buffer to allocate for [IOCTL_AACS_READ_MEDIA_KEY_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_read_media_key_block). The size is always a multiple of 32,768 (0x8000).

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes transferred. The **Status** field is set to STATUS_SUCCESS if the operation succeeds. The following failure codes are common with this operation:

**STATUS_COPY_PROTECTION_FAILURE or STG_E_STATUS_COPY_PROTECTION_FAILURE**

Failure of one of the copy protection mechanisms.

**STATUS_CSS_AUTHENTICATION_FAILURE or STG_E_CSS_AUTHENTICATION_FAILURE**

The authentication process has failed.

**STATUS_CSS_KEY_NOT_ESTABLISHED or STG_E_CSS_KEY_NOT_ESTABLISHED**

The AGID for AACS has not been established.

**STATUS_CSS_KEY_NOT_PRESENT or STG_E_CSS_KEY_NOT_PRESENT**

No AACS protection exists for this media.

## Remarks

The IOCTL_AACS_READ_MEDIA_KEY_BLOCK_SIZE request will not work if the media in the logical unit is not AACS protected.

The IOCTL_AACS_READ_MEDIA_KEY_BLOCK_SIZE request corresponds to one of the steps of the Advanced Access Content System (AACS) authentication algorithm (AACS-Auth). For a complete description of AACS-Auth, see the *Advanced Access Content System, Introduction and Common Cryptographic Elements* specification that is published by Advanced Access Content System Licensing Administrator (AACS LA).
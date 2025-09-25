# _AACS_READ_BINDING_NONCE structure

## Description

The AACS_READ_BINDING_NONCE structure is a wrapper for the Authentication Grant Identifier (AGID) and logical block address (LBA)/length pair that are required to read a nonce.

## Members

### `SessionId`

A value of type DVD_SESSION_ID that specifies an AGID. The client obtains this value by a successful call to IOCTL_AACS_START_SESSION.

### `NumberOfSectors`

The number of sectors in the area for which the binding nonce is retrieved. To request the nonce for a file, the caller of IOCTL_AACS_READ_BINDING_NONCE must set this member to MAXULONGLONG.

### `StartLba`

The starting logical block address of the area for which the binding nonce is retrieved. To request the nonce for a file, the caller of [IOCTL_AACS_GENERATE_BINDING_NONCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_generate_binding_nonce) or [IOCTL_AACS_READ_BINDING_NONCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_read_binding_nonce) must set this member to MAXULONGLONG.

### `Handle`

The file handle. Callers of IOCTL_AACS_READ_BINDING_NONCE that use file system support can set this member to a file handle. If the caller does not use file system support, this member must have a value of INVALID_HANDLE_VALUE.

### `ForceStructureLengthToMatch64bit`

## Remarks

Clients retrieve the binding nonce with an [IOCTL_AACS_GENERATE_BINDING_NONCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_generate_binding_nonce) request or an [IOCTL_AACS_READ_BINDING_NONCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_read_binding_nonce) request.

## See also

[AACS_BINDING_NONCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_binding_nonce)

[IOCTL_AACS_GENERATE_BINDING_NONCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_generate_binding_nonce)

[IOCTL_AACS_READ_BINDING_NONCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_read_binding_nonce)
# _AACS_CERTIFICATE structure

## Description

The AACS_CERTIFICATE structure contains a cryptographically random 160-bit value, followed by a 92-byte certificate.

## Members

### `Nonce`

A cryptographically random 160-bit nonce value.

### `Certificate`

A 92-byte certificate.

## Remarks

Clients retrieve an Advanced Access Content System (AACS) certificate with an [IOCTL_AACS_GET_CERTIFICATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_get_certificate) request. Clients send certificates in a [AACS_SEND_CERTIFICATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_send_certificate) structure with an [IOCTL_AACS_SEND_CERTIFICATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_send_certificate) request.

## See also

[IOCTL_AACS_GET_CERTIFICATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_get_certificate)
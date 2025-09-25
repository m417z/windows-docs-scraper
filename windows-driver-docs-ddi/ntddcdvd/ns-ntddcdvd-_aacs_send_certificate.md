# _AACS_SEND_CERTIFICATE structure

## Description

The AACS_SEND_CERTIFICATE structure is a wrapper for both an Advanced Access Content System (AACS) certificate and an Authentication Grant Identifier (AGID).

## Members

### `SessionId`

A value of type DVD_SESSION_ID that specifies an AGID.

### `Certificate`

A structure of type [AACS_CERTIFICATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_certificate) that specifies the certificate to retrieve.

## Remarks

Clients send an Advanced Access Content System (AACS) certificate with an [IOCTL_AACS_SEND_CERTIFICATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_send_certificate) request. Clients retrieve an AACS certificate with an [IOCTL_AACS_GET_CERTIFICATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_get_certificate) request.

## See also

[AACS_CERTIFICATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-_aacs_certificate)

[DVD_SESSION_ID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff553743(v=vs.85))

[IOCTL_AACS_GET_CERTIFICATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_get_certificate)
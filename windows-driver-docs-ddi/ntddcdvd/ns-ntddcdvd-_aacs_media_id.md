# _AACS_MEDIA_ID structure

## Description

The AACS_MEDIA_ID structure contains an Advanced Access Content System (AACS) media identifier and corresponding message authentication code (MAC).

## Members

### `MediaID`

The media identifier.

### `MAC`

The message authentication code (MAC) that the client uses to verify that the MediaID is for the current AACS authentication sequence.

## Remarks

Clients retrieve the AACS certificate with an [IOCTL_AACS_READ_MEDIA_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_read_media_id) request.

## See also

[IOCTL_AACS_READ_MEDIA_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_read_media_id)
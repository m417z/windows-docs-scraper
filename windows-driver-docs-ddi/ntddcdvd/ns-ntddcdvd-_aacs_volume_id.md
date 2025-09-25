# _AACS_VOLUME_ID structure

## Description

The AACS_VOLUME_ID structure contains an Advanced Access Content System (AACS) volume ID and the corresponding message authentication code (MAC).

## Members

### `VolumeID`

The volume identifier.

### `MAC`

The message authentication code (MAC) that the client uses to verify that the volume identifier is for the current AACS authentication sequence.

## Remarks

Clients retrieve an AACS volume ID with an [IOCTL_AACS_READ_VOLUME_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_read_volume_id) request.

## See also

[IOCTL_AACS_READ_VOLUME_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_read_volume_id)
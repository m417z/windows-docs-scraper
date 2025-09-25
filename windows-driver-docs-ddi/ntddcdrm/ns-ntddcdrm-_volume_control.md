# _VOLUME_CONTROL structure

## Description

The VOLUME_CONTROL structure is used in conjunction with the [IOCTL_CDROM_GET_VOLUME](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_volume) request to retrieve volume values for up to four audio ports.

## Members

### `PortVolume`

Pointer to an array of volume values, one for each of the ports, with a maximum of four ports.

## See also

[IOCTL_CDROM_GET_VOLUME](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_volume)
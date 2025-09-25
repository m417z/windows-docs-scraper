# _DVD_MANUFACTURER_DESCRIPTOR structure

## Description

The DVD_MANUFACTURER_DESCRIPTOR structure is used in conjunction with the [IOCTL_DVD_READ_STRUCTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_read_structure) request to retrieve a DVD manufacturer descriptor.

## Members

### `ManufacturingInformation`

Contains an array holding the manufacturing information taken from the DVD media lead-in area. In the case of DVD-R multisession disc, this information is taken from the last border-in area.

## See also

[IOCTL_DVD_READ_STRUCTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_read_structure)
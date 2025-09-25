# _DVD_BCA_DESCRIPTOR structure

## Description

The DVD_BCA_DESCRIPTOR structure is used in conjunction with the [IOCTL_DVD_READ_STRUCTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_read_structure) request to retrieve a DVD burst cutting area (BCA) descriptor.

## Members

### `BCAInformation`

Contains an array that holds vendor-defined information retrieved from the burst cutting area.

## Remarks

The contents of the BCA region are specified by the media manufacturer.

## See also

[IOCTL_DVD_READ_STRUCTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_read_structure)
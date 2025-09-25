# _DVD_COPYRIGHT_DESCRIPTOR structure

## Description

The DVD_COPYRIGHT_DESCRIPTOR structure is used in conjunction with the [IOCTL_DVD_READ_STRUCTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_read_structure) request to retrieve a DVD copyright descriptor.

## Members

### `CopyrightProtectionType`

Indicates, when set to 1, the presence of data specific to a copyright protection system. A value of zero indicates there is no such data. All other values are reserved.

### `RegionManagementInformation`

Indicates in which regions of the world the disc can be played. Each bit represents one of eight regions. If a bit is set, the disc cannot be played in the corresponding region. If a bit is not set, the disc can be played in the corresponding region.

### `Reserved`

Reserved.

## See also

[IOCTL_DVD_READ_STRUCTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_read_structure)
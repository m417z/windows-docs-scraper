# _DVD_REGION structure

## Description

The DVD_REGION structure is used in conjunction with the [IOCTL_DVD_GET_REGION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_get_region) request to retrieve region playback control (RPC) information for a DVD device.

## Members

### `CopySystem`

Indicates the copyright protection type. For more information about copyright protection types, see the *SCSI Multimedia Commands - 3* (MMC-3) specification.

### `RegionData`

Indicates the region code of the currently mounted DVD media. This is an eight-bit bitmask, with one bit for each DVD region. A value of 0x00 means that no region is specified.

### `SystemRegion`

Indicates the region code of the DVD player. This is an eight-bit bitmask, with one bit for each system region. A value of 0x00 means that no region is specified.

### `ResetCount`

Indicates the remaining number of times the DVD device's region code can be changed by the user. This member can hold a value between 0 and 7.

## See also

[IOCTL_DVD_GET_REGION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_get_region)
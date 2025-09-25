# DVD_READ_STRUCTURE structure

## Description

The DVD_READ_STRUCTURE structure is used in conjunction with the [IOCTL_DVD_READ_STRUCTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_read_structure) request to retrieve a DVD descriptor containing information about a DVD disc.

## Members

### `BlockByteOffset`

Contains an offset to the logical block address of the descriptor to be retrieved.

### `Format`

Indicates the type of DVD descriptor to retrieve. See the [DVD_STRUCTURE_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ne-ntddcdvd-dvd_structure_format) enumeration type for further information about the values that can be assigned to this member.

### `SessionId`

Contains the DVD session ID.

### `LayerNumber`

Contains the number of the layer where the descriptor is to be retrieved.

## Remarks

The DVD_READ_STRUCTURE structure contains data such as copyright information, or manufacturer-specific information.

## See also

[DVD_STRUCTURE_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ne-ntddcdvd-dvd_structure_format)

[IOCTL_DVD_READ_STRUCTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_read_structure)
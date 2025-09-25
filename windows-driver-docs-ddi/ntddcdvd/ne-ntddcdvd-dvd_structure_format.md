# DVD_STRUCTURE_FORMAT enumeration

## Description

The DVD_STRUCTURE_FORMAT enumeration type is used in conjunction with the [IOCTL_DVD_READ_STRUCTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_read_structure) request and the [DVD_READ_STRUCTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-dvd_read_structure) structure to retrieve a DVD descriptor.

## Constants

### `DvdPhysicalDescriptor`

Indicates that caller is requesting a DVD physical descriptor.

### `DvdCopyrightDescriptor`

Indicates that caller is requesting a DVD copyright descriptor containing copyright information from the DVD lead-in area.

### `DvdDiskKeyDescriptor`

Indicates that caller is requesting a DVD key descriptor containing the disc key obfuscated using the bus key.

### `DvdBCADescriptor`

Indicates that caller is requesting a DVD burst cutting area (BCA) descriptor.

### `DvdManufacturerDescriptor`

Indicates that caller is requesting a DVD manufacturer descriptor containing disc manufacturing information from the DVD lead-in area.

### `DvdMaxDescriptor`

Indicates that caller is requesting a DVD max descriptor.

## See also

[DVD_READ_STRUCTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ns-ntddcdvd-dvd_read_structure)

[IOCTL_DVD_READ_STRUCTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_dvd_read_structure)
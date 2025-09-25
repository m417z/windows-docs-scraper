# _DEVICE_TRIM_DESCRIPTOR structure

## Description

The DEVICE_TRIM_DESCRIPTOR structure is used in conjunction with the [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) request to retrieve the trim descriptor data for a device.

## Members

### `Version`

Contains the size of the structure DEVICE_TRIM_DESCRIPTOR. The value of this member will change as members are added to the structure.

### `Size`

Specifies the total size of the descriptor, in bytes.

### `TrimEnabled`

Specifies whether trim is enabled for the device.

## Remarks

Storage class drivers issue a device-control request with the I/O control code [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) to retrieve this structure, which contains trim information for the device. The structure can be retrieved either from the device object for the bus or from an FDO, which forwards the request to the underlying bus.

## See also

[IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)
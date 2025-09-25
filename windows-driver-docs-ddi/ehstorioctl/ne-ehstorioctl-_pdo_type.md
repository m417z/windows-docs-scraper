# _PDO_TYPE enumeration

## Description

This enumeration describes the types of Physical Device Objects (PDOs).

## Constants

### `PDO_TYPE_UNDEFINED`

Types either enumerated or provided as filter parameter to [IOCTL_EHSTOR_DEVICE_ENUMERATE_PDOS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_device_enumerate_pdos)

### `PDO_TYPE_DISK`

This value indicates the PDO is for a logical disk device.

### `PDO_TYPE_CONTROL`

This value indicates the PDO is for a logical control device.

### `PDO_TYPE_SILO`

This value indicates the PDO is for a logical silo device.

### `PDO_TYPE_THIS`

## See also

[IOCTL_EHSTOR_DEVICE_ENUMERATE_PDOS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_device_enumerate_pdos)
# _ENUM_PDO_RESULTS structure

## Description

This structure describes a result set of Physical Device Objects (PDOs) that are enumerated with [IOCTL_EHSTOR_DEVICE_ENUMERATE_PDOS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_device_enumerate_pdos).

## Members

### `cEntries`

This member indicates the number of entries in the array of ENUM_PDO_ENTRY structures.

### `rgEntries`

This member contains the array of ENUM_PDO_ENTRY structures.

## See also

[IOCTL_EHSTOR_DEVICE_ENUMERATE_PDOS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_device_enumerate_pdos)
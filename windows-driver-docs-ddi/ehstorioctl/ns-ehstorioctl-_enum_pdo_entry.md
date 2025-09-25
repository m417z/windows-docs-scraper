# _ENUM_PDO_ENTRY structure

## Description

This structure describes a single entry in a result set of Physical Device Objects (PDOs) that are enumerated with [IOCTL_EHSTOR_DEVICE_ENUMERATE_PDOS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_device_enumerate_pdos).

## Members

### `type`

This member indicates the type of the PDO that is being identified, as defined by PDO_TYPE.

### `state`

This member contains information about the current PnP state of the PDO, as defined by PDO_STATE.

### `capabilities`

This member contains a bitmask with bits indicating information about the silo represented by the PDO in question, as defined by PDO_CAPS.

### `ulSTID`

This member contains the silo type identifier, as defined and assigned by the IEEE 1667 working group.

### `bSpecificationMajor`

### `bSpecificationMinor`

### `bImplementationMajor`

### `bImplementationMinor`

### `wszDeviceInstancePath`

The string contained in this member is the device instance path in a form suitable for use with the Win32 API CreateFile routine.

## See also

[IOCTL_EHSTOR_DEVICE_ENUMERATE_PDOS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_device_enumerate_pdos)
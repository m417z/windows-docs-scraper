# _ACPI_DEVICE_INFORMATION_OUTPUT_BUFFER structure

## Description

The ACPI_DEVICE_INFORMATION_OUTPUT_BUFFER structure contains output arguments from the IOCTL_ACPI_GET_DEVICE_INFORMATION control method.

## Members

### `Signature`

A unique identifier for the IOCTL that returns this buffer. Used for verification.

### `Size`

The size, in bytes, of the ACPI_DEVICE_INFORMATION_OUTPUT_BUFFER structure.

### `Revision`

Revision of the ACPI_DEVICE_INFORMATION_OUTPUT_BUFFER structure.

### `Reserved0`

Reserved. Do not use.

### `VendorIdStringOffset`

The offset from the beginning of this structure to the beginning of the **VendorIDString** member. This string uniquely identifies The manufacturer and the device itself.

### `VendorStringLength`

The length of the **VendorIDString** member.

### `DeviceIdStringOffset`

The offset from the beginning of this structure to the beginning of the **DeviceIDString** member. This string uniquely identifies the device.

### `SubSystemIdStringOffset`

The offset from the beginning of this structure to the beginning of the **SubSystemIDString** member. This string uniquely identifies the manufacturer and the subsystem (chip or board) into which the device is integrated.

### `SubSystemStringLength`

The length of the **SubSystemIDString** member.

### `SubDeviceIdStringOffset`

The offset from the beginning of this structure to the beginning of the **DeviceIDString** member. This string uniquely identifies the subsystem.

### `InstanceIdLength`

The length of the **InstanceIDString** member.

### `InstanceIdOffset`

The offset from the beginning of this structure to the beginning of the **InstanceIDString** member. This string uniquely identifies the device amongst all such devices on the platform.

### `BaseClassCode`

A number identifying the class of the device.

For more information, see the [Peripheral Component Interconnect Special Interest Group (PCI-SIG)](https://pcisig.com/specifications) specifications for baseclass code definitions.

### `HardwareRevision`

A number identifying the hardware revision of the device.

### `ProgrammingInterface`

A number identifying the programming interface of the device.

For more information, see the [Peripheral Component Interconnect Special Interest Group (PCI-SIG)](https://pcisig.com/specifications) specifications for class programming interface definitions.

### `Reserved1`

Reserved. Do not use.

### `SubClassCode`

A number identifying the subclass of the device.

For more information, see the [Peripheral Component Interconnect Special Interest Group (PCI-SIG)](https://pcisig.com/specifications) specifications for subclass code definitions.

## Remarks

Appended after the ACPI_DEVICE_INFORMATION_OUTPUT_BUFFER are the SubSystemIdString, VendorIdString, and InstanceIdString strings, described as follows:

### BYTE[SubVendorStringLength+1] SubSystemIdString

A string of **SubSystemStringLength** in length which contains the subsystem's manufacturer and subsystem identifiers.

### BYTE[VendorIdStringOffset+1] VendorIdString

A string of **VendorStringLength** in length which contains the device's manufacturer and device identifiers.

### BYTE[InstanceIdOffset+1] InstanceIdString

A string of **InstanceIDLength** in length which contains a number that uniquely identifies the device amongst all such devices on the platform (i.e. all devices with the same Vendor, Device, SubsystemVendor and SubsystemDevice IDs.)

## See also

[IOCTL_ACPI_GET_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_get_device_information)
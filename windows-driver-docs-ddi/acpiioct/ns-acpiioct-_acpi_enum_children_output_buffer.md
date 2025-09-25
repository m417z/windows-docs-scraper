# _ACPI_ENUM_CHILDREN_OUTPUT_BUFFER structure

## Description

The ACPI_ENUM_CHILDREN_OUTPUT_BUFFER structure contains an array of object names in an ACPI namespace.

## Members

### `Signature`

The signature of the output buffer, which must be set to ACPI_ENUM_CHILDREN_OUTPUT_BUFFER_SIGNATURE.

### `NumberOfChildren`

The number of elements of type [ACPI_ENUM_CHILD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_enum_child) in the **Children** array.

### `Children`

An array of elements of type ACPI_ENUM_CHILD. Each ACPI_ENUM_CHILD structure contains the path and name of an object in the ACPI namespace.

## Remarks

A driver for a device uses an [IOCTL_ACPI_ENUM_CHILDREN](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_enum_children) request to enumerate the child objects of the device. The enumerated child objects can be devices or any object of a supplied name. This request returns an ACPI_ENUM_CHILDREN_OUTPUT_BUFFER structure, which includes the **Children** member that contains an array of [ACPI_ENUM_CHILD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_enum_child) structures.

For information about how to enumerate child objects of a device, see [Enumerating Child Devices and Control Methods](https://learn.microsoft.com/windows-hardware/drivers/acpi/enumerating-child-devices-and-control-methods).

## See also

[ACPI_ENUM_CHILD](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_enum_child)

[IOCTL_ACPI_ENUM_CHILDREN](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_enum_children)
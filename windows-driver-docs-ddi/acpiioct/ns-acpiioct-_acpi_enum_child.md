# _ACPI_ENUM_CHILD structure

## Description

The ACPI_ENUM_CHILD structure is a member of the [ACPI_ENUM_CHILDREN_OUTPUT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_enum_children_output_buffer) structure and contains the full path and name of an object in an ACPI namespace.

## Members

### `Flags`

A flag value that the ACPI driver sets to ACPI_OBJECT_HAS_CHILDREN if the enumerated child object has child objects; otherwise, the ACPI driver does not set this value.

### `NameLength`

The number of characters, including a NULL-terminated character, in the ASCII string that the **Name** array contains.

### `Name`

A NULL-terminated ASCII string that contains the path and name of an object in an ACPI namespace. For more information about the format of the path and name, see the Remarks section later in this topic.

## Remarks

A driver for a device uses an [IOCTL_ACPI_ENUM_CHILDREN](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_enum_children) request to enumerate the child objects of the device. The enumerated child objects can be devices or any object of a supplied name. This request returns an ACPI_ENUM_CHILDREN_OUTPUT_BUFFER structure, which includes the **Children** member that contains an array of ACPI_ENUM_CHILD structures.

The path and name that are contained in a **Name** member are in the standard format for a fully qualified path and name of an object in an ACPI namespace. For example, assume that a device named 'ABCD' is an immediate child of the root of an ACPI namespace, that device 'ABCD' has a child device named 'CHLD,' and that child device 'CHLD' has an immediate child object named '_FOO.' In this case, **Name** would contain '\ABCD.CHLD._FOO.'

For information about how to enumerate child objects of a device, see [Enumerating Child Devices and Control Methods](https://learn.microsoft.com/windows-hardware/drivers/acpi/enumerating-child-devices-and-control-methods).

## See also

[ACPI_ENUM_CHILDREN_OUTPUT_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ns-acpiioct-_acpi_enum_children_output_buffer)

[IOCTL_ACPI_ENUM_CHILDREN](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_enum_children)
# _ACPI_ENUM_CHILDREN_INPUT_BUFFER structure

## Description

The ACPI_ENUM_CHILDREN_INPUT_BUFFER structure is used as input to an [IOCTL_ACPI_ENUM_CHILDREN](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_enum_children) request. The structure specifies which child objects to enumerate in the namespace of the device to which the request is sent.

## Members

### `Signature`

The signature of the input buffer, which must be set to ACPI_ENUM_CHILDREN_INPUT_BUFFER_SIGNATURE.

### `Flags`

A flag that determines which objects the ACPI driver enumerates, as described in the Remarks section later in this topic.

### `NameLength`

The number of ASCII characters, including a NULL-terminator, that the **Name** array contains.

### `Name`

A NULL-terminated, four-character ASCII string that contains the name of a child object that the ACPI driver uses to restrict the enumeration to child objects of the same name. For more information about how to supply an object name, see the Remarks section later in this topic.

## Remarks

[IOCTL_ACPI_ENUM_CHILDREN](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_enum_children) supports the following types of enumerations, depending on how the **Flags** member is set in the corresponding ACPI_ENUM_CHILDREN_INPUT_BUFFER structure:

For information about how to enumerate child objects of a device, see [Enumerating Child Devices and Control Methods](https://learn.microsoft.com/windows-hardware/drivers/acpi/enumerating-child-devices-and-control-methods).

## See also

[IOCTL_ACPI_ENUM_CHILDREN](https://learn.microsoft.com/windows-hardware/drivers/ddi/acpiioct/ni-acpiioct-ioctl_acpi_enum_children)
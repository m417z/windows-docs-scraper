# _PEP_ACPI_OBJECT_NAME_WITH_TYPE structure (pep_x.h)

## Description

The **PEP_ACPI_OBJECT_NAME_WITH_TYPE** structure that specifies both the path-relative name of an ACPI object and the type of this object.

## Members

### `Name`

A [PEP_ACPI_OBJECT_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_object_name) structure that contains the four-character name of the ACPI object.

### `Type`

A [PEP_ACPI_OBJECT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_acpi_object_type) enumeration value that indicates the type of ACPI object. Currently, the only supported object type is a control method.

## Remarks

The **Objects** member of the [PEP_ACPI_ENUMERATE_DEVICE_NAMESPACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_enumerate_device_namespace) structure is the first element in an array of **PEP_ACPI_OBJECT_NAME_WITH_TYPE** structures.

## See also

[PEP_ACPI_ENUMERATE_DEVICE_NAMESPACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_enumerate_device_namespace)

[PEP_ACPI_OBJECT_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_object_name)

[PEP_ACPI_OBJECT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_acpi_object_type)
# _PEP_ACPI_OBJECT_TYPE enumeration (pep_x.h)

## Description

The **PEP_ACPI_OBJECT_TYPE** enumeration indicates the type of ACPI object.

## Constants

### `PepAcpiObjectTypeMethod`

The object is an ACPI control method.

### `PepAcpiObjectTypeDevice`

### `PepAcpiObjectTypeMaximum`

Reserved for use by the operating system.

## Remarks

The **Type** member of the [PEP_ACPI_QUERY_OBJECT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_query_object_information) structure is an **PEP_ACPI_OBJECT_TYPE** enumeration value.

## See also

[PEP_ACPI_QUERY_OBJECT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_query_object_information)
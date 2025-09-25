# _PEP_ACPI_OBJECT_NAME structure (pep_x.h)

## Description

The **PEP_ACPI_OBJECT_NAME** union contains the four-character name of an ACPI object.

## Members

### `Name`

The object name stored as an array of four 8-bit unsigned characters.

### `NameAsUlong`

The object name stored as a single 32-bit unsigned integer value.

## Remarks

The *Name* member of the [PEP_ACPI_OBJECT_NAME_WITH_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_object_name_with_type) structure is a **PEP_ACPI_OBJECT_NAME** union. Also, the *Name* member of the [PEP_ACPI_QUERY_OBJECT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_query_object_information) structure is a **PEP_ACPI_OBJECT_NAME** union.

## See also

- [PEP_ACPI_OBJECT_NAME_WITH_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_object_name_with_type)
- [PEP_ACPI_QUERY_OBJECT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_query_object_information)
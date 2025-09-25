# _PEP_ACPI_REQUEST_CONVERT_TO_BIOS_RESOURCES structure (pepfx.h)

## Description

The **PEP_ACPI_REQUEST_CONVERT_TO_BIOS_RESOURCES** structure is used in the process of converting ACPI resources to BIOS resources by one of the [PEP initialization functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

## Members

### `TranslationStatus`

The result code from the resource translation call.

### `InputBuffer`

A pointer to a [PEP_ACPI_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_resource) containing the input buffer.

### `InputBufferSize`

The size of the input buffer.

### `OutputBuffer`

A pointer to the output buffer containing the translated structure.

### `OutputBufferSize`

The size of the output buffer.

### `Flags`

The value contained in the [PEP_ACPI_RESOURCE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_resource_flags) structure.

## See also

[PEP initialization functions](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[PEP_ACPI_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_resource)

[PEP_ACPI_RESOURCE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_resource_flags)
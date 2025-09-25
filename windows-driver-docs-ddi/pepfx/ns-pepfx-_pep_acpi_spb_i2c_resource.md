# _PEP_ACPI_SPB_I2C_RESOURCE structure (pepfx.h)

## Description

The **PEP_ACPI_SPB_I2C_RESOURCE** structure describes an ACPI I2C serial bus resource.

## Members

### `SpbCommon`

A [PEP_ACPI_SPB_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_spb_resource) structure describing this resource.

### `ConnectionSpeed`

The maximum speed, in hertz, supported by this connection.

### `SlaveAddress`

The I2C bus address for this connection.

## See also

[PEP_ACPI_SPB_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_spb_resource)
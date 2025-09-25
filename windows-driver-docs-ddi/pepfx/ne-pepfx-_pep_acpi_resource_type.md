# _PEP_ACPI_RESOURCE_TYPE enumeration (pepfx.h)

## Description

The **PEP_ACPI_RESOURCE_TYPE** enumeration is used to identify the type of ACPI resource that is contained in the [PEP_ACPI_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_resource) union.

## Constants

### `PepAcpiMemory`

Indicates that the resource is an ACPI memory resource.

### `PepAcpiIoPort`

Indicates that the resource is an ACPI IO port resource.

### `PepAcpiInterrupt`

Indicates that the resource is an ACPI interrupt resource.

### `PepAcpiGpioIo`

Indicates that the resource is an ACPI GPIO resource.

### `PepAcpiGpioInt`

Indicates that the resource is an ACPI GPIO interrupt resource.

### `PepAcpiSpbI2c`

Indicates that the resource is an ACPI I2C serial bus resource.

### `PepAcpiSpbSpi`

Indicates that the resource is an ACPI SPI serial bus resource.

### `PepAcpiSpbUart`

Indicates that the resource is an ACPI UART serial bus resource.

### `PepAcpiExtendedMemory`

Indicates that the resource is an ACPI extended memory resource.

### `PepAcpiExtendedIo`

Indicates that the resource is an ACPI extended IO resource.

## See also

[PEP_ACPI_REQUEST_CONVERT_TO_BIOS_RESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_request_convert_to_bios_resources)

[PEP_ACPI_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_resource)
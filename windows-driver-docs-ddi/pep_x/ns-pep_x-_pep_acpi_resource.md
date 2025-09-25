# _PEP_ACPI_RESOURCE structure (pep_x.h)

## Description

The **PEP_ACPI_RESOURCE** structure contains hardware details for a specific ACPI resource.

## Members

### `Type`

The [PEP_ACPI_RESOURCE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_acpi_resource_type) enumeration value that is applicable to this resource.

### `IoMemory`

If **Type** is **PepAcpiMemory** or **PepAcpiIoPort**, this union contains a [PEP_ACPI_IO_MEMORY_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_io_memory_resource) structure describing an ACPI IO or memory resource.

### `Interrupt`

If **Type** is **PepAcpiInterrupt**, this union contains a [PEP_ACPI_INTERRUPT_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_interrupt_resource) structure describing an ACPI interrupt resource.

### `Gpio`

If **Type** is **PepAcpiGpioIo** or **PepAcpiGpioInt**, this union contains a [PEP_ACPI_GPIO_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_gpio_resource) structure describing an ACPI GPIO resource.

### `SpbI2c`

If **Type** is **PepAcpiSpbI2c**, this union contains a [PEP_ACPI_SPB_I2C_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_spb_i2c_resource) structure describing an ACPI I2C serial bus resource.

### `SpbSpi`

If **Type** is **PepAcpiSpbSpi**, this union contains a [PEP_ACPI_SPB_SPI_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_spb_spi_resource) structure describing an ACPI SPI serial bus resource.

### `SpbUart`

If **Type** is **PepAcpiSpbUart**, this union contains a [PEP_ACPI_SPB_UART_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_spb_uart_resource) structure describing an ACPI SPB serial bus resource.

### `ExtendedAddress`

If **Type** is **PepAcpiExtendedMemory** or **PepAcpiExtendedIo**, this union contains a [PEP_ACPI_EXTENDED_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_extended_address) structure describing an ACPI extended memory or extended IO resource.

## See also

[PEP_ACPI_EXTENDED_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_extended_address)

[PEP_ACPI_GPIO_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_gpio_resource)

[PEP_ACPI_INTERRUPT_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_interrupt_resource)

[PEP_ACPI_IO_MEMORY_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_io_memory_resource)

[PEP_ACPI_RESOURCE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ne-pepfx-_pep_acpi_resource_type)

[PEP_ACPI_SPB_I2C_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_spb_i2c_resource)

[PEP_ACPI_SPB_SPI_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_spb_spi_resource)

[PEP_ACPI_SPB_UART_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_spb_uart_resource)
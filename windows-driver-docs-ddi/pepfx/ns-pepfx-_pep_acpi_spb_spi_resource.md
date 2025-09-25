# _PEP_ACPI_SPB_SPI_RESOURCE structure (pepfx.h)

## Description

The **PEP_ACPI_SPB_SPI_RESOURCE** structure describes an ACPI SPI serial bus resource.

## Members

### `SpbCommon`

A [PEP_ACPI_SPB_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_spb_resource) structure describing this resource.

### `ConnectionSpeed`

The maximum speed, in hertz, supported by this connection.

### `DataBitLength`

The size, in bits, of the smallest unit of transfer.

### `Phase`

The phase of the clock pulse on which to capture data.

### `Polarity`

The polarity of the clock. If zero, this indicates the
clock is low during the first phase. If 1, this indicates the
clock is high during the first phase.

### `DeviceSelection`

The device selection value. This value is
specific to the device and may refer to a chip-select line, GPIO
line, or other line selection mechanism.

## See also

[PEP_ACPI_SPB_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_spb_resource)
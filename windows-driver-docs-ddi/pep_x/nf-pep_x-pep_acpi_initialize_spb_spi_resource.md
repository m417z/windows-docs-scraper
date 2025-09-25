# PEP_ACPI_INITIALIZE_SPB_SPI_RESOURCE function (pep_x.h)

## Description

> [!NOTE]
> Microsoft supports a diverse and inclusionary environment. This article contains references to terminology that the Microsoft [Style Guide for Bias-Free Communications](https://learn.microsoft.com/style-guide/bias-free-communication) recognizes as exclusionary. The word or phrase is used in this article for consistency because it currently appears in the software. When the software is updated to remove the language, this article will be updated to be in alignment.

The **PEP_ACPI_INITIALIZE_SPB_SPI_RESOURCE** function initializes a platform extension plug-in's (PEP) [PEP_ACPI_SPB_SPI_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_spb_spi_resource) structure.

## Parameters

### `DeviceSelection` [in]

The device selection value. This value is
specific to the device and may refer to a chip-select line, GPIO
line, or other line selection mechanism.

### `DeviceSelectionPolarity` [in]

The polarity of the clock. If zero, this indicates the
clock is low during the first phase. If 1, this indicates the
clock is high during the first phase.

### `WireMode` [in]

When zero, indicates that this device produces and consumes this resource. Otherwise, this device only consumes this resource.

### `DataBitLength` [in]

The size, in bits, of the smallest unit of transfer.

### `SlaveMode` [in]

Indicates if the resource is operating in slave mode.

### `ConnectionSpeed` [in]

The maximum speed, in hertz, supported by this connection.

### `ClockPolarity` [in]

The polarity of the clock. If zero, this indicates the
clock is low during the first phase. If 1, this indicates the
clock is high during the first phase.

### `ClockPhase` [in]

The phase of the clock pulse on which to capture data.

### `ResourceSource` [in]

The name of the serial bus controller device to which this
connection descriptor applies. The name can be a fully
qualified path, a relative path, or a simple name segment
that utilizes the namespace search rules.

### `ResourceSourceIndex` [in]

This parameter should always be set to zero.

### `ResourceUsage` [in]

Indicates if the resource is in use.

### `SharedMode` [in]

Indicates if the resource is shared.

### `VendorData` [in]

A pointer to optional data that is specific to the serial bus connection type.

### `VendorDataLength` [in]

The length of the buffer pointed to by the *VendorData* parameter.

### `Resource` [out]

A pointer to the resource. The structure behind the pointer is of type [PEP_ACPI_SPB_SPI_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_spb_spi_resource).

## See also

[PEP_ACPI_SPB_SPI_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_spb_spi_resource)
# PEP_ACPI_INITIALIZE_SPB_I2C_RESOURCE function (pep_x.h)

## Description

The **PEP_ACPI_INITIALIZE_SPB_I2C_RESOURCE** function initializes a platform extension plug-in's (PEP) [PEP_ACPI_SPB_I2C_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_spb_i2c_resource) structure.

## Parameters

### `SlaveAddress` [in]

The I2C bus address for this connection.

### `DeviceInitiated` [in]

If true, indicates that communication over this connection is initiated by the device.

### `ConnectionSpeed` [in]

The maximum speed, in hertz, supported by this connection.

### `AddressingMode` [in]

Indicates that this device is in addressing mode.

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

A pointer to the resource. The structure behind the pointer is of type [PEP_ACPI_SPB_I2C_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_spb_i2c_resource).

## See also

[PEP_ACPI_SPB_I2C_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_spb_i2c_resource)
# DXGK_I2C_INTERFACE structure

## Description

The **DXGK_I2C_INTERFACE** structure contains pointers to functions in the I2C interface, which is implemented by the display miniport driver.

## Members

### `Size`

The size, in bytes, of this structure.

### `Version`

The version number of the I2C interface. Version number constants are defined in *Dispmprt.h* (for example, DXGK_I2C_INTERFACE_VERSION_1).

### `Context`

A pointer to a private context block.

### `InterfaceReference`

A pointer to an interface reference function that is implemented by the display miniport driver.

### `InterfaceDereference`

A pointer to an interface dereference function that is implemented by the display miniport driver.

### `DxgkDdiI2CTransmitDataToDisplay`

A pointer to the display miniport driver's [**DxgkDdiI2CTransmitDataToDisplay**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_i2c_transmit_data_to_display) function.

### `DxgkDdiI2CReceiveDataFromDisplay`

A pointer to the display miniport driver's [**DxgkDdiI2CReceiveDataFromDisplay**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_i2c_receive_data_from_display) function.

## Remarks

A kernel-mode component that needs to use the I2C interface calls the display miniport driver's [**DxgkDdiQueryInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_interface) function.
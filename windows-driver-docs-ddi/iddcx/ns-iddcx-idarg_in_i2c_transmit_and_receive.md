# IDARG_IN_I2C_TRANSMIT_AND_RECEIVE structure

## Description

Gives information about the I2C data being transmitted ane received by the OS.

## Members

### `TransmitSevenBitI2CAddress`

[in] The address of the I2C device to which data will be transmitted.

### `TransmitDataSizeInBytes`

[in] The size, in bytes, of the buffer pointed to by **pTransmitData**. This parameter must be between 1 and 64, inclusively.

### `pTransmitData`

[in] A pointer to a buffer that holds the data to be transmitted.

### `ReceiveSevenBitI2CAddress`

[in] The address of the I2C device from which data will be received.

### `ReceiveFlags`

[in] Flags for the receive operation.

### `ReceiveDataSizeInBytes`

[in] The size, in bytes, of the buffer pointed to by **pReceiveData**.

### `pReceiveData`

[out] A pointer to a buffer that receives the data.

## See also

[EVT_IDD_CX_MONITOR_I2C_TRANSMIT_AND_RECEIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_monitor_i2c_transmit_and_receive)
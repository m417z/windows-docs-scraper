# IDARG_IN_I2C_TRANSMIT structure

## Description

 Gives information about the I2C data being transmitted by the OS.

## Members

### `SevenBitI2CAddress`

 [in] The address of the I2C device to which data will be transmitted

### `DataSizeInBytes`

 [in] The size, in bytes, of the buffer pointed to by **pData**. This parameter must be between 1 and 64, inclusively.

### `pData`

 [in] A pointer to a buffer that holds the data to be transmitted.
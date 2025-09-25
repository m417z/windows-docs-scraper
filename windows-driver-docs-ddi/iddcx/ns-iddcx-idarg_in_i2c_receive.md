# IDARG_IN_I2C_RECEIVE structure

## Description

Gives information about I2C data being received by the OS.

## Members

### `SevenBitI2CAddress` [in]

The address of the I2C device from which data will be received.

### `Flags` [in]

Flags for the receive operation.

### `DataSizeInBytes` [in]

The size, in bytes, of the buffer pointed to by **pData**.

### `pData` [out]

A pointer to a buffer that receives the data.
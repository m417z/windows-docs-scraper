# I2CSensorReadRegister function

## Description

The I2CSensorReadRegister function reads the devices register(s) over I2C.

## Parameters

### `I2CIoTarget`

Supplies the WDF I2C I/O target handle.

### `RegAddress`

Supplies the I2C register address to read from.

### `Buffer`

Supplies a buffer in which to read the contents of the register to.

### `BufferCb`

Supplies the size of the buffer.

## Return value

This function returns NTSTATUS.

## Remarks

## See also
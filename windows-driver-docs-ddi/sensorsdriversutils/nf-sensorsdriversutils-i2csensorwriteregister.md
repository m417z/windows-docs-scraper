# I2CSensorWriteRegister function

## Description

The I2CSensorWriteRegister function writes to the device register(s) over I2C.

## Parameters

### `I2CIoTarget`

Supplies the WDF I2C I/O target handle.

### `RegAddress`

Supplies the I2C register address to write to.

### `RegValue`

Supplies the value to write.

### `RegLength`

Number of bytes contained in RegValue array.

## Return value

This function returns NTSTATUS.

## Remarks

## See also
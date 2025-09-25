# DIEFFESCAPE structure

## Description

The **DIEFFESCAPE** structure passes hardware-specific data directly to the device driver.

## Members

### `dwSize`

Specifies the size of the structure in bytes. This member must be initialized before the structure is used.

### `dwCommand`

Specifies a driver-specific command number. Contact the hardware vendor for a list of valid commands and their parameters.

### `lpvInBuffer`

Points to the buffer containing the data required to perform the operation.

### `cbInBuffer`

Specifies the size, in bytes, of the **lpvInBuffer** buffer.

### `lpvOutBuffer`

Points to the buffer in which the operation's output data is returned.

### `cbOutBuffer`

On entry, specifies the size, in bytes, of the **lpvOutBuffer** buffer. On exit, specifies the number of bytes actually produced by the command.
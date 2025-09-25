# PI8042_SYNCH_READ_PORT callback function

## Description

The PI8042_SYNCH_READ_PORT-typed callback routine does a synchronized read from an i8042 port. I8042prt supplies this callback.

## Parameters

### `Context` [in]

Pointer to a context supplied by I8042prt.

### `Value` [out]

Pointer to the UCHAR value returned by the routine.

### `WaitForACK` [in]

Not used.

## Return value

The PI8042_SYNCH_READ_PORT callback returns one of the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The routine successfully returned a byte. |
| **STATUS_IO_TIMEOUT** | The hardware was not ready for a read access. |

## Remarks

The PI8042_SYNCH_READ_PORT callback can only be used in a [PI8042_KEYBOARD_INITIALIZATION_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_keyboard_initialization_routine) callback. I8042prt specifies the read port callback in the *ReadPort* parameter that I8042prt inputs to a keyboard initialization routine.

The routine polls the hardware until a read is returned by the hardware or an internal time-out occurs.

## See also

[PI8042_KEYBOARD_INITIALIZATION_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_keyboard_initialization_routine)

[PI8042_SYNCH_WRITE_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_synch_write_port)
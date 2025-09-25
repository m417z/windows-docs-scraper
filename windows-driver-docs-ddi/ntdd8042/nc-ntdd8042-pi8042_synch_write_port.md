# PI8042_SYNCH_WRITE_PORT callback function

## Description

The PI8042_SYNCH_READ_PORT-typed callback routine does a synchronized write to an i8042 port. I8042prt supplies this routine.

## Parameters

### `Context` [in]

Pointer to a context supplied by I8042prt.

### `Value` [in]

Specifies the UCHAR value to write to an i8042 port.

### `WaitForACK` [in]

Specifies, if **TRUE**, that the routine waits until the write is acknowledged by the i8042 port. Otherwise, the routine returns without waiting for an acknowledgment from the port.

## Return value

The PI8042_SYNCH_WRITE_PORT callback returns one of the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The routine successfully wrote a byte to an i8042 port. |
| **STATUS_IO_TIMEOUT** | The hardware was not ready for a write access. |

## Remarks

The PI8042_SYNCH_READ_PORT callback can only be used in a [PI8042_KEYBOARD_INITIALIZATION_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_keyboard_initialization_routine) callback. I8042prt specifies the write port callback in the *WritePort* parameter that I8042prt inputs to a keyboard initialization routine.

The routine polls the hardware until a read is returned by the hardware or an internal time-out occurs.

## See also

[PI8042_KEYBOARD_INITIALIZATION_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_keyboard_initialization_routine)

[PI8042_SYNCH_READ_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_synch_read_port)
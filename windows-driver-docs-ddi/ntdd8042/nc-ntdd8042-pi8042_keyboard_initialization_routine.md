# PI8042_KEYBOARD_INITIALIZATION_ROUTINE callback function

## Description

A PI8042_KEYBOARD_INITIALIZATION_ROUTINE-typed callback routine supplements the default initialization of a keyboard device by I8042prt.

## Parameters

### `InitializationContext` [in]

Pointer to the filter device object of the driver that supplies the callback.

### `SynchFuncContext` [in]

Pointer to the context for the callbacks that are pointed to by *ReadPort* and *Writeport.*

### `ReadPort` [in]

Pointer to a [PI8042_SYNCH_READ_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_synch_read_port) callback that reads from the port.

### `WritePort` [in]

Pointer to a [PI8042_SYNCH_WRITE_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_synch_write_port) callback that writes to the port.

### `TurnTranslationOn` [out]

Specifies whether to turn translation on or off. If *TranslationOn* is **TRUE**, translation is turned on; otherwise, translation is turned off.

## Return value

A PI8042_KEYBOARD_INITIALIZATION_ROUTINE callback returns an appropriate NTSTATUS code.

## Remarks

An upper-level keyboard filter driver can provide a PI8042_KEYBOARD_INITIALIZATION_ROUTINE callback.

If an upper-level keyboard filter driver supplies an initialization callback, I8042prt calls the filter initialization callback when I8042prt initializes the keyboard. Default keyboard initialization includes the following operations: reset the keyboard, set the typematic rate and delay, and set the light-emitting diodes (LED).

## See also

[PI8042_SYNCH_READ_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_synch_read_port)

[PI8042_SYNCH_WRITE_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_synch_write_port)
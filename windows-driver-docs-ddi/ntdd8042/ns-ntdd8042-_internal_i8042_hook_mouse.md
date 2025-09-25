# _INTERNAL_I8042_HOOK_MOUSE structure

## Description

INTERNAL_I8042_HOOK_MOUSE is used by I8042prt to connect an optional callback routine that supplements the operation of the mouse ISR. The callback can be supplied by an optional, vendor-supplied, upper-level filter driver.

## Members

### `Context`

Pointer, if non-**NULL**, to the context that must be used with the **IsrRoutine** routine. Otherwise, **Context** is **NULL**.

### `IsrRoutine`

Pointer, if non-**NULL**, to an optional [PI8042_MOUSE_ISR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_mouse_isr) callback that customizes the operation of the I8042prt mouse ISR. Otherwise, **IsrRoutine** is **NULL**.

### `IsrWritePort`

Pointer to the system-supplied mouse [PI8042_ISR_WRITE_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_isr_write_port) callback, which writes data to a mouse.

### `QueueMousePacket`

Pointer to the system-supplied mouse [PI8042_QUEUE_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_queue_packet) callback, which queues a mouse input data packet for processing by the mouse's ISR deferred procedure call.

### `CallContext`

Pointer to the context that must be used with the **IsrWritePort** and **QueueMousePacket** routines.

## Remarks

This structure is only used with an [IOCTL_INTERNAL_I8042_HOOK_MOUSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ni-ntdd8042-ioctl_internal_i8042_hook_mouse) request.

**Context**, **InitializationRoutine**, and **IsrRoutine** can be supplied by an optional, vendor-supplied, upper-level filter driver.

**IsrWritePort**, **QueueMousePacket**, and **CallContext** are supplied by I8042prt.

## See also

[IOCTL_INTERNAL_I8042_HOOK_MOUSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ni-ntdd8042-ioctl_internal_i8042_hook_mouse)

[MouFilter_IsrHook](https://learn.microsoft.com/previous-versions/ff542379(v=vs.85))

[PI8042_ISR_WRITE_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_isr_write_port)

[PI8042_MOUSE_ISR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_mouse_isr)

[PI8042_QUEUE_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_queue_packet)
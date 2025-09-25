# _INTERNAL_I8042_HOOK_KEYBOARD structure

## Description

INTERNAL_I8042_HOOK_KEYBOARD is used by I8042prt to connect optional callback routines that supplement keyboard initialization and the keyboard ISR. The callbacks can be supplied by an optional, vendor-supplied, upper-level filter driver.

## Members

### `Context`

Pointer, if non-**NULL**, to the context that must be used with the **InitializationRoutine** and **IsrRoutine** routines. Otherwise, **Context** is **NULL**.

### `InitializationRoutine`

Pointer, if non-**NULL**, to an optional [PI8042_KEYBOARD_INITIALIZATION_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_keyboard_initialization_routine)callback. I8042prt uses this callback to initialize a device after the device is reset. Otherwise, **IntializatonRoutine** is **NULL**.

### `IsrRoutine`

Pointer, if non-**NULL**, to an optional [PI8042_KEYBOARD_ISR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_keyboard_isr) callback that customizes the operation of the I8042prt keyboard ISR. Otherwise, **IsrRoutine** is **NULL**.

### `IsrWritePort`

Pointer to the system-supplied [PI8042_ISR_WRITE_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_isr_write_port) callback, which writes data to a keyboard.

### `QueueKeyboardPacket`

Pointer to the system-supplied [PI8042_QUEUE_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_queue_packet) callback, which queues a keyboard input data packet for processing by the keyboard's ISR deferred procedure call.

### `CallContext`

Pointer to the context that must be used with the **IsrWritePort** and **QueueKeyboardPacket** routines.

## Remarks

This structure is only used with an [IOCTL_INTERNAL_I8042_HOOK_KEYBOARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ni-ntdd8042-ioctl_internal_i8042_hook_keyboard) request.

**Context**, **InitializationRoutine**, and **IsrRoutine** can be supplied by an optional, vendor-supplied, upper-level filter driver.

**IsrWritePort**, **QueueKeyboardPacket**, and **CallContext** are supplied by I8042prt.

## See also

[IOCTL_INTERNAL_I8042_HOOK_KEYBOARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ni-ntdd8042-ioctl_internal_i8042_hook_keyboard)

[KbFilter_InitializationRoutine](https://learn.microsoft.com/previous-versions/ff542293(v=vs.85))

[KbFilter_IsrHook](https://learn.microsoft.com/previous-versions/ff542294(v=vs.85))

[PI8042_ISR_WRITE_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_isr_write_port)

[PI8042_KEYBOARD_ISR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_keyboard_isr)

[PI8042_QUEUE_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_queue_packet)
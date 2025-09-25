# PI8042_ISR_WRITE_PORT callback function

## Description

The PI8042_ISR_WRITE_PORT-typed callback routine writes data to an i8042 port. I8042prt provides this callback.

## Parameters

### `Context` [in]

Pointer to the function device object that represents a keyboard or mouse device.

### `Value` [in]

Specifies the data to write to an i8042 port.

## Remarks

The PI8042_ISR_WRITE_PORT callback should only be called by a [PI8042_KEYBOARD_ISR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_keyboard_isr) callback or a [PI8042_MOUSE_ISR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_mouse_isr) callback. I8042prt calls a vendor-supplied ISR callback for a device in the corresponding I8042prt device ISR.

I8042prt specifies the keyboard write port callback in the **IsrWritePort** member of the [INTERNAL_I8042_HOOK_KEYBOARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ns-ntdd8042-_internal_i8042_hook_keyboard) structure that I8042prt uses with an [IOCTL_INTERNAL_I8042_HOOK_KEYBOARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ni-ntdd8042-ioctl_internal_i8042_hook_keyboard) request.

I8042prt specifies the mouse write port callback in the **IsrWritePort** member of the [INTERNAL_I8042_HOOK_MOUSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ns-ntdd8042-_internal_i8042_hook_mouse) structure that I8042prt uses with an [IOCTL_INTERNAL_I8042_HOOK_KEYBOARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ni-ntdd8042-ioctl_internal_i8042_hook_keyboard) request.

The PI8042_ISR_WRITE_PORT callback runs in kernel mode at the same IRQL as the I8042prt ISR for the device.

## See also

[INTERNAL_I8042_HOOK_MOUSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ns-ntdd8042-_internal_i8042_hook_mouse)

**IOCTL_INTERNAL_I8042_HOOK_KEYBOARD**

[IOCTL_INTERNAL_I8042_HOOK_MOUSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ni-ntdd8042-ioctl_internal_i8042_hook_mouse)
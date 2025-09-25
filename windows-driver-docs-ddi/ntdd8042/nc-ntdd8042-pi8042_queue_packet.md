# PI8042_QUEUE_PACKET callback function

## Description

The PI8042_QUEUE_PACKET-typed callback routine queues an input data packet for processing by the ISR DPC of a keyboard or mouse device. I8042prt provides this callback.

## Parameters

### `Context` [in]

Pointer to the function device object that represents a keyboard or mouse device.

## Remarks

The PI8042_QUEUE_PACKET callback should only be called by a [PI8042_KEYBOARD_ISR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_keyboard_isr) callback or a[PI8042_MOUSE_ISR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_mouse_isr) callback. I8042prt calls a vendor-supplied ISR callback in the corresponding I8042prt device ISR.

I8042prt specifies the queue packet callback for a keyboard in the **QueueKeyboardPacket** member of the [INTERNAL_I8042_HOOK_KEYBOARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ns-ntdd8042-_internal_i8042_hook_keyboard) structure that I8042prt uses with an [IOCTL_INTERNAL_I8042_HOOK_KEYBOARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ni-ntdd8042-ioctl_internal_i8042_hook_keyboard) request.

I8042prt specifies the queue packet callback for a mouse in the **QueueMousePacket** member of an [INTERNAL_I8042_HOOK_MOUSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ns-ntdd8042-_internal_i8042_hook_mouse) structure that I8042prt uses with an [IOCTL_INTERNAL_I8042_HOOK_MOUSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ni-ntdd8042-ioctl_internal_i8042_hook_mouse) request.

The PI8042_QUEUE_PACKET callback runs in kernel mode at the same IRQL as the I8042prt ISR for the device.

## See also

[INTERNAL_I8042_HOOK_KEYBOARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ns-ntdd8042-_internal_i8042_hook_keyboard)

[INTERNAL_I8042_HOOK_MOUSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ns-ntdd8042-_internal_i8042_hook_mouse)

[IOCTL_INTERNAL_I8042_HOOK_KEYBOARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ni-ntdd8042-ioctl_internal_i8042_hook_keyboard)

[IOCTL_INTERNAL_I8042_HOOK_MOUSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ni-ntdd8042-ioctl_internal_i8042_hook_mouse)
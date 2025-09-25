# _IO_INTERRUPT_MESSAGE_INFO_ENTRY structure

## Description

The **IO_INTERRUPT_MESSAGE_INFO_ENTRY** structure describes the properties of a single message-signaled interrupt.

## Members

### `MessageAddress`

Specifies the physical address that triggers the interrupt message.

### `TargetProcessorSet`

Specifies a [**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity) value that determines the set of processors that can receive the interrupt.

### `InterruptObject`

Pointer to the interrupt object that represents the interrupt.

### `MessageData`

Specifies the value to be written to the address specified by **MessageAddress** to trigger the interrupt.

### `Vector`

Specifies the interrupt vector for the interrupt.

### `Irql`

Specifies the device IRQL (DIRQL) for the interrupt.

### `Mode`

Specifies a [KINTERRUPT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_mode) value that determines whether the interrupt is level-sensitive or latched.

### `Polarity`

Specifies a [KINTERRUPT_POLARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_polarity) value that determines whether the interrupt is active-high or active-low.

## See also

[IO_INTERRUPT_MESSAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info)
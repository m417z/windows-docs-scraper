# _IO_INTERRUPT_MESSAGE_INFO structure

## Description

The **IO_INTERRUPT_MESSAGE_INFO** structure describes the driver's message-signaled interrupts.

## Members

### `UnifiedIrql`

Specifies the IRQL at which the driver's [InterruptMessageService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kmessage_service_routine) routine runs. If the driver specified an interrupt spin lock for its interrupts, **UnifiedIrql** also specifies the IRQL at which the interrupt spin lock is acquired.

### `MessageCount`

Specifies the number of message-signaled interrupts allocated for the driver.

### `MessageInfo`

Variable-length array that specifies an [IO_INTERRUPT_MESSAGE_INFO_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info_entry) structure for each message-signaled interrupt allocated for the driver. The **MessageCount** member specifies the number of entries in this array.

## Remarks

When a driver calls [IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex) to register an [InterruptMessageService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kmessage_service_routine) routine, **IoConnectInterruptEx** provides a pointer to **IO_INTERRUPT_MESSAGE_INFO** in *Parameters*->**MessageBased.ConnectionContext**. For more information, see [IO_CONNECT_INTERRUPT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_connect_interrupt_parameters).

## See also

[IO_CONNECT_INTERRUPT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_connect_interrupt_parameters)

[IO_INTERRUPT_MESSAGE_INFO_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info_entry)

[IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex)
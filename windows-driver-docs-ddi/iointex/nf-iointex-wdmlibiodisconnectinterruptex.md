# WdmlibIoDisconnectInterruptEx function

## Description

The **WdmlibIoDisconnectInterruptEx** function unregisters an interrupt service routine (ISR) that was registered by a previous call to the [WdmlibIoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/iointex/nf-iointex-wdmlibioconnectinterruptex) function.

## Parameters

### `Parameters` [in, out]

Pointer to an [IO_DISCONNECT_INTERRUPT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_disconnect_interrupt_parameters) structure that contains the connection context for the interrupt being disconnected.

## Return value

None.

## Remarks

The driver should configure the device to issue interrupts only when these interrupts are connected. Failure to prevent a device from issuing interrupts when the interrupts are disconnected might cause system instability. For example, if a device shares a level-triggered interrupt line with other devices, and the device issues an interrupt request when the device's interrupts are disconnected, the other devices on the line will not acknowledge the interrupt and the interrupt will continue to fire. Before calling **WdmlibIoDisconnectInterruptEx**, the driver should configure the device to stop issuing interrupts. After calling [WdmlibIoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/iointex/nf-iointex-wdmlibioconnectinterruptex), the driver should configure the device to start issuing interrupts.

## See also

[IO_DISCONNECT_INTERRUPT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_disconnect_interrupt_parameters)

[WdmlibIoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/iointex/nf-iointex-wdmlibioconnectinterruptex)
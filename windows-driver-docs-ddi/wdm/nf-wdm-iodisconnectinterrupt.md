# IoDisconnectInterrupt function

## Description

The **IoDisconnectInterrupt** routine releases a device driver's set of interrupt object(s) when the device is paused or removed, or when the driver is being unloaded.

## Parameters

### `InterruptObject` [in]

A pointer to a [KINTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure. The caller obtained this pointer from the [IoConnectInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterrupt) call that previously connected the interrupt or interrupts.

## Remarks

The driver should configure the device to issue interrupts only when these interrupts are connected. Failure to prevent a device from issuing interrupts when the interrupts are disconnected might cause system instability. For example, if a device shares a level-triggered interrupt line with other devices, and the device issues an interrupt request when the device's interrupts are disconnected, the other devices on the line will not acknowledge the interrupt and the interrupt will continue to fire. Before calling **IoDisconnectInterrupt**, the driver should configure the device to stop issuing interrupts. After calling [IoConnectInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterrupt), the driver should configure the device to start issuing interrupts.

If the driver stored the pointer to its interrupt object(s) in the device extension of its device object or in the controller extension of its controller object, it must call **IoDisconnectInterrupt** before it calls [IoDeleteDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodeletedevice) or [IoDeleteController](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iodeletecontroller).

## See also

[IoConnectInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterrupt)

[IoDeleteController](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iodeletecontroller)

[IoDeleteDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodeletedevice)

[KINTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)
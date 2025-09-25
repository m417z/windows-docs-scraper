# WdmlibIoConnectInterruptEx function

## Description

The **WdmlibIoConnectInterruptEx** function registers an interrupt-handling routine for a device's interrupts.

## Parameters

### `Parameters` [in, out]

Pointer to an [IO_CONNECT_INTERRUPT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_connect_interrupt_parameters) structure that specifies the device and interrupt-handling routine. On return, **WdmlibIoConnectInterruptEx** updates this structure to hold information about the device's interrupts.

## Return value

The function returns STATUS_SUCCESS on success, or the appropriate NTSTATUS error value on failure. Possible error values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | The operation is invalid for the specified device. For example, *Parameters*->**Version** = CONNECT_LINE_BASED, and the system has assigned multiple interrupt messages to the device. |
| **STATUS_INVALID_PARAMETER** | The caller specified an invalid parameter. This error occurs, for example, when the caller specified **NULL** for the device's device object. |
| **STATUS_INVALID_PARAMETER_1** | The caller specified an invalid value for the **Version** member of the structure that *Parameters* points to. *Parameters*->**Version** must be one of CONNECT_LINE_BASED, CONNECT_MESSAGE_BASED, or CONNECT_FULLY_SPECIFIED. |
| **STATUS_INVALID_PARAMETER_10** | The caller specified an invalid value for the tenth member of the structure that *Parameters* points to. This error occurs, for example, when *Parameters*->**FullySpecified.ProcessorEnableMask** does not have any bits set. |
| **STATUS_NOT_FOUND** | One of the arguments was not found. For example, the specified device has no interrupts, or the specified interrupt vector is not assigned to any device. |

## Remarks

**WdmlibIoConnectInterruptEx**
can be used to register an interrupt-handling routine for both traditional line-based interrupts (such as that supported by the PCI bus), and the newer message-signaled interrupts (such as that supported by PCI versions 2.2 and 3.0).

Drivers register an [InterruptService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kservice_routine) routine for line-based interrupts, and an [InterruptMessageService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kmessage_service_routine) routine for message-signaled interrupts. For more information about how to specify the members of *Parameters* in each case, see [IO_CONNECT_INTERRUPT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_connect_interrupt_parameters).

**WdmlibIoConnectInterruptEx** updates the members of *Parameters* to provide information about the device's interrupts. For more information about the information provided by **WdmlibIoConnectInterruptEx**, see [IO_CONNECT_INTERRUPT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_connect_interrupt_parameters).

Use [WdmlibIoDisconnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/iointex/nf-iointex-wdmlibiodisconnectinterruptex) to unregister a routine registered with **WdmlibIoConnectInterruptEx**.

The driver should not program its device to generate interrupts until it has connected its ISR. Thus, the ISR cannot fire before **WdmlibIoConnectInterruptEx** returns. However, there are certain devices, such as buttons, that are not programmable. For those devices, the driver should be prepared to handle the ISR as soon as it calls **WdmlibIoConnectInterruptEx**. The interrupt line may already be asserted when **WdmlibIoConnectInterruptEx** is called and can fire immediately after the line is enabled at the interrupt controller, before the **WdmlibIoConnectInterruptEx** call unwinds.

For more information about registering an interrupt-handling routine, see [Registering an ISR](https://learn.microsoft.com/windows-hardware/drivers/kernel/registering-an-isr).

## See also

[IO_CONNECT_INTERRUPT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_connect_interrupt_parameters)

[InterruptMessageService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kmessage_service_routine)

[InterruptService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kservice_routine)

[WdmlibIoDisconnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/iointex/nf-iointex-wdmlibiodisconnectinterruptex)
# IoReportInterruptInactive function

## Description

The **IoReportInterruptInactive** routine informs the operating system that a registered interrupt service routine (ISR) is inactive and is not expecting interrupt requests.

## Parameters

### `Parameters` [in]

A pointer to an [IO_REPORT_INTERRUPT_ACTIVE_STATE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_report_interrupt_active_state_parameters) structure that contains the connection context associated with the interrupt. The caller received this context from the [IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex) call that registered the ISR.

## Remarks

The [IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex) routine registers an ISR and connects the ISR to an interrupt or interrupts. After the ISR is registered, the driver can make the ISR active or inactive by calling the [IoReportInterruptActive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreportinterruptactive) or **IoReportInterruptInactive** routine. By default, the ISR is active after the **IoConnectInterruptEx** call.

An ISR that is in the inactive state can be disconnected or made active. To disconnect the ISR and delete its registration, call the [IoDisconnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodisconnectinterruptex) routine. To make the ISR active without changing its registration, call **IoReportInterruptActive**.

The **IO_REPORT_INTERRUPT_ACTIVE_STATE_PARAMETERS** structure must contain a valid connection contact obtained from an **IoConnectInterruptEx** call.

For more information about **IoReportInterruptInactive**, see [Making an ISR Active or Inactive](https://learn.microsoft.com/windows-hardware/drivers/kernel/making-an-isr-active-or-inactive).

## See also

[IO_REPORT_INTERRUPT_ACTIVE_STATE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_report_interrupt_active_state_parameters)

[IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex)

[IoDisconnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodisconnectinterruptex)

[IoReportInterruptActive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreportinterruptactive)
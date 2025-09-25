# _IO_REPORT_INTERRUPT_ACTIVE_STATE_PARAMETERS structure

## Description

The **IO_REPORT_INTERRUPT_ACTIVE_STATE_PARAMETERS** structure contains the connection context for a registered interrupt service routine (ISR) that was connected to an interrupt or interrupts by a previous call to the [IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex) routine.

## Members

### `Version`

The interrupt connection type described by this structure. This member must match the connection type the caller obtained from the **IoConnectInterruptEx** call that connected the interrupt. The following are valid values for this member:

* CONNECT_FULLY_SPECIFIED
* CONNECT_LINE_BASED
* CONNECT_MESSAGE_BASED
* CONNECT_FULLY_SPECIFIED_GROUP

For more information, see Remarks.

### `ConnectionContext`

A union that contains the connection context associated with the interrupt. Each union member is a pointer to a connection context of a particular type. If **Version** = CONNECT_MESSAGE_BASED, the **InterruptMessageTable** member of this union contains a pointer to an [IO_INTERRUPT_MESSAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info) structure. For all other **Version** values, the **InterruptObject** member of this union contains a pointer to a [KINTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure. Use the **Generic** member of this union to treat the connection context pointer as a PVOID value (and avoid casting).

For more information, see Remarks.

### `ConnectionContext.Generic`

A PVOID pointer to a connection context.

### `ConnectionContext.InterruptObject`

A pointer to a connection context of type [KINTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess).

### `ConnectionContext.InterruptMessageTable`

A pointer to a connection context of type [IO_INTERRUPT_MESSAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info).

## Remarks

This structure is supplied as a parameter to the [IoReportInterruptActive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreportinterruptactive) and [IoReportInterruptInactive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreportinterruptinactive) routines.

The **Version** member indicates the type of the connection context specified in the **ConnectionContext** member. Set this member to the *Parameters-*>**Version** value obtained from the [IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex) call that connected the interrupt.

If the *Parameters-*>**Version** value obtained from **IoConnectInterruptEx** is CONNECT_FULLY_SPECIFIED or CONNECT_FULLY_SPECIFIED_GROUP, set the **ConnectionContext.InterruptObject** member of the **IO_REPORT_INTERRUPT_ACTIVE_STATE_PARAMETERS** structure to the *(*Parameters-*>**FullySpecified.InterruptObject**) pointer value obtained from **IoConnectInterruptEx**.

If the *Parameters-*>**Version** value obtained from **IoConnectInterruptEx** is CONNECT_MESSAGE_BASED, set the **ConnectionContext.InterruptMessageTable** member of the **IO_REPORT_INTERRUPT_ACTIVE_STATE_PARAMETERS** structure to the *(*Parameters-*>**MessageBased.ConnectionContext.InterruptMessageTable**) pointer value obtained from **IoConnectInterruptEx**.

If the *Parameters-*>**Version** value obtained from **IoConnectInterruptEx** is CONNECT_LINE_BASED, but the caller initially set *Parameters-*>**Version** to CONNECT_MESSAGE_BASED, set the **ConnectionContext.InterruptObject** member of the **IO_REPORT_INTERRUPT_ACTIVE_STATE_PARAMETERS** structure to the *(*Parameters-*>**MessageBased.ConnectionContext.InterruptObject**) pointer value obtained from **IoConnectInterruptEx**.

If the *Parameters-*>**Version** value obtained from **IoConnectInterruptEx** is CONNECT_LINE_BASED, and the caller initially set *Parameters-*>**Version** to CONNECT_LINE_BASED, set the **ConnectionContext.InterruptObject** member of the **IO_REPORT_INTERRUPT_ACTIVE_STATE_PARAMETERS** structure to the *(*Parameters-*>**LineBased.InterruptObject**) pointer value obtained from **IoConnectInterruptEx**.

## See also

[IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex)

[IoReportInterruptActive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreportinterruptactive)

[IoReportInterruptInactive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreportinterruptinactive)
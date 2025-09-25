# _IO_DISCONNECT_INTERRUPT_PARAMETERS structure

## Description

The **IO_DISCONNECT_INTERRUPT_PARAMETERS** structure describes the parameters when unregistering an interrupt-handling routine with [IoDisconnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodisconnectinterruptex).

## Members

### `Version`

Specifies the particular operation to be performed by **IoDisconnectInterruptEx**. The value for **Version** depends on the value specified for *Parameters-*>**Version** when [IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex) registered the interrupt handing routine, as shown in the following table.

| IO_CONNECT_INTERRUPT_PARAMETERS Version value | IO_DISCONNECT_INTERRUPT_PARAMETERS Version value |
| --- | --- |
| CONNECT_LINE_BASED | CONNECT_LINE_BASED |
| CONNECT_MESSAGE_BASED | The value of **Version** output by **IoConnectInterruptEx**. |
| CONNECT_FULLY_SPECIFIED | CONNECT_FULLY_SPECIFIED |

### `ConnectionContext`

A pointer to the [KINTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) or [IO_INTERRUPT_MESSAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info) structure that was provided by [IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex) when the interrupt was connected. The value for **ConnectionContext** depends on the value specified for *Parameters*->**Version** when **IoConnectInterruptEx** registered the interrupt handling routine, as shown in the following table.

| IoConnectInterruptEx Version value | IoDisconnectInterruptEx ConnectionContext value |
| --- | --- |
| CONNECT_LINE_BASED | The value stored in **LineBased.InterruptObject**. |
| CONNECT_MESSAGE_BASED | The value stored in **MessageBased.ConnectionContext**. |
| CONNECT_FULLY_SPECIFIED | The value stored in **FullySpecified.InterruptObject**. |

To minimize casting, **ConnectionContext** is defined as a union. Use **ConnectionContext.Generic** to specify the value as a PVOID. Use **ConnectionContext.InterruptObject** and **ConnectionContext.InterruptMessageTable** to specify the value as a pointer to a [KINTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) or [IO_INTERRUPT_MESSAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info) structure.

### `ConnectionContext.Generic`

A pointer to a data structure of unspecified type.

### `ConnectionContext.InterruptObject`

A pointer to a [KINTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure.

### `ConnectionContext.InterruptMessageTable`

A pointer to an [IO_INTERRUPT_MESSAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info) structure.

## See also

[IO_INTERRUPT_MESSAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info)

[IoDisconnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodisconnectinterruptex)

[KINTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)
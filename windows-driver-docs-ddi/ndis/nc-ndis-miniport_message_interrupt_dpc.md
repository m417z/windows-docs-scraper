# MINIPORT_MESSAGE_INTERRUPT_DPC callback function

## Description

A miniport driver must provide a
*MiniportMessageInterruptDPC* handler if the driver calls the
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex) function
to register an interrupt.

**Note** You must declare the function by using the **MINIPORT_MESSAGE_INTERRUPT_DPC** type. For
more information, see the following Examples section.

## Parameters

### `MiniportInterruptContext` [in]

A handle to a block of interrupt context information. The miniport driver supplied this handle in
the
*MiniportInterruptContext* parameter that the miniport driver passed to the
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex) function.

### `MessageId` [in]

A message-signaled interrupt (MSI) message identifier.
*MessageId* is an index to an
[IO_INTERRUPT_MESSAGE_INFO_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info_entry) structure inside a
[IO_INTERRUPT_MESSAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info) structure. NDIS passes a pointer to the associated
**IO_INTERRUPT_MESSAGE_INFO** structure in the
**MessageInfoTable** member when the driver successfully registers for MSI with the
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex) function.

### `MiniportDpcContext` [in]

A pointer to a context area that the miniport driver supplied when it called the
[NdisMQueueDpcEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismqueuedpcex) or
[NdisMQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismqueuedpc) function. If NDIS called
*MiniportMessageInterruptDPC* because the miniport driver returned a bitmask in the
*TargetProcessors* parameter of the
[MiniportMessageInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt) function, then
*MiniportDpcContext* is **NULL**.

### `ReceiveThrottleParameters` [in]

A pointer to an
[NDIS_RECEIVE_THROTTLE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_receive_throttle_parameters) structure specifies the maximum number of
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that a miniport
driver should indicate in a DPC.

**Note** In NDIS 6.1 and earlier, this parameter is named *NdisReserved1*, its datatype is **PULONG**, and it is reserved for NDIS.

### `NdisReserved1`

Reserved for NDIS.

### `NdisReserved2` [in]

Reserved for NDIS.

**Note** In NDIS 6.1 and earlier, this parameter's datatype is **PULONG**.

## Remarks

Miniport drivers that register a message-signaled interrupt with the
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex) function
must provide a
*MiniportMessageInterruptDPC* function.

NDIS calls
*MiniportMessageInterruptDPC* to complete the deferred processing of an interrupt. The miniport
driver can call the
[NdisMQueueDpcEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismqueuedpcex) or
[NdisMQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismqueuedpc) function to request additional
deferred procedure calls (DPCs) for other processors.

Miniport drivers determine the source of each interrupt and take appropriate action. For example, if
an interrupt indicates the completion of a transmit operation, the miniport driver completes a pending
send request. If the cause of the interrupt is a change in link state, the miniport driver indicates the
new link status to NDIS. If there are outstanding receive packets, the miniport driver indicates the
packets to NDIS.

A miniport driver that supports [receive side scaling (RSS)](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-receive-side-scaling2), and has the feature enabled, examines its
receive queues in
*MiniportMessageInterruptDPC*. The NIC could have already queued received packets on separate queues
based on hash values, if the NIC provides such capabilities. Otherwise, the miniport driver can sort the
packets into separate queues in
*MiniportMessageInterruptDPC*.

*MiniportMessageInterruptDPC* calls the
[NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists) function to indicate the packets on the current processor.
*MiniportMessageInterruptDPC* can determine processing that is required for other CPUs and request
NDIS to schedule DPCs on CPUs where a DPC is not outstanding.

If the current DPC is running on the same CPU as the
[MiniportMessageInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt) function, the miniport driver should indicate all of the packets that
could not be mapped to a CPU. If this DPC is the last scheduled DPC and it will not request additional
DPCs,
*MiniportMessageInterruptDPC* should reenable the interrupts on the NIC, for the specified message,
before it returns.

Before NDIS calls
*MiniportMessageInterruptDPC*, interrupts for the specified message on the NIC, have typically been
disabled in the
[MiniportMessageInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt) function. Before it returns control,
*MiniportMessageInterruptDPC* can reenable interrupts. If the miniport driver queued additional DPCs
while interrupts were disabled, the driver should enable the interrupts after the last DPC executes.

**Note** For better performance, miniport drivers should only disable interrupts for
specific messages. They should not disable all message-signaled interrupts.

Miniport drivers should limit the number of the receive buffers that they indicate while they are
processing an
*interrupt DPC batch* to complete within the required time limit. An interrupt DPC batch is the
collection of all the DPCs that run after the ISR and before the interrupts are reenabled.

A miniport driver can call
[NdisMDeregisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterinterruptex) from
its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) or
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function to release
resources that it allocated with
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex). After
**NdisMDeregisterInterruptEx** returns, NDIS does not call a miniport driver's
[MiniportMessageInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt) or
*MiniportMessageInterruptDPC* function.

NDIS calls
*MiniportMessageInterruptDPC* at IRQL = DISPATCH_LEVEL.

### Examples

To define a *MiniportMessageInterruptDPC* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportMessageInterruptDPC* function that is named "MyMessageInterruptDPC", use the **MINIPORT_MESSAGE_INTERRUPT_DPC** type as shown in this code example:

```
MINIPORT_MESSAGE_INTERRUPT_DPC MyMessageInterruptDPC;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyMessageInterruptDPC(
    NDIS_HANDLE  MiniportInterruptContext,
    ULONG  MessageId,
    PVOID  MiniportDpcContext,
    PVOID  ReceiveThrottleParameters,
    PVOID  NdisReserved2
    )
  {...}
```

The **MINIPORT_MESSAGE_INTERRUPT_DPC** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_MESSAGE_INTERRUPT_DPC** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[IO_INTERRUPT_MESSAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info)

[IO_INTERRUPT_MESSAGE_INFO_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info_entry)

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportMessageInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt)

[NDIS_MINIPORT_INTERRUPT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_interrupt_characteristics)

[NDIS_RECEIVE_THROTTLE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_receive_throttle_parameters)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisMDeregisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterinterruptex)

[NdisMIndicateReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatereceivenetbufferlists)

[NdisMQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismqueuedpc)

[NdisMQueueDpcEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismqueuedpcex)

[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex)

[Receive Side Scaling (RSS)](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-receive-side-scaling2)
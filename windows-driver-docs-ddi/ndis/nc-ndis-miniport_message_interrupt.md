# MINIPORT_MESSAGE_INTERRUPT callback function

## Description

NDIS calls the
*MiniportMessageInterrupt* function when a NIC generates a message-based interrupt.

**Note** You must declare the function by using the **MINIPORT_MESSAGE_INTERRUPT** type. For more
information, see the following Examples section.

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
**IO_INTERRUPT_MESSAGE_INFO** structure at the
**MessageInfoTable** member when the driver successfully registers for MSI with the
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex) function.

### `QueueDefaultInterruptDpc` [out]

A pointer to a Boolean variable that the miniport driver sets before returning from this call. A
miniport driver sets this value to **TRUE** to indicate that the driver requires a DPC on the default
(current) CPU. If set to **TRUE**, NDIS ignores the value of the
*TargetProcessors* parameter. If set to **FALSE**, NDIS uses the value of the
*TargetProcessors* parameter to schedule DPCs.

### `TargetProcessors` [out]

A bitmask that indicates the target processors for which NDIS should schedule a DPC. This bitmask represents the first 32 processors in processor group 0. Each bit in
the bitmask identifies a CPU. If the caller sets bit 0, NDIS schedules a DPC for CPU 0. If the caller sets bit 1, NDIS
schedules a DPC for CPU 1, and so on.

**Note** NDIS
6.20 and later drivers should not use this parameter to schedule DPCs. Instead, they should set this parameter to zero and use the
[NdisMQueueDpcEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismqueuedpcex) function to schedule DPCs.

## Return value

*MiniportMessageInterrupt* returns **TRUE** if the underlying NIC generated the interrupt; otherwise, it
returns **FALSE**.

## Remarks

Miniport drivers that register for message-signaled interrupts (MSI) support with the
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex) function
must provide a
*MiniportMessageInterrupt* function.

A miniport driver should do as little work as possible in its
*MiniportMessageInterrupt* function. It should defer I/O operations for the interrupts that the NIC
generates to the
[MiniportMessageInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt_dpc) function.

When a NIC generates an MSI, NDIS calls the miniport driver's
*MiniportMessageInterrupt* function.

*MiniportMessageInterrupt* saves required state information about the interrupt and defers as much of
the I/O processing as possible to the
[MiniportMessageInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt_dpc) function.

If the miniport driver requests deferred procedure calls (DPCs) for a specified message, the miniport
driver should disable all further interrupts for that message and reenable the interrupts after all the
DPCs are finished.

The miniport driver should set
*QueueDefaultInterruptDpc* to **TRUE** to schedule a DPC for the default CPU only. The driver can do
this, for example, if:

* The NIC generated the interrupt to signal the completion of a send operation or any other request
  that doesn't run on other CPUs.
* The NIC generated the interrupt to signal received data and the miniport driver cannot process
  received packets in separate DPCs.
* The interrupt indicates received packets and the miniport driver can process received packets in
  separate DPCs, but [receive side scaling (RSS)](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-receive-side-scaling2) is not enabled for the miniport driver. For more information, see
  [OID_GEN_RECEIVE_SCALE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-receive-scale-capabilities) and
  [OID_GEN_RECEIVE_SCALE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-receive-scale-parameters).
* Receive side scaling is enabled for the miniport driver, and the miniport driver can generate
  different messages on every receive queue.

If a miniport driver processes received packets in separate DPCs, the miniport driver sets the
*QueueDefaultInterruptDpc* parameter to **FALSE**. The miniport driver should set the
*TargetProcessors* bit for the CPU that is associated with each nonempty receive queue. NDIS will
schedule a DPC on each of the indicated CPUs in processor group 0.

If
*MiniportMessageInterrupt* shares resources for a specified message, such as NIC registers or state
variables, with another
*MiniportXxx* function that runs at a lower IRQL, that
*MiniportXxx* function must call the
[NdisMSynchronizeWithInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsynchronizewithinterruptex) function. This ensures that the driver's
[MiniportSynchronizeMessageInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_synchronize_interrupt) function accesses the shared resources in a synchronized and
multiprocessor-safe manner.

A miniport driver can call the
[NdisMDeregisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterinterruptex) function from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) or
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function to release resources that it allocated with
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex). After
**NdisMDeregisterInterruptEx** returns, NDIS does not call a miniport driver's
*MiniportMessageInterrupt* or
[MiniportMessageInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt_dpc) function.

NDIS calls
*MiniportMessageInterrupt* at the DIRQL of the MSI that the miniport driver registered in a previous
call to
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex). Therefore,
*MiniportMessageInterrupt* must call the subset of the NDIS functions, such as the
**NdisRaw*Xxx*** or
**NdisRead/WriteRegister*Xxx*** functions, that are safe to call at any IRQL.

### Examples

To define a *MiniportMessageInterrupt* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportMessageInterrupt* function that is named "MyMessageInterrupt", use the **MINIPORT_MESSAGE_INTERRUPT** type as shown in this code example:

```
MINIPORT_MESSAGE_INTERRUPT MyMessageInterrupt;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
BOOLEAN
 MyMessageInterrupt(
    NDIS_HANDLE  MiniportInterruptContext,
    ULONG  MessageId,
    PBOOLEAN  QueueDefaultInterruptDpc,
    PULONG  TargetProcessors
    )
  {...}
```

The **MINIPORT_MESSAGE_INTERRUPT** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_MESSAGE_INTERRUPT** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[IO_INTERRUPT_MESSAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info)

[IO_INTERRUPT_MESSAGE_INFO_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info_entry)

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportMessageInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt_dpc)

[MiniportSynchronizeMessageInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_synchronize_interrupt)

[NDIS_MINIPORT_INTERRUPT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_interrupt_characteristics)

[NdisMDeregisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterinterruptex)

[NdisMQueueDpcEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismqueuedpcex)

[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex)

[NdisMSynchronizeWithInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsynchronizewithinterruptex)

[OID_GEN_RECEIVE_SCALE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-receive-scale-capabilities)

[OID_GEN_RECEIVE_SCALE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-receive-scale-parameters)

[Receive Side Scaling (RSS)](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-receive-side-scaling2)
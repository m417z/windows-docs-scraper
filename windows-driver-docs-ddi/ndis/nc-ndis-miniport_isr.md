# MINIPORT_ISR callback function

## Description

NDIS calls the
*MiniportInterrupt* function when a NIC, or another device that shares the
interrupt with the NIC, generates an interrupt.

**Note** You must declare this function by using the **MINIPORT_ISR** type. For more information,
see the following Examples section.

## Parameters

### `MiniportInterruptContext` [in]

A handle to a block of interrupt context information. The miniport driver supplied this handle in
the
*MiniportInterruptContext* parameter that the miniport driver passed to the
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex) function.

### `QueueDefaultInterruptDpc` [out]

A pointer to a BOOLEAN variable that the miniport driver sets before it returns from this call. A
miniport driver sets this value to **TRUE** to indicate that the driver requires a DPC on the default
(current) CPU. If this value is set to **TRUE**, NDIS ignores the value of the
*TargetProcessors* parameter. If it is set to **FALSE**, NDIS uses the value of the
*TargetProcessors* parameter to schedule DPCs. If
*QueueDefaultInterruptDpc* is **TRUE**, NDIS will schedule a DPC regardless of the
return value from
*MiniportInterrupt*.

### `TargetProcessors` [out]

A bitmask that indicates the target processors for which NDIS should schedule a DPC. This bitmask represents the first 32 processors in processor group 0. Each bit in
the bitmask identifies a CPU. If the caller sets bit 0, NDIS schedules a DPC for CPU 0. If the caller sets bit 1, NDIS
schedules a DPC for CPU 1, and so on. If
*QueueDefaultInterruptDpc* is set to **FALSE** and
*TargetProcessors* is set to zero, NDIS will not schedule any DPCs. Otherwise,
NDIS will schedule DPCs regardless of the return value from
*MiniportInterrupt*.

**Note** NDIS
6.20 and later drivers should not use this parameter to schedule DPCs. Instead, they should set this parameter to zero and use the
[NdisMQueueDpcEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismqueuedpcex) function to schedule DPCs.

## Return value

*MiniportInterrupt* returns one of the following values:

| Return code | Description |
| --- | --- |
| ****TRUE**** | [MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr) determined that the underlying NIC generated the interrupt. |
| ****FALSE**** | [MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr) determined that the underlying NIC did not generate the interrupt. |

**Note** NDIS will queue DPCs based on the values that are specified in the
*QueueDefaultInterruptDpc* and
*TargetProcessors* parameters regardless of the value that
*MiniportInterrupt* returns. However,
*MiniportInterrupt* must still return the correct value.

## Remarks

Miniport drivers that register an interrupt with the
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex) function
must provide a
*MiniportInterrupt* function.

A miniport driver should do as little work as possible in its
*MiniportInterrupt* function. It should defer I/O operations for the interrupts
that the NIC generates to the
[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc) function.

When an interrupt occurs on a NIC's interrupt line, NDIS calls the miniport driver's
*MiniportInterrupt* function.

All NICs can share line-based interrupts with other devices on the I/O bus. If the NIC did not
generate the interrupt,
*MiniportInterrupt* should return **FALSE** immediately so that the system can call
the driver of the device that generated the interrupt. If the
*QueueDefaultInterruptDpc* is set to **FALSE** and the
*TargetProcessors* parameter is set to zero, NDIS will not schedule any DPCs.
Otherwise, NDIS will schedule DPCs regardless of the re*MiniportInterrupt*turn value from
*MiniportInterrupt*.

If the interrupt is for the NIC,
*MiniportInterrupt* dismisses the interrupt on the NIC, saves whatever state it
must about the interrupt, and defers as much of the I/O processing as possible to the
[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc) function.

If the underlying NIC generated the specified interrupt and the miniport driver will request deferred
procedure calls (DPCs), the miniport driver should disable all further interrupts from the NIC and
reenable the interrupts after all the DPCs are finished.

The miniport driver should set
*QueueDefaultInterruptDpc* to **TRUE** to schedule a DPC for the default CPU only.
The driver could do this, for example, if:

* The NIC generated the interrupt to signal the completion of a send operation, or any other request
  that doesn't run on other CPUs.
* The NIC generated the interrupt to signal received data and the miniport driver cannot process
  received packets in separate DPCs.
* The interrupt indicates received packets and the miniport driver can process received packets in
  separate DPCs, but [receive side scaling (RSS)](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-receive-side-scaling2) is not enabled for the miniport driver. For more information,
  see
  [OID_GEN_RECEIVE_SCALE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-receive-scale-capabilities) and
  [OID_GEN_RECEIVE_SCALE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-receive-scale-parameters).

If a miniport driver processes received packets in separate DPCs, the driver sets the
*QueueDefaultInterruptDpc* parameter to **FALSE**. The miniport driver should set the
*TargetProcessors* bit for the CPU that is associated with each nonempty receive
queue. NDIS will schedule a DPC on each of the indicated CPUs.

**Note** NDIS will queue DPCs based on the values that are specified in the
*QueueDefaultInterruptDpc* and
*TargetProcessors* parameters regardless of the value that
*MiniportInterrupt* returns. However,
*MiniportInterrupt* must still return the correct value.

If
*MiniportInterrupt* shares resources, such as NIC registers or state variables,
with another
*MiniportXxx* function that runs at a lower IRQL, that
*MiniportXxx* function must call the
[NdisMSynchronizeWithInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsynchronizewithinterruptex) function. This ensures that the driver's
*MiniportSynchronizeInterrupt* function accesses the shared resources in a
synchronized and multiprocessor-safe manner.

A miniport driver can call the
[NdisMDeregisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterinterruptex) function from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) or
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function to release
resources that it allocated with
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex). After
**NdisMDeregisterInterruptEx** returns, NDIS does not call a miniport
driver's
*MiniportInterrupt* or
[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc) function.

NDIS calls
*MiniportInterrupt* at the DIRQL of the interrupt that the miniport driver
registered in a previous call to
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex). Therefore,
*MiniportInterrupt* must call the subset of the NDIS functions, such as the
**NdisRaw***Xxx* or
**NdisRead/WriteRegister***Xxx* functions, that are safe to call at any IRQL.

### Examples

To define a *MiniportInterrupt* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportInterrupt* function that is named "MyInterrupt", use the **MINIPORT_ISR** type as shown in this code example:

```
MINIPORT_ISR MyInterrupt;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
BOOLEAN
 MyInterrupt(
    NDIS_HANDLE  MiniportInterruptContext,
    PBOOLEAN  QueueDefaultInterruptDpc,
    PULONG  TargetProcessors
    )
  {...}
```

The **MINIPORT_ISR** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_ISR** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc)

[MiniportSynchronizeInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_synchronize_interrupt)

[NDIS_MINIPORT_INTERRUPT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_interrupt_characteristics)

[NdisMDeregisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterinterruptex)

[NdisMQueueDpcEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismqueuedpcex)

[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex)

[NdisMSynchronizeWithInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsynchronizewithinterruptex)

[OID_GEN_RECEIVE_SCALE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-receive-scale-capabilities)

[OID_GEN_RECEIVE_SCALE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-receive-scale-parameters)

[Receive Side Scaling (RSS)](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-receive-side-scaling2)
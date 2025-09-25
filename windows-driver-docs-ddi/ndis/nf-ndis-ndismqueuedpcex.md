# NdisMQueueDpcEx function

## Description

NDIS miniport drivers call the
**NdisMQueueDpcEx** function to schedule DPC calls on CPUs.

## Parameters

### `NdisInterruptHandle` [in]

An interrupt handle that the miniport driver obtained in a previous call to the
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex) function.

### `MessageId` [in]

An MSI message ID for the DPC. If the DPC is for a line-based interrupt, this parameter is not
used and it should be set to zero. Otherwise,
*MessageId* is an index to the
[IO_INTERRUPT_MESSAGE_INFO_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info_entry) structure inside a
[IO_INTERRUPT_MESSAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info) structure. NDIS passes a pointer to the associated
IO_INTERRUPT_MESSAGE_INFO structure at the
**MessageInfoTable** member when the driver successfully registers for MSI with the
**NdisMRegisterInterruptEx** function.

### `TargetProcessors` [in]

A bitmap that indicates target processors. NDIS should schedule a DPC for each target processor
that is indicated in the bitmap. Each bit in
*TargetProcessors* identifies a CPU. If the caller sets bit 0, NDIS schedules a DPC for CPU 0. If the caller sets bit 1, NDIS
schedules a DPC for CPU 1, and so on.

### `MiniportDpcContext` [in]

A pointer to a caller-specified context area. NDIS passes this pointer to the
*MiniportDpcContext* parameter of the
[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc) and
[MiniportMessageInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt_dpc) functions.

## Return value

**NdisMQueueDpcEx** returns a bitmap that indicates target processors. Each bit in the return value
identifies a CPU.

NDIS successfully scheduled a DPC for each target processor that is set in the bitmap. If NDIS sets
bit 0, NDIS scheduled a DPC for CPU 0. If NDIS sets bit 1, NDIS scheduled a DPC for CPU 1, and so
on.

If the driver requested a DPC for a CPU, and NDIS indicates that it did not schedule that DPC, then the DPC was not scheduled because the DPC that maps to this interrupt/processor pair was already scheduled for that CPU.

## Remarks

NDIS 6.20 and later miniport drivers call
**NdisMQueueDpcEx** to request DPC calls for other processors. NDIS calls the
[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc) or
[MiniportMessageInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt_dpc) function to complete the deferred processing of an interrupt.

**NdisMQueueDpcEx** is the same as the
[NdisMQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismqueuedpc) function except that the
*TargetProcessors* parameter has a type of KGROUP_AFFINITY. Therefore,
**NdisMQueueDpcEx** can schedule DPCs on processors in any processor group. To schedule DPCs in more
than one processor group, you can use multiple calls to
**NdisMQueueDpcEx**.

**Note** The
[NdisMQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismqueuedpc),
[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr), and
[MiniportMessageInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt) functions have a
*TargetProcessors* parameter that is a ULONG. This parameter specifies the first 32 processors in
processor group 0.

**Important** NDIS 6.20 and later drivers should always use
**NdisMQueueDpcEx** to schedule DPCs.

## See also

[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr)

[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc)

[MiniportMessageInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt)

[MiniportMessageInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt_dpc)

[NdisMQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismqueuedpc)

[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex)
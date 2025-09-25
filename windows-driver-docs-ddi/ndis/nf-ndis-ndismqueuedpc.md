# NdisMQueueDpc function

## Description

NDIS miniport drivers call the
**NdisMQueueDpc** function to schedule DPC calls on CPUs.

## Parameters

### `NdisInterruptHandle` [in]

An interrupt handle that the miniport driver obtained in a previous call to the
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex) function.

### `MessageId` [in]

An MSI message ID for the DPC. If the DPC is for a line-based interrupt, this parameter is not
used and it should be set to zero. Otherwise,
*MessageId* is an index to the
[IO_INTERRUPT_MESSAGE_INFO_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info_entry) structures inside a
[IO_INTERRUPT_MESSAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_interrupt_message_info) structure. NDIS passes a pointer to the associated
IO_INTERRUPT_MESSAGE_INFO structure at the
**MessageInfoTable** member when the driver successfully registers for MSI with the
**NdisMRegisterInterruptEx** function.

### `TargetProcessors` [in]

A bitmap that indicates the target processors for which NDIS should schedule a DPC. Each bit in
*TargetProcessors* identifies a CPU. If the caller sets bit 0, NDIS schedules a DPC for CPU 0. If the caller sets bit 1, NDIS
schedules a DPC for CPU 1, and so forth.

### `MiniportDpcContext` [in, optional]

A pointer to a caller-specified context area. NDIS passes this pointer to the
*MiniportDpcContext* parameter of the
[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc) and
[MiniportMessageInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt_dpc) functions.

## Return value

**NdisMQueueDpc** returns a bitmap that indicates the target processors for which NDIS successfully
scheduled a DPC. Each bit in the return value identifies a CPU. If NDIS sets bit 0, NDIS scheduled a DPC for CPU 0. If NDIS sets bit 1, NDIS scheduled a DPC
for CPU 1, and so forth.

If the driver requested a DPC for a CPU, and NDIS indicates that it did not schedule that DPC, the
DPC was not scheduled because a DPC was already scheduled for that CPU.

## Remarks

NDIS calls
[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc) or
[MiniportMessageInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt_dpc) to complete the deferred processing of an interrupt. The miniport
driver can call
**NdisMQueueDpc** to request additional DPC calls for other processors.

## See also

[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc)

[MiniportMessageInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt_dpc)

[NdisMQueueDpcEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismqueuedpcex)

[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex)
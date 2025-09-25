# KeSetTargetProcessorDpcEx function

## Description

The **KeSetTargetProcessorDpcEx** routine specifies the processor that a DPC routine will run on.

## Parameters

### `Dpc` [in, out]

A pointer to the caller's [DPC object](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-dpc-objects). This parameter points to a [KDPC](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure, which is an opaque, system structure that represents the DPC object. This object must previously have been initialized by the [KeInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc) routine.

### `ProcNumber` [in]

A pointer to a caller-allocated [PROCESSOR_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_processor_number) structure that identifies the target processor on which the DPC will be queued and executed. This structure specifies a group and a processor within this group.

## Return value

**KeSetTargetProcessorDpcEx** returns STATUS_SUCCESS if the call is successful. Otherwise, it returns the following:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The *ProcNumber* parameter points to an invalid processor number. |

## Remarks

Each processor in a multiprocessor system has its own DPC queue. **KeSetTargetProcessorDpcEx** specifies which processor's queue the system should use when the driver calls the [KeInsertQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc) or [IoRequestDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iorequestdpc) routine to queue a DPC to be run later.

**KeSetTargetProcessorDpcEx** can specify the target processor for both ordinary DPCs and [threaded DPCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/threaded-dpcs). An ordinary DPC cannot be preempted by even a high-priority thread, but a threaded DPC can be preempted by time-critical threads that have sufficiently high priorities.

A related routine, [KeSetTargetProcessorDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kesettargetprocessordpc), specifies a target processor for a DPC, but this routine, unlike **KeSetTargetProcessorDpcEx**, does not specify a group for the target processor. Starting with Windows 7, **KeSetTargetProcessorDpc** assumes that the target processor belongs to group 0. This behavior ensures that existing drivers that call **KeSetTargetProcessorDpc** and that use no group-oriented features will run correctly in multiprocessor systems that have two or more groups. However, drivers that use any group-oriented features in Windows 7 and later versions of the Windows operating system should call **KeSetTargetProcessorDpcEx** instead of **KeSetTargetProcessorDpc**.

A call to **KeSetTargetProcessorDpcEx** that occurs after a DPC object has been queued has no effect on the selection of a processor for the DPC routine to run on. To control the selection of the target processor, a **KeSetTargetProcessorDpcEx** call must occur before the call to **KeInsertQueueDpc** or **IoRequestDpc** that queues the DPC object.

For more information about DPC queues, see [Organization of DPC Queues](https://learn.microsoft.com/windows-hardware/drivers/kernel/organization-of-dpc-queues).

## See also

[IoRequestDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iorequestdpc)

[KDPC](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[KeInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc)

[KeInsertQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc)

[KeSetTargetProcessorDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kesettargetprocessordpc)

[PROCESSOR_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_processor_number)
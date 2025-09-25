# KeSetTargetProcessorDpc function (wdm.h)

## Description

The **KeSetTargetProcessorDpc** routine specifies the processor that a DPC routine will be run on.

## Parameters

### `Dpc` [in, out]

Pointer to the caller's DPC object, which [KeInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc) already initialized.

### `Number` [in]

Specifies the zero-based number of the target processor on which the DPC should be queued and executed.

## Remarks

On multiprocessor systems, each processor has its own DPC queue. The **KeSetTargetProcessorDpc** routine specifies which processor's queue the system should use when the driver calls [KeInsertQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc) or [IoRequestDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iorequestdpc) to queue a DPC to be run later.

Starting with Windows Vista, you can also use **KeSetTargetProcessorDpc** to specify the target processor for [threaded DPCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/threaded-dpcs).

A call to **KeSetTargetProcessorDpcEx** that occurs after a DPC object has been queued has no effect on the selection of a processor for the DPC routine to run on. To control the selection of the target processor, a **KeSetTargetProcessorDpc** call must occur before the call to **KeInsertQueueDpc** or **IoRequestDpc** that queues the DPC object.

For more information about DPC queues, see [Organization of DPC Queues](https://learn.microsoft.com/windows-hardware/drivers/kernel/organization-of-dpc-queues).

Windows 7 and later versions of Windows support processor groups. Drivers that are designed to handle information about processor groups should use the [KeSetTargetProcessorDpcEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettargetprocessordpcex) routine, which specifies a processor group, instead of **KeSetTargetProcessorDpc**, which does not. However, the implementation of **KeSetTargetProcessorDpc** in Windows 7 and later versions of Windows provides compatibility for drivers that were written for earlier versions of Windows, which do not support processor groups. In this implementation, if *Number* is less than the number of active logical processors in group 0, **KeSetTargetProcessorDpc** sets the target for the DPC to the processor in group 0 that is specified by *Number*. Otherwise, the DPC target does not change.

## See also

[IoRequestDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iorequestdpc)

[KeGetCurrentProcessorNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kegetcurrentprocessornumber)

[KeInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc)

[KeInsertQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc)

[KeSetImportanceDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kesetimportancedpc)

[KeSetTargetProcessorDpcEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesettargetprocessordpcex)
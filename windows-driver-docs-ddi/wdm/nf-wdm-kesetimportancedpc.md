# KeSetImportanceDpc function (wdm.h)

## Description

The **KeSetImportanceDpc** routine specifies how soon the DPC routine is run.

## Parameters

### `Dpc` [in, out]

Pointer to the caller's DPC object, which [KeInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc) already initialized.

### `Importance` [in]

Specifies one of the following system-defined values to determine the behavior of [KeInsertQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc) and [IoRequestDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iorequestdpc) when either routine is used to queue the DPC.

#### LowImportance

Place the DPC at the end of the DPC queue, and do not begin processing of the queue.

#### MediumImportance

Place the DPC at the end of the DPC queue. If the DPC is assigned to the current processor's DPC queue, begin processing the queue immediately. **MediumImportance** is the default value for *Importance*.

#### MediumHighImportance

Place the DPC at the end of the DPC queue, and begin processing the queue immediately. MediumHighImportance is available only on Windows Vista and later versions of Windows.

#### HighImportance

Place the DPC at the beginning of the DPC queue, and begin processing the queue immediately.

##### - Importance.HighImportance

Place the DPC at the beginning of the DPC queue, and begin processing the queue immediately.

##### - Importance.LowImportance

Place the DPC at the end of the DPC queue, and do not begin processing of the queue.

##### - Importance.MediumHighImportance

Place the DPC at the end of the DPC queue, and begin processing the queue immediately. MediumHighImportance is available only on Windows Vista and later versions of Windows.

##### - Importance.MediumImportance

Place the DPC at the end of the DPC queue. If the DPC is assigned to the current processor's DPC queue, begin processing the queue immediately. **MediumImportance** is the default value for *Importance*.

## Remarks

The **KeSetImportanceDpc** routine influences how soon a DPC is run after it is queued by determining:

* The location of the DPC within the DPC queue. Typically, the **KeInsertQueueDpc** and **IoRequestDpc** routines place a DPC at the end of the queue. If a driver first calls **KeSetImportanceDpc** with *Importance* = **HighImportance**, **KeInsertQueueDpc** and **IoRequestDpc** will place the DPC at the beginning of the queue.
* When the system begins processing the DPC queue. Typically, **KeInsertQueueDpc** and **IoRequestDpc** immediately begin processing the DPC queue for the current processor. Drivers can specify different values for *Importance* to change this behavior.

By default, DPCs are assigned to the DPC queue for the current processor, so specifying **MediumImportance** or **MediumHighImportance** for *Importance* has the same effect. However, drivers can use [KeSetTargetProcessorDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kesettargetprocessordpc) to change the processor that the DPC will be assigned to.

For Windows Vista and later versions of the Windows operating system, you can use **KeSetImportanceDpc** for threaded DPCs. If the caller sets *Importance* to **HighImportance**, the DPC is placed at the beginning of the queue; otherwise, it is placed at the end. The routine does not affect when the threaded DPC queue is processed. Threaded DPCs are always processed by a dedicated thread at IRQL = PASSIVE_LEVEL. For more information about threaded DPCs, see [Introduction to Threaded DPCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-threaded-dpcs).

Note that a driver must call **KeSetImportanceDpc** before it calls **KeInsertQueueDpc** and **IoRequestDpc** to have any effect.

For more information about how the system processes the DPC queue, see [Organization of DPC Queues](https://learn.microsoft.com/windows-hardware/drivers/kernel/organization-of-dpc-queues).

## See also

[IoRequestDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iorequestdpc)

[KeInitializeDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializedpc)

[KeInsertQueueDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinsertqueuedpc)

[KeSetTargetProcessorDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kesettargetprocessordpc)

[KeSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesynchronizeexecution)
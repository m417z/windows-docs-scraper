## Description

Kernel streaming clients send the KSEVENTDATA structure to the class driver to specify a notification method.

## Members

### `NotificationType`

Contains flags indicating what type of notification should be performed. The following table lists all the possible values for the NotificationType member.

| NotificationType Flag | Description |
|---|---|
| KSEVENTF_EVENT_HANDLE | Indicates that a Win32 synchronization or notification object handle is being passed. The KSEVENTDATA.EventHandle.Event element contains the handle. |
| KSEVENTF_SEMAPHORE_HANDLE | Indicates that a Win32 semaphore handle is being passed. The KSEVENTDATA.SemaphoreHandle.Semaphore element contains the handle. |
| KSEVENTF_EVENT_OBJECT | Indicates that a pointer to a kernel synchronization or notification object is being passed. The KSEVENTDATA.EventObject.Event element contains a pointer to this object. This is available only to kernel-mode clients. |
| KSEVENTF_SEMAPHORE_OBJECT | Indicates that a pointer to a kernel semaphore object is being passed. The KSEVENTDATA.SemaphoreObject.Semaphore element contains a pointer to this object. This is available only to kernel-mode clients. |
| KSEVENTF_DPC | Indicates that a pointer to a kernel DPC structure is being passed. The KSEVENTDATA.Dpc.Dpc element contains a pointer to the DPC. This is available only to kernel-mode clients. |
| KSEVENTF_WORKITEM | Indicates that a pointer to a kernel work item structure is being passed. The KSEVENTDATA.WorkItem.WorkQueueItem contains a pointer to the work item. This is available only to kernel-mode clients. |
| KSEVENTF_KSWORKITEM | Indicates that a pointer to a kernel streaming work item structure is being passed. The KSEVENTDATA.KsWorkItem.WorkQueueItem contains a pointer to the work item, and is queued to a previously registered kernel streaming work item. This is available only to kernel-mode clients. |

### `EventHandle`

Defines the **EventHandle** structure.

### `EventHandle.Event`

Contains a handle to a synchronization event when the KSEVENT_EVENT_HANDLE flag is set.

### `EventHandle.Reserved`

Reserved and set to zero.

### `SemaphoreHandle`

Defines the **SemaphoreHandle** structure.

### `SemaphoreHandle.Semaphore`

Contains a handle to a semaphore when the KSEVENT_SEMAPHORE_HANDLE flag is set.

### `SemaphoreHandle.Reserved`

Reserved and set to zero.

### `SemaphoreHandle.Adjustment`

Contains the adjustment to the semaphore when it is released.

### `EventObject`

Defines the **EventObject** structure.

### `EventObject.Event`

Defines the **PVOID** member **Event**.

### `EventObject.Increment`

Defines the **KPRIORITY** member **Increment**.

### `EventObject.Reserved`

Reserved and set to zero.

### `SemaphoreObject`

Defines the **SemaphoreObject** structure.

### `SemaphoreObject.Semaphore`

Defines the **PVOID** member **Semaphore**.

### `SemaphoreObject.Increment`

Defines the **KPRIORITY** member **Increment**.

### `SemaphoreObject.Adjustment`

Defines the **LONG** member **Adjustment**.

### `Dpc`

Defines the **Dpc** structure.

### `Dpc.Dpc`

Defines the **PKDPC** member **Dpc**.

### `Dpc.ReferenceCount`

Defines the **ULONG** member **ReferenceCount**.

### `Dpc.Reserved`

Reserved and set to zero.

### `WorkItem`

Defines the **WorkItem** structure.

### `WorkItem.WorkQueueItem`

Defines the **PWORK_QUEUE_ITEM** member **WorkQueueItem**.

### `WorkItem.WorkQueueType`

Defines the **WORK_QUEUE_TYPE** member **WorkQueueType**.

### `WorkItem.Reserved`

Reserved and set to zero.

### `KsWorkItem`

Defines the **KsWorkItem** structure.

### `KsWorkItem.WorkQueueItem`

Defines the **PWORK_QUEUE_ITEM** member **WorkQueueItem**.

### `KsWorkItem.KsWorkerObject`

Defines the **PKSWORKER** member **KsWorkerObject**.

### `KsWorkItem.Reserved`

Reserved for future use.

### `Alignment`

Defines the **Alignment** structure.

### `Alignment.Unused`

Not used.

### `Alignment.Alignment`

Reserved for internal use by AVStream. Minidrivers should not manipulate this member.

## Remarks

For more information, see [KS Events](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-events).

## See also

[KDPC](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[KSEVENT](https://learn.microsoft.com/windows-hardware/drivers/stream/ksevent-structure)

[KsIncrementCountedWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksincrementcountedworker)

[KsRegisterWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksregisterworker)

[**WORK_QUEUE_ITEM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_work_queue_item)

[**WORK_QUEUE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_work_queue_type)
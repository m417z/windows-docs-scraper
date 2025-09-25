# IoInitializeWorkItem function

## Description

The **IoInitializeWorkItem** routine initializes a work item that the caller has already allocated.

## Parameters

### `IoObject` [in]

Pointer to the caller's driver object or to one of the caller's device objects. If the caller will later pass the work item to [IoQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitem), *IoObject* must point to a device object.

### `IoWorkItem` [in]

Pointer to the [IO_WORKITEM](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure to initialize.

## Remarks

The driver allocates its own storage for an [IO_WORKITEM](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure, and then calls **IoInitializeWorkItem** to initialize it. Memory must be allocated from nonpaged pool. To determine the number of bytes that is necessary to hold an **IO_WORKITEM** structure, call [IoSizeofWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosizeofworkitem).

An **IO_WORKITEM** structure that is initialized by **IoInitializeWorkItem** must be uninitialized by [IoUninitializeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iouninitializeworkitem) before it is freed.

A related routine, [IoAllocateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateworkitem), both allocates and initializes a work item. By combining allocation and initialization into a single call, **IoAllocateWorkItem** might be more convenient for some drivers to use than **IoInitializeWorkItem**, which does initialization only. However, **IoInitializeWorkItem** is required by drivers that must initialize work items in previously allocated storage.

For example, a driver might allocate a block of storage for a pool of work items. The driver can call **IoInitializeWorkItem** to initialize a work item when the work item is allocated from the pool. The driver can call **IoUninitializeWorkItem** to uninitialize the work item when it is returned to the pool. During the initial storage allocation for the pool, the driver can call **IoSizeofWorkitem** to determine how much storage to allocate for each work item.

For more information about work items, see [System Worker Threads](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-worker-threads).

## See also

[IO_WORKITEM](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[IoAllocateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateworkitem)

[IoQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitem)

[IoQueueWorkItemEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitemex)

[IoSizeofWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosizeofworkitem)

[IoUninitializeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iouninitializeworkitem)
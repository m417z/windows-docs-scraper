# IoAllocateWorkItem function

## Description

The **IoAllocateWorkItem** routine allocates a work item.

## Parameters

### `DeviceObject` [in]

Pointer to the caller's driver object or to one of the caller's device objects. If the caller will later pass the work item to [IoQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitem), *DeviceObject* must point to a device object.

## Return value

**IoAllocateWorkItem** returns a pointer to the allocated [IO_WORKITEM](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure. The routine returns **NULL** if sufficient resources do not exist.

## Remarks

The driver must free the work item that is returned by **IoAllocateWorkItem** by calling [IoFreeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreeworkitem).

**IoAllocateWorkItem** both allocates and initializes a work item. A related routine, [IoInitializeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinitializeworkitem), initializes a work item in storage that the driver has previously allocated. Do not call **IoInitializeWorkItem** to initialize a work item that was allocated by **IoAllocateWorkItem**.

For more information about work items, see [System Worker Threads](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-worker-threads).

## See also

[IO_WORKITEM](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[IoFreeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreeworkitem)

[IoInitializeWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinitializeworkitem)

[IoQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitem)

[IoQueueWorkItemEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioqueueworkitemex)
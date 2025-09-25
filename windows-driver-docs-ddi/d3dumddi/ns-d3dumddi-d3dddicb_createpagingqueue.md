# D3DDDICB_CREATEPAGINGQUEUE structure

## Description

**D3DDDICB_CREATEPAGINGQUEUE** is used with [pfnCreatePagingQueueCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createpagingqueuecb) to create a device paging queue that can be used to synchronize with video memory management operations for the device, such as making the device resource resident.

## Members

### `Priority` [in]

Scheduling priority relative to other paging queues on this device. Paging queues with higher priority values will be processed ahead of paging queues with lower priority values.

### `hPagingQueue` [out]

A paging queue handle that will be used to synchronize paging operations.

### `hSyncObject` [out]

Handle to the monitored fence object used to synchronize paging operations for this paging queue. Destroying the paging queue (either implicitly or explicitly) will automatically destroy this sync object.

### `FenceValueCPUVirtualAddress` [out]

A read-only mapping of the paging fence object value for the CPU. This is a user mode address readable from the process that created the monitored fence object.

### `PhysicalAdapterIndex` [in]

Physical adapter index (engine ordinal) for the queue.

## Remarks

A device can have multiple paging queues created for it. Paging queues can be destroyed either explicitly by calling [pfnDestroyPagingQueueCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroypagingqueuecb), or by implicitly destroying the device they belong to. After the latter, paging queue handles will become invalid.

## See also

[pfnCreatePagingQueueCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createpagingqueuecb)

[pfnDestroyPagingQueueCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroypagingqueuecb)
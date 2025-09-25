# NdisScheduleWorkItem callback function

## Description

**Note** NDIS 5. *x* has been deprecated and is superseded by NDIS 6. *x*. For new NDIS driver development, see [Network Drivers Starting with Windows Vista](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/). For information about porting NDIS 5. *x* drivers to NDIS 6. *x*, see [Porting NDIS 5.x Drivers to NDIS 6.0](https://msdn.microsoft.com/library/Ff570059).

*NdisScheduleWorkItem* inserts a given work item into a queue from which a system worker thread removes the item and gives control to the callback function that the driver previously supplied to [**NdisInitializeWorkItem**](https://msdn.microsoft.com/library/ff552258/(v=vs.85/)).

## Parameters

### `WorkItem` [in]

Pointer to the work item that was set up by a preceding call to **NdisInitializeWorkItem**.

## Return value

*NdisScheduleWorkItem* always succeeds and therefore always returns NDIS\_STATUS\_SUCCESS.

## Remarks

A call to *NdisScheduleWorkItem* allows an NDIS driver to defer some driver-determined operation that could or should be done at a lower IRQL than the raised IRQL at which it is currently running to its worker-thread callback function.

The driver's callback is run within a system thread context at IRQL = PASSIVE\_LEVEL later. This caller-supplied function is responsible for reclaiming the storage that the driver allocated for *WorkItem*. For example, if the driver called **NdisAllocateMemoryWithTag** to provide a context area to **NdisInitializeWorkItem**, its callback function should make the reciprocal call to **NdisFreeMemory** with *WorkItem* before it returns control.

A driver must not wait for its callback routine to complete an operation if it is already holding one synchronization object and might attempt to acquire another. For example, a NDIS driver should release any currently held spin lock(s), and so forth before it calls *NdisScheduleWorkItem*. A highest level NDIS protocol driver also must release any currently held semaphores, mutexes, resource variables, and so forth before it calls *NdisScheduleWorkItem*. Releasing all synchronization resources before queuing a synchronous worker-thread operation prevents deadlocks.

A serialized miniport driver should never attempt to queue a worker-thread callback routine, because there is no way for such a driver to synchronize access to its NIC context area(s) with a worker-thread callback. Consequently, such a serialized NDIS driver cannot share anything in its per-adapter context area with a worker-thread callback function without causing intermittent system crashes.

- Target platform: [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356)
- Version: Not supported for NDIS 6.0 drivers in Windows Vista. Use [**NdisQueueIoWorkItem**](https://msdn.microsoft.com/library/Ff563775)instead. Supported for NDIS 5.1 drivers in Windows Vista and Windows XP.

## See also

- [**NdisAllocateMemoryWithTag**](https://msdn.microsoft.com/library/ff550767/(v=vs.85/))
- [**NdisFreeMemory**](https://msdn.microsoft.com/library/Ff562577)
- [**NdisInitializeWorkItem**](https://msdn.microsoft.com/library/ff552258/(v=vs.85/))
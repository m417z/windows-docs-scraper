# NdisAllocateIoWorkItem function

## Description

NDIS drivers call the
**NdisAllocateIoWorkItem** function to allocate a work item. For more information, see [NDIS I/O Work Items](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-i-o-work-items).

## Parameters

### `NdisObjectHandle` [in]

The handle of an NDIS object that is associated with a device object or driver object.

## Return value

If
**NdisAllocateIoWorkItem** successfully allocates a work item, it returns a handle to the work item.
If it fails,
**NdisAllocateIoWorkItem** returns **NULL**.

## Remarks

NDIS miniport drivers pass
**NdisAllocateIoWorkItem** either of two handles: the adapter handle that NDIS passed to the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function or
the miniport driver handle that NDIS returned when the miniport driver called
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver).

NDIS filter drivers can pass
**NdisAllocateIoWorkItem** the filter driver handle that NDIS returned when the filter driver called
[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver).

NDIS miniport drivers and filter drivers can also pass
**NdisAllocateIoWorkItem** the NDIS device handle that NDIS returned when the driver called
[NdisRegisterDeviceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterdeviceex).
**NdisAllocateIoWorkItem** gets the device object or driver object that is associated with the handle
and passes the device object or driver object to the
[IoAllocateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateworkitem) function.

**Note** Protocol drivers cannot use
**NdisAllocateIoWorkItem** because NDIS does not associate protocol drivers with device objects or
driver objects.

NDIS drivers call the
[NdisQueueIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisqueueioworkitem) function to queue
work items. After a driver calls
**NdisQueueIoWorkItem**, NDIS calls the driver-specified callback function at IRQL = PASSIVE_LEVEL.
This can improve system performance by allowing the current function to end immediately and the driver to
do work later at a lower IRQL.

NDIS drivers must call the
[NdisFreeIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreeioworkitem) function to free the
resources associated with a work item that
**NdisAllocateIoWorkItem** allocated.

Drivers can call
**NdisFreeIoWorkItem** in the callback routine that is passed to
**NdisQueueIoWorkItem**.

If a miniport driver used the handle that NDIS passed to
*MiniportInitializeEx* when it called
**NdisAllocateIoWorkItem**, the work item must be freed before or in the call to the drivers
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function.

If a miniport driver used the handle that
**NdisMRegisterMiniportDriver** returned when the driver called
**NdisAllocateIoWorkItem**, the driver must free the work item before the driver unloads.

In general, a driver must free the work item before the driver unloads.

## See also

[IoAllocateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateworkitem)

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS I/O Work Items](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-i-o-work-items)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[NdisFreeIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreeioworkitem)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisQueueIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisqueueioworkitem)

[NdisRegisterDeviceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterdeviceex)
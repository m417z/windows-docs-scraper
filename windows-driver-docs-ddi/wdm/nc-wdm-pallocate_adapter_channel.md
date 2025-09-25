# PALLOCATE_ADAPTER_CHANNEL callback function

## Description

The **AllocateAdapterChannel** routine prepares the system for a DMA operation on behalf of the target device object, and then calls the driver-supplied [AdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_control) routine to carry out the DMA operation.

## Parameters

### `DmaAdapter` [in]

Pointer to the [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure returned by [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) that represents the bus-master adapter or DMA controller.

### `DeviceObject` [in]

Pointer to the device object that represents the target device for a requested DMA operation.

### `NumberOfMapRegisters` [in]

Specifies the number of map registers to be used in the transfer. This value is the lesser of the number of map registers needed to satisfy the current transfer request, and the number of available map registers returned by [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter).

### `ExecutionRoutine` [in]

Pointer to a driver-supplied [AdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_control) routine. The routine is called when the system DMA controller or bus-master adapter becomes available.

### `Context` [in]

Pointer to the driver-determined context to be passed to the [AdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_control) routine.

## Return value

This routine can return one of the following NTSTATUS values.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The adapter channel has been allocated. The system will call the *AdapterControl* routine once the DMA operation can begin. |
| **STATUS_INSUFFICIENT_RESOURCES** | The *NumberOfMapRegisters* is larger than the value returned by **IoGetDmaAdapter**. The *AdapterControl* routine will not be called. |

## Remarks

**AllocateAdapterChannel**
is not a system routine that can be called directly by name. This routine is callable only by pointer from the address returned in a
[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)
structure. Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter).

A driver calls the **AllocateAdapterControl** routine to register an [AdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_control) routine that performs a DMA operation for the driver. The *AdapterControl* routine carries out a DMA operation using either the system DMA controller or a bus-master adapter.

If the DMA operation can be performed immediately, the system immediately calls *AdapterControl*. If the system DMA controller or bus-master adapter is currently in use, **AllocateAdapterChannel** queues the *AdapterControl* until the adapter becomes available. In either case, **AllocateAdapterChannel** returns STATUS_SUCCESS.

If the system lacks the resources to perform the DMA operation, **AllocateAdapterChannel** returns STATUS_INSUFFICIENT_RESOURCES. In that case, *AdapterControl* is not queued, and the driver should complete the current IRP with the appropriate error code (such as STATUS_INSUFFICIENT_RESOURCES).

This routine reserves exclusive access to a DMA controller channel and map registers for the one or more DMA operations that are required to satisfy the current IRP's transfer request for the specified device.

Only one DMA request can be queued for a device object at any one time. Therefore, the driver should not call **AllocateAdapterChannel** again for another DMA operation on the same device object until the [AdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_control) routine has completed execution. In addition, a driver must not call **AllocateAdapterChannel** from within its *AdapterControl* routine.

The system passes the value of the **CurrentIrp** member of *DeviceObject* as the *Irp* parameter of *AdapterControl*. If **AllocateAdapterChannel** is called from a driver's [StartIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_startio) routine, this is guaranteed to point to the IRP that *StartIo* was called to process. Otherwise, to use the *Irp* parameter of *AdapterControl*, the driver must set **CurrentIrp** to point to the current IRP before calling **AllocateAdapterChannel**.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[FlushAdapterBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers)

[FreeAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_adapter_channel)

[FreeMapRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_map_registers)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)

[MapTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer)

[ReadDmaCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pread_dma_counter)
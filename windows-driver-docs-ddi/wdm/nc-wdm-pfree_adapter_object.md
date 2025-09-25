# PFREE_ADAPTER_OBJECT callback function

## Description

The **FreeAdapterObject** routine releases the specified adapter object after a driver has completed all DMA operations.

## Parameters

### `DmaAdapter` [in]

A pointer to a [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure. This structure is the adapter object that is to be released. This object represents the driver's bus-master DMA device or system DMA channel. The caller obtained this pointer from a previous call to the [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine.

### `AllocationAction` [in]

The type of deallocation that the calling driver requests. Set this parameter to an [IO_ALLOCATION_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_allocation_action) enumeration value. For more information, see the Remarks section.

## Remarks

**FreeAdapterObject**
is not a system routine that can be called directly by name. This routine can be called only by pointer from the address returned in a
[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)
structure. Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) with the **Version** member of the *DeviceDescription* parameter set to DEVICE_DESCRIPTION_VERSION3. If **IoGetDmaAdapter** returns **NULL**, the routine is not available on your platform.

If *AllocationAction* = **DeallocateObject**, the **FreeAdapterObject** call releases the adapter object, and releases any map registers that might be allocated for this object.

If *AllocationAction* = **DeallocateObjectKeepRegisters**, the **FreeAdapterObject** call releases the adapter object, but does not release any map registers. In this case, the driver must explicitly release any allocated map registers by calling the [FreeMapRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_map_registers) routine.

If *AllocationAction* = **KeepObject**, the **FreeAdapterObject** call has no effect.

**FreeAdapterObject** can be used to deallocate DMA resources that are allocated by calls to the [AllocateAdapterChannelEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel_ex), [GetScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list_ex), and [BuildScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list_ex) routines. If the driver calls one of these routines synchronously, the *ExecutionRoutine* parameter is optional and can be omitted. In this case, the driver can use the adapter object and map registers that are allocated by the call. After the driver initiates the DMA transfer, the driver can call **FreeAdapterObject** to deallocate the adapter object and, if necessary, the map registers.

The [FreeAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_adapter_channel) routine is similar to **FreeAdapterObject**. **FreeAdapterChannel** always releases the adapter object and any allocated map registers. This behavior is similar to that of **FreeAdapterObject** if *AllocationAction* = **DeallocateObject**.

## See also

[AdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_control)

[AdapterListControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_list_control)

[AllocateAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel)

[AllocateAdapterChannelEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel_ex)

[BuildScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list_ex)

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[FreeAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_adapter_channel)

[FreeMapRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_map_registers)

[GetScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list_ex)

[IO_ALLOCATION_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_allocation_action)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)
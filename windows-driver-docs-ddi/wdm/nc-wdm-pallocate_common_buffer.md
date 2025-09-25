# PALLOCATE_COMMON_BUFFER callback function

## Description

The **AllocateCommonBuffer** routine allocates memory and maps it so that it is simultaneously accessible from both the processor and a device for DMA operations.

## Parameters

### `DmaAdapter` [in]

Pointer to the [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure returned by [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) that represents the bus-master adapter or DMA controller.

### `Length` [in]

Specifies the number of bytes of memory to allocate.

### `LogicalAddress` [out]

Pointer to a variable that receives the logical address the device can use to access the allocated buffer. Use this address rather than calling [MmGetPhysicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmgetphysicaladdress) because the system can take into account any platform-specific memory restrictions.

### `CacheEnabled` [in]

Specifies whether the allocated memory can be cached.

This parameter is ignored. The operating system determines whether to enable cached memory in the common buffer that is to be allocated. That decision is based on the processor architecture and device bus.

On computers with x86-based, x64-based, and Itanium-based processors, cached memory is enabled. It is assumed that all DMA operations performed by a device are coherent with the relevant CPU caches, which might be caching that memory. If your driver needs to disable caching, call [AllocateCommonBufferEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_common_buffer_ex) instead.

On computers with ARM or ARM 64-based processors, the operating system does not automatically enable cached memory for all devices. The system relies on the **ACPI_CCA** method for each device to determine whether the device is cache-coherent.

## Return value

**AllocateCommonBuffer** returns the base virtual address of the allocated range. If the buffer cannot be allocated, it returns **NULL**.

## Remarks

**AllocateCommonBuffer**
is not a system routine that can be called directly by name. This routine is callable only by pointer from the address returned in a
**DMA_OPERATIONS**
structure. Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter).

**AllocateCommonBuffer** supports DMA in which the device and the processor continuously communicate through system memory, as in a control structure for a bus-master DMA device.

**AllocateCommonBuffer** also supports subordinate devices whose drivers use a system DMA controller's autoinitialize mode.

**AllocateCommonBuffer** does the following:

* Allocates memory that can be reached from both the processor and the device. This memory appears contiguous to the device.
* Allocates map registers to map the buffer, if required by the system.
* Sets up a translation for the device, including loading map registers if necessary.

To use resident system memory economically, drivers should allocate as few of these buffers per device as possible. **AllocateCommonBuffer** allocates at least a page of memory, regardless of the requested *Length*. After a successful allocation requesting fewer than PAGE_SIZE bytes, the caller can access only the requested *Length*. After a successful allocation requesting more than an integral multiple of PAGE_SIZE bytes, any remaining bytes on the last allocated page are inaccessible to the caller.

If a driver needs several pages of common buffer space, but the pages need not be contiguous, the driver should make several one-page requests to **AllocateCommonBuffer** instead of one large request. This approach conserves contiguous memory.

Drivers typically call **AllocateCommonBuffer** as part of device start-up, during their response to a PnP [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) request. After startup, it is possible that only one-page requests will succeed, if any.

## See also

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[FreeCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_common_buffer)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)
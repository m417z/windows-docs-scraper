# NdisAllocateBuffer function

## Description

**Note** NDIS 5. *x* has been deprecated and is superseded by NDIS 6. *x*. For new NDIS driver development, see [Network Drivers Starting with Windows Vista](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/). For information about porting NDIS 5. *x* drivers to NDIS 6. *x*, see [Porting NDIS 5.x Drivers to NDIS 6.0](https://msdn.microsoft.com/library/Ff570059).

**NdisAllocateBuffer** creates a buffer descriptor mapping a specified virtual (sub)range within an already allocated, nonpaged memory block.

## Parameters

### `Status` [out]

Pointer to a caller-supplied variable in which this function returns the final status of the buffer allocation, which is NDIS\_STATUS\_SUCCESS if it returned a valid buffer descriptor pointer at *Buffer* and otherwise NDIS\_STATUS\_FAILURE.

### `Buffer` [out]

Pointer to a caller-supplied variable in which this function returns a pointer to the allocated buffer descriptor.

### `PoolHandle` [in, optional]

Specifies the handle returned by a preceding call to [NdisAllocateBufferPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatebufferpool).

### `VirtualAddress` [in]

Pointer to the base virtual address of previously allocated system-space memory to be mapped in the returned buffer descriptor.

### `Length` [in]

Specifies the number of bytes to be mapped.

## Remarks

Return value: None

**NdisAllocateBuffer** allocates storage for and initializes a buffer descriptor to map a specified range of previously allocated memory, such as memory used for a packet header or a NIC receive buffer.

Buffer descriptor allocation draws on the buffer pool that [NdisAllocateBufferPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatebufferpool) creates. A driver can call **NdisAllocateBuffer** as many times as necessary to allocate the buffer descriptors that it requires if it called **NdisAllocateBufferPool** during initialization.

All lower-level NDIS drivers must allocate all buffer descriptors that they chain to packets from buffer pool. Only highest-level protocol drivers can be given OS-dependent descriptors mapping virtual memory ranges, and, if these memory descriptors are equivalent to NDIS buffer descriptors, a highest-level protocol can pass such descriptors as parameters to *NdisXxx* functions.

- Target platform: [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356)

## See also

- [**NdisAllocateBufferPool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatebufferpool)
- [**NdisAllocateMemoryWithTag**](https://msdn.microsoft.com/library/ff550767/(v=vs.85/))
- [**NdisFreeBuffer**](https://msdn.microsoft.com/library/ff551981/(v=vs.85/))
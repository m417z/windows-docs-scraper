# PFNKSALLOCATOR callback function

## Description

Minidrivers can optionally supply a callback function of type **PFNKSALLOCATOR** as a parameter in calls to [KsEnableEventWithAllocator](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksenableeventwithallocator), [KsPropertyHandlerWithAllocator](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspropertyhandlerwithallocator), and [KsMethodHandlerWithAllocator](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksmethodhandlerwithallocator).

## Parameters

### `Irp` [in]

Specifies the IRP for which the buffer allocation request is being made.

### `BufferSize` [in]

Specifies the size of buffer needed. This size covers all parameters in the request.

### `InputOperation` [in]

Set to **TRUE** if this is an input operation, meaning that on successful return, the Irp->IoStatus.Information field will contain the number of bytes to copy back to the original input buffer.

## Return value

Returns STATUS_SUCCESS if the request is handled. Otherwise returns an appropriate error code.

## Remarks

Typically, pool memory is used for buffer allocations. This enables filters that pass event, property, and method queries directly to hardware to avoid extra data copies by allowing them to provide the buffer into which such data is placed by the standard handling functions. So, a filter may have memory blocks that have already been mapped to an adapter from which buffer allocations can occur.

Since this memory presumably is not typical pool-allocated memory, the filter must perform buffer cleanup on completion of the Irp. This means that for input operations from usermode that are not synchronous, the allocator must allocate an MDL for the destination buffer, probe and lock it, and retrieve a system address. This must be done in order to enable copying of the return data to the original buffer.
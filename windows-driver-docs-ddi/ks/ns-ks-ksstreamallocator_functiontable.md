# KSSTREAMALLOCATOR_FUNCTIONTABLE structure

## Description

Clients can request the function table of a given allocator by sending a KSSTREAMALLOCATOR_FUNCTIONTABLE structure in a KSPROPERTY_STREAMALLOCATOR_FUNCTIONTABLE property request.

## Members

### `AllocateFrame`

Points to a [KStrAllocateFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnallocator_allocateframe) routine.

### `FreeFrame`

Points to a [KStrFreeFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnallocator_freeframe) routine.

## Remarks

This property is only supported by allocators supporting the DISPATCH_LEVEL function interface. Allocators supporting this property must be able to allocate and free frames at IRQL <= DISPATCH_LEVEL.

Because the DISPATCH_LEVEL interface is closely associated with the IRP-based interface, acquiring the function table is likely to result in the creation of an internal notification event to allow pending I/O to be completed when frames are returned to the free list. When the handle to the allocator is closed, the function table pointers are invalid and the associated events are automatically disabled.

This property is only accessible from kernel-mode.

## See also

[KSPROPERTY_STREAMALLOCATOR_FUNCTIONTABLE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-streamallocator-functiontable)

[KStrAllocateFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnallocator_allocateframe)

[KStrFreeFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnallocator_freeframe)
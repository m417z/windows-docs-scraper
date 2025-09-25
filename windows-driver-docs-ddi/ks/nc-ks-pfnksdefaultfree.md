# PFNKSDEFAULTFREE callback function

## Description

An AVStream minidriver's *AVStrMiniAllocatorFreeFrame* routine frees the specified frame.

## Parameters

### `Context` [in]

Pointer to the allocator's context structure created in [AVStrMiniInitializeAllocator](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspininitializeallocator).

### `Buffer` [in]

Pointer to the frame to be freed.

## Remarks

The minidriver specifies this routine's address in the **Free** member of its [KSALLOCATOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksallocator_dispatch) structure. The minidriver passes this structure to the class driver in [KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch).

AVStream calls *AVStrMiniFree* to free a frame, passing as parameters the context structure set in the initialization dispatch and a pointer to the frame to free.

For more information, see [KS Allocators](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-allocators).

## See also

[AVStrMiniInitializeAllocator](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspininitializeallocator)

[KSALLOCATOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksallocator_dispatch)
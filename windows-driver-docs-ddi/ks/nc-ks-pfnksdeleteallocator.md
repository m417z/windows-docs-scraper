# PFNKSDELETEALLOCATOR callback function

## Description

An AVStream minidriver's *AVStrMiniDeleteAllocator* routine deletes the allocator that is associated with a pin.

## Parameters

### `Context` [in]

Pointer to the allocator's context structure created by [AVStrMiniInitializeAllocator](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspininitializeallocator).

## Remarks

The minidriver specifies this routine's address in the **DeleteAllocator** member of its [KSALLOCATOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksallocator_dispatch) structure. The minidriver passes this structure to the class driver in [KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch).

Once this function is called, AVStream will no longer use the allocator to allocate and free memory. This handler should release all system resources reserved by the allocator.

For more information, see [KS Allocators](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-allocators).

## See also

[AVStrMiniInitializeAllocator](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspininitializeallocator)

[KSALLOCATOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksallocator_dispatch)

[KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch)
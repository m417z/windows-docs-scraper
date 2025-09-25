# PFNKSPININITIALIZEALLOCATOR callback function

## Description

An AVStream minidriver's *AVStrMiniInitializeAllocator* routine initializes an allocator that will be associated with a pin.

## Parameters

### `Pin` [in]

Pointer to a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure describing the pin with which the allocator is to be associated.

### `AllocatorFraming` [in]

Pointer to a [KSALLOCATOR_FRAMING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksallocator_framing) structure describing the framing requirements that the allocator should use.

### `Context` [out]

Pointer to a context for the allocator that will be passed as a parameter to the other routines for this structure. For example, the driver could store pin or allocator framing structures for later reference by the other callback routines. Note that other routines for [KSALLOCATOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksallocator_dispatch) must have at least an indirect way of referencing *Pin*. (For instance, [AVStrMiniAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksdefaultallocate) will need to be able to access the *AllocatorFraming* information for *Pin*, and *Context* is the only parameter that AVStream will pass it.)

## Return value

*AVStrMiniInitializeAllocator* should return STATUS_SUCCESS or the error code that it received attempting to create the allocator.

## Remarks

The minidriver specifies this routine's address in the **InitializeAllocator** member of its [KSALLOCATOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksallocator_dispatch) structure. The minidriver passes this structure to the class driver in [KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch).

Note that kernel-mode allocators cannot allocate frames that could eventually reach user mode.

AVStream calls *AVStrMiniInitializeAllocator* to initialize the given allocator. The handler for this routine should prepare to handle memory allocation and free requests.

For more information, see [KS Allocators](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-allocators).

## See also

[AVStrMiniDeleteAllocator](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksdeleteallocator)

[KSALLOCATOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksallocator_dispatch)

[KSALLOCATOR_FRAMING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksallocator_framing)

[KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin)

[KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch)
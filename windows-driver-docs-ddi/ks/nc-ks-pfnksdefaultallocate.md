# PFNKSDEFAULTALLOCATE callback function

## Description

An AVStream minidriver's *AVStrMiniAllocate* routine allocates a frame using the allocator specified in the *Context* parameter.

## Parameters

### `Context` [in]

Pointer to the allocator's context structure created in *AVStrMiniInitializeAllocator*.

## Return value

**Allocate** returns a pointer to the newly allocated memory. Return **NULL** if the attempt to allocate memory failed.

## Remarks

The minidriver specifies this routine's address in the **Allocate** member of its [KSALLOCATOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksallocator_dispatch) structure. The minidriver passes this structure to the class driver in [KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch).

AVStream calls this routine to allocate a frame. The handler should allocate a frame as described by the allocator framing context passed into the initialization dispatch.

For more information, see [KS Allocators](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-allocators).

## See also

[AVStrMiniInitializeAllocator](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspininitializeallocator)

[KSALLOCATOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksallocator_dispatch)

[KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch)
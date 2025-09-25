# _KSALLOCATOR_DISPATCH structure

## Description

The KSALLOCATOR_DISPATCH structure contains the callbacks required for a pin to implement its own kernel-level allocator.

## Members

### `InitializeAllocator`

A pointer to a minidriver-supplied [AVStrMiniInitializeAllocator](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspininitializeallocator) callback routine.

### `DeleteAllocator`

A pointer to a minidriver-supplied [AVStrMiniDeleteAllocator](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksdeleteallocator) callback routine.

### `Allocate`

A pointer to a minidriver-supplied [AVStrMiniAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksdefaultallocate) callback routine.

### `Free`

A pointer to a minidriver-supplied [AVStrMiniAllocatorFreeFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksdefaultfree) callback routine.

## Remarks

By providing a pointer to a KSALLOCATOR_DISPATCH structure in the relevant [KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch) structure, a minidriver declares that the corresponding pin is capable of performing kernel-level allocation. The allocator might or might not be used by the graph manager. Note that memory allocated at kernel level cannot be passed to a user-mode filter.

## See also

[KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch)
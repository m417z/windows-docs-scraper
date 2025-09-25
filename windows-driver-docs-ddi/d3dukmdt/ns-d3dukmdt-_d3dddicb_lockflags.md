# _D3DDDICB_LOCKFLAGS structure

## Description

The D3DDDICB_LOCKFLAGS structure identifies how to lock an allocation.

## Members

### `ReadOnly`

A UINT value that specifies whether the locked allocation can only be read from. Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `WriteOnly`

A UINT value that specifies whether the locked allocation can only be written to. Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `DonotWait`

A UINT value that specifies whether the video memory manager should wait to lock the allocation. If this member is set, the memory manager fails the call to [pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb) with D3DERR_WASSTILLDRAWING if the graphics hardware is using the allocation.

Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `IgnoreSync`

A UINT value that specifies whether the video memory manager should check whether the graphics hardware is using the allocation. If this member is set, the memory manager should not check.

**IgnoreSync** can be set only with an allocation that can be placed in an aperture segment. It cannot be set with a swizzled allocation, or with a cached allocation when cache coherency is not supported by the graphics adapter.

Setting this member is equivalent to setting the fourth bit of the 32-bit **Value** member (0x00000008).

### `LockEntire`

A UINT value that specifies whether the entire allocation region is locked rather than just a subregion.

Setting this member is equivalent to setting the fifth bit of the 32-bit **Value** member (0x00000010).

### `DonotEvict`

A UINT value that specifies whether the video memory manager should evict the allocation so that the lock can succeed. If this member is set, the memory manager should not evict the allocation. If the allocation must be evicted to handle the lock request, the memory manager fails the call to [pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb) with D3DERR_NOTAVAILABLE. Eviction might be necessary when all of the deswizzling apertures are exhausted.

Setting this member is equivalent to setting the sixth bit of the 32-bit **Value** member (0x00000020).

### `AcquireAperture`

A UINT value that specifies whether the video memory manager should call the display miniport driver's [DxgkDdiAcquireSwizzlingRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_acquireswizzlingrange) function to set up an unswizzling aperture for the allocation.

An allocation that was locked without setting **AcquireAperture** cannot be locked again with **AcquireAperture** set.

**AcquireAperture** cannot be set if the allocation can be located only in an aperture segment.

Setting this member is equivalent to setting the seventh bit of the 32-bit **Value** member (0x00000040).

### `Discard`

A UINT value that specifies whether the video memory manager can rename or multiple-buffer the allocation. For more information about renaming allocations, see [Requesting to Rename an Allocation](https://learn.microsoft.com/windows-hardware/drivers/display/requesting-to-rename-an-allocation).

**Discard** is ignored for pinned, primary, or shared allocations.

Setting this member is equivalent to setting the eighth bit of the 32-bit **Value** member (0x00000080).

### `NoExistingReference`

A UINT value that specifies whether the user-mode display driver currently does not have queued in its command buffer a reference to any instance of the allocation that is being locked. The driver should use the **NoExistingReference** member after the video memory manager fails the lock request by using only the **Discard** flag and after the driver flushes its current command buffer to the kernel. The driver should use **NoExistingReference** in combination with **Discard**.

Setting this member is equivalent to setting the ninth bit of the 32-bit **Value** member (0x00000100).

### `UseAlternateVA`

A UINT value that specifies whether the display miniport driver can lock an allocation at a different physical address than the allocation's current segment location or with a different memory footprint than was previously allocated. When this flag is specified, the display miniport driver can update the base address and size of the physical address range that the allocation is CPU accessible through (by updating the **RangeSize** and **CPUTranslatedAddress** members of the [DXGKARG_ACQUIRESWIZZLINGRANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_acquireswizzlingrange) structure in a call to the [DxgkDdiAcquireSwizzlingRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_acquireswizzlingrange) function). When this flag is specified, the video memory manager attempts to allocate a new virtual address to handle the lock request rather than use the allocation backing store virtual address. However, if the video memory manager cannot allocate the new virtual address, the lock request fails.

This flag is also used to lock swizzled or tiled allocations that are currently located in a non-AGP aperture segment. In this type of lock, the video memory manager maps the alternate virtual address to a physical address range that can be unswizzled or untiled on the fly and then redirects the memory access to the system memory pages.

The video memory manager creates the alternate virtual address when the allocation is first locked with **UseAlternateVA** and releases the virtual address in one of the following scenarios:

* The allocation is not accessible to the CPU, and the swizzling range is released for reuse by another allocation.
* The allocation is not accessible to the CPU and is being evicted.
* The allocation is being destroyed.
* The allocation is being paged in after it was evicted while under lock.

Be aware that **UseAlternateVA** can only be used on the primary allocation if the primary allocation was created by specifying the **UseAlternateVA** bit-field flag in the **Flags** member of the [DXGK_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo) structure in a call to the display miniport driver's [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function. A primary allocation that is created in such a way can only be locked with the **UseAlternateVA** flag.

**UseAlternateVA** cannot be used on a shared allocation.

An allocation that was locked with **UseAlternateVA** set cannot be locked again.

**Note** If the user-mode display driver has set **UseAlternateVA** in the **Flags** member of the **D3DDDICB_LOCKFLAGS** structure during a call to the [pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb) function, the display miniport driver should not call the [DxgkCbExcludeAdapterAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_exclude_adapter_access) function.

Setting this member is equivalent to setting the tenth bit of the 32-bit **Value** member (0x00000200).

### `IgnoreReadSync`

A UINT value that specifies whether the video memory manager should wait only for pending Graphics Processing Unit (GPU) write operations to the allocation to complete. If this member is set, the memory manager is not required to wait for GPU read operations to complete. That is, as soon as the last GPU write operation completes, the lock can return even though the GPU might still be reading from the allocation.

**IgnoreReadSync** can be set only with an allocation that can be placed in an aperture segment. It cannot be set with a swizzled allocation, or with a cached allocation when cache coherency is not supported by the graphics adapter.

Setting this member is equivalent to setting the eleventh bit of the 32-bit **Value** member (0x00000400).

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 21 bits (0xFFFFF800) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that is contained in D3DDDICB_LOCKFLAGS that can hold one 32-bit value that identifies how to lock an allocation.

## Remarks

When you use a D3DDDICB_LOCKFLAGS structure to specify how to lock an allocation, you must adhere to the following rules:

* Simultaneously specifying the **ReadOnly** and **WriteOnly** members is invalid.
* The **IgnoreSync** member has no effect if specified with the **Discard** member.
* The **DonotWait** member has no effect if specified with the **Discard** member.
* Simultaneously specifying the **IgnoreSync** and **AcquireAperture** members is invalid.
* Because specifying the **UseAlternateVA** member indicates that an aperture is acquired, the **AcquireAperture** member must also be set.
* Retired or offered allocations cannot be locked. See also [Requesting to Rename an Allocation](https://learn.microsoft.com/windows-hardware/drivers/display/requesting-to-rename-an-allocation).
* An allocation can be locked only if it was created with the **CpuVisible** member set in the [DXGK_ALLOCATIONINFOFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfoflags) structure.
* Only the owner (creator) of a shared allocation can lock it, unless it's a GDI non-managed primary allocation.
* An allocation that is locked with a swizzled range must be unlocked before it can be locked again.

## See also

[D3DDDICB_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_lock)

[DXGK_ALLOCATIONINFOFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfoflags)

[DxgkDdiAcquireSwizzlingRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_acquireswizzlingrange)

[pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb)
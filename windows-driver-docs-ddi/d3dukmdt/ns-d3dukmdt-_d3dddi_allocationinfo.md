# D3DDDI_ALLOCATIONINFO structure

## Description

The **D3DDDI_ALLOCATIONINFO** structure describes an allocation for WDDM v1. User-mode graphics clients should use [**D3DDDI_ALLOCATIONINFO2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationinfo2) instead.

## Members

### `hAllocation`

[out] A **D3DKMT_HANDLE** that represents a kernel-mode handle to the allocation. This handle is associated with the kernel-mode resource handle (if non-NULL) that the Direct3D runtime's [**pfnAllocateCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb) function returns in the **hKMResource** member of the [**D3DDDICB_ALLOCATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_allocate) structure. The user-mode display driver can use this kernel-mode allocation handle to reference the allocation in the command buffer.

### `pSystemMem`

[in] A pointer to system memory that the Direct3D runtime preallocated. Otherwise, this member is NULL if the allocation is to use video memory.

If the allocation is in system memory, the user-mode display driver should assign the buffer in the **pSysMem** member of the [**D3DDDI_SURFACEINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_surfaceinfo) structure for the resource to **pSystemMem**. This buffer is specified when the Direct3D runtime calls the user-mode display driver's [**CreateResource**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource) function to create resources.

### `pPrivateDriverData`

[in/out,opt] A pointer to buffer that contains optional private data that might be required by the display miniport driver to create the allocation. The display miniport driver can also return data in the buffer. When the contents of the buffer are passed to the display miniport driver, the contents must be in a format that the display miniport driver can process.

### `PrivateDriverDataSize`

[in] Size in bytes of the private data.

### `VidPnSourceId`

[in] The zero-based VidPN identification number of the video present source in a path of a video present network (VidPN) topology if the allocation is for the primary surface. The driver should set **VidPnSourceId** only for primary allocation types and not for any other type of allocation. If the driver sets **VidPnSourceId** for any other allocation type in a call to the [**pfnAllocateCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb) function, **pfnAllocateCb** returns D3DDDI_ID_NOTAPPLICABLE.

When the DirectX graphics kernel subsystem initiates the creation of the allocation for the shared primary surface, the display miniport driver can determine the identification number from the **VidPnSourceId** member of the [**D3DKMDDI_SHAREDPRIMARYSURFACEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_sharedprimarysurfacedata) structure that the **pPrivateDriverData** member of the [**DXGK_ALLOCATIONINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo) structure points to.

### `Flags`

[in] A union that contains either a structure or a 32-bit value that identifies the type of allocation.

### `Flags.Primary`

[in] A UINT that specifies whether the allocation is part of the desktop. Such an allocation is implicitly accessible to the CPU. A primary allocation can be either pinned down at creation or not pinned down at creation.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Flags.Stereo`

[in] Supported beginning with Windows 8. A UINT that specifies whether the allocation is a stereo primary allocation. The **Stereo** member can be set only when the **Primary** member is set.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `Flags.Reserved`

[in] This member is reserved and should be set to zero.

### `Flags.Value`

[in] A 32-bit value that identifies the type of allocation.

## Remarks

When the user-mode display driver sets the **Primary** bit-field flag in the **Flags** member of D3DDDI_ALLOCATIONINFO, certain restrictions apply to the [**DXGK_ALLOCATIONINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo) structure in the **pAllocationInfo** member of the [**DXGKARG_CREATEALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createallocation) structure for the allocation in a call to the display miniport driver's [**DxgkDdiCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function. These restrictions include the following:

* The allocation is allocated according to preferences; otherwise, the allocation defaults to the supported write segment set, and all of the specified segments in the write segment set must be CPU-accessible.

* The display miniport driver cannot set the following bit-field flags in the **Flags** member of [**DXGK_ALLOCATIONINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo):

* PermanentSysMem
* Cached
* Protected
* ExistingSysMem
* ExistingKernelSysMem

The D3DDDI_ID_NOTAPPLICABLE constant is defined in *D3dukmdt.h*.

## See also

[**CreateResource**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource)

[**D3DDDICB_ALLOCATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_allocate)

[**D3DDDI_ALLOCATIONINFO2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationinfo2)

[**D3DDDI_SURFACEINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_surfaceinfo)

[**D3DKMDDI_SHAREDPRIMARYSURFACEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_sharedprimarysurfacedata)

[**DXGKARG_CREATEALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createallocation)

[**DXGK_ALLOCATIONINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo)

[**DxgkDdiCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)

[**pfnAllocateCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb)
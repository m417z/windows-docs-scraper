## Description

**D3DKMT_CREATEALLOCATIONFLAGS** is a structure of bit fields that specify how to create an allocation in a call to the [**D3DKMTCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation) function.

## Members

### `CreateResource`

Specifies whether to create a device-specific resource. If you set **CreateShared**, you must also set **CreateResource**.

### `CreateShared`

Specifies whether to create a resource shared across all devices. If you set **CreateShared**, you must also set **CreateResource**. For more information on using **CreateShared**, see the Remarks section.

### `NonSecure`

Specifies whether to create an allocation that can be opened by any process. If **NonSecure** is set, secure and non-secure processes can open the allocation.

### `CreateProtected`

This member is reserved and should be set to zero. Supported starting with Windows 7.

### `RestrictSharedAccess`

Specifies whether to create a resource shared across all devices but with some restrictions. Supported starting with Windows 7.

### `ExistingSysMem`

This member is reserved and should be set to zero. Supported starting with Windows 7. **ExistingSysMem**'s limitations follow:

* **ExistingSystemMem** and **ExistingSection** can't both be set for the same allocation. **ExistingSysMem** is set, **StandardAllocation** must also be set.

* **ExistingSysMem** must be correctly aligned. The existing system memory buffer that the D3D runtime gives to the kernel must be page-aligned and a multiple of page size, otherwise the kernel fails the call to [**D3DKMTCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation).

* When the kernel creates a D3DKMDT_STANDARDALLOCATION_GDISURFACE type of standard allocation:

  * The runtime provides the size of the existing system buffer. Using this size, the kernel creates a standard allocation of GDISURFACE type with the following parameters which KMDs understand correctly:

``` c
    D3DKMDT_GDISURFACEDATA::Width = Size of ExistingSysMem buffer
    D3DKMDT_GDISURFACEDATA::Height = 1
    D3DKMDT_GDISURFACEDATA::Format = D3DDDIFMT_UNKNOWN
    D3DKMDT_GDISURFACEDATA::Type = D3DKMDT_GDISURFACE_TEXTURE_CROSSADAPTER
    ```

* Protect against ExistingSysMem pointer pointing to a DXGALLOCATION which is MemRotated

 The kernel must protect against the scenario where user mode locks an existing DXGALLOCATION and uses the resulting CPU pointer to create an ExistingSysMem standard allocation. This case is invalid if the DXGALLOCATION VAD is MEM_ROTATE, i.e. if the allocation could be in VRAM. The kernel takes the following steps in the create standard allocation with ExistingSysMem call:

  * MemSecure the ExistingSysMem pointer.
  * VirtualQuery the memory. If attributes contain MEM_ROTATE then fail call.
  * MemSecure is only released when this allocation is freed to prevent memory from being changed behind kernel’s back.

### `NtSecuritySharing`

Specifies whether the allocation is shared with an NT handle, meaning that it doesn't have a global **D3DKMT_HANDLE** kernel-mode handle to the resource.

If **NtSecuritySharing** is set to 1 (TRUE):

* The allocation is shared using the [**D3DKMTShareObjects**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtshareobjects) function but doesn't have a global **D3DKMT_HANDLE** handle to the resource.
* **CreateShared** must be set to 1.

For more information on using **NtSecuritySharing**, see the Remarks section. Supported starting with Windows 8.

### `ReadOnly`

Specifies whether the allocation can only be read from. Supported starting with Windows 8.

### `CreateWriteCombined`

This member is reserved and should be set to zero. Supported starting with Windows 8.

### `CreateCached`

This member is reserved and should be set to zero. Supported starting with Windows 8.

### `SwapChainBackBuffer`

This member is reserved and should be set to zero. Supported starting with Windows 8.

### `CrossAdapter`

If set, indicates that the resource is a shared [cross-adapter resource](https://learn.microsoft.com/windows-hardware/drivers/display/using-cross-adapter-resources-in-a-hybrid-system#definition-and-properties-of-a-cross--adapter-resource).

### `OpenCrossAdapter`

If set, indicates that the resource is created by opening a cross adapter resource. Can't be used when allocation is created from the user mode. Supported starting with Windows 8.1 (WDDM 1.3).

### `PartialSharedCreation`

Specifies whether the allocation is created as a partial shared allocation. Supported starting with Windows 8.1 (WDDM 1.3).

### `Zeroed`

[out] Set when the allocation was fulfilled with zeroed pages. Supported starting with Windows 8 (WDDM 1.3).

### `WriteWatch`

[in] Indicates whether to create the allocation with write-watch enabled. Supported starting with Windows 8.1 (WDDM 1.3).

### `StandardAllocation`

[in] When set, instructs *Dxgkrnl* to create a standard allocation using [**pStandardAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createallocation) instead of **pPrivateDriverData**. Either **ExistingSysMem** or **ExistingSection** (but not both) must also be set if **StandardAllocation** is set. Additionally, when creating a **StandardAllocation**, the **CreateShared** and **CrossAdapter** flags must also be set. Supported starting with Windows 10 version 1709 (WDDM 2.3).

### `ExistingSection`

[in] When set, instructs *Dxgkrnl* to use the section handle ([**hSection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationinfo2)) instead of the system memory pointer (**pSystemMem**). **ExistingSystemMem** and **ExistingSection** can't both be set for the same allocation. If **ExistingSection** is set, **StandardAllocation** must also be set. Supported starting with Windows 10 version 1709 (WDDM 2.3).

### `AllowNotZeroed`

[in] Indicates that the allocation can be created without zeroing the pages. Supported starting with Windows 10, version 1903 (WDDM 2.6).

### `PhysicallyContiguous`

[in] Indicates that the allocation must be physically contiguous. Supported starting with Windows 10, version 2004 (WDDM 2.7).

### `NoKmdAccess`

[in] Indicates that the KMD isn't notified about the allocation. Supported starting with Windows 10, version 2004 (WDDM 2.7).

### `SharedDisplayable`

Indicates that the allocation is a shared, displayable resource. Supported starting with Windows 11 (WDDM 3.0).

### `Reserved`

Supported starting with Windows 8.

This member is reserved and should be set to zero.

## Remarks

Objects to be shared by using the [**D3DKMTShareObjects**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtshareobjects) function must first be created with the **NtSecuritySharing** flag value set. This flag value is available in the **D3DKMT_CREATEALLOCATIONFLAGS**, [**D3DKMT_CREATEKEYEDMUTEX2_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createkeyedmutex2_flags), and [**D3DDDI_SYNCHRONIZATIONOBJECT_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobject_flags) structures.

Drivers should follow these guidelines on **D3DKMT_CREATEALLOCATIONFLAGS** sharing flags:

* If the allocation is not shared, set both **CreateShared** and **NtSecuritySharing** to 0.
* If the allocation is shared with a **D3DKMT_HANDLE** data type, set **CreateShared** = 1 and **NtSecuritySharing** = 0.
* If the allocation is shared with an NT handle to the process (and without a global **D3DKMT_HANDLE** kernel-mode handle to the resource), set **CreateShared** = 1 and **NtSecuritySharing** = 1.

## See also

[**D3DKMTCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation)

[**D3DKMT_CREATEALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createallocation)
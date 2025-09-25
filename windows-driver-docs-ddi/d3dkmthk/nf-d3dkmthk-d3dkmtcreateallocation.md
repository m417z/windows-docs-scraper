## Description

The **D3DKMTCreateAllocation** function creates or adds allocations of system or video memory. User-mode graphics client drivers should call [**D3DKMTCreateAllocation2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation2) instead (see Remarks).

## Parameters

### `unnamedParam1`

[in, out] **pData**: A pointer to a [**D3DKMT_CREATEALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createallocation) structure that contains information for creating allocations.

## Return value

**D3DKMTCreateAllocation** returns STATUS_SUCCESS if the operation succeeds. Otherwise, it might return an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code such as one of the following values:

| Return code | Description |
| ----------- | ----------- |
| STATUS_DEVICE_REMOVED | The graphics adapter was stopped or the display device was reset. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |
| STATUS_NO_MEMORY | This routine could not complete because of insufficient system memory. |
| STATUS_NO_VIDEO_MEMORY | This routine could not complete because of insufficient video memory. The video memory manager attempts to virtualize video memory. However, if the virtualization fails (such as when virtual address space runs out), the memory manager might return this error code. |

## Remarks

User-mode graphics client drivers should call [**D3DKMTCreateAllocation2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation2) instead. One reason is that Windows Subsystem for Linux (WSL) doesn't support **D3DKMTCreateAllocation**(nf-d3dkmthk-d3dkmtcreateallocation2.md).

User mode (in this case, the D3D runtime) calls **D3DKMTCreateAllocation** to create allocations and resources. An allocation can be associated with a resource or it can stand alone.

When user mode calls [**D3DKMTCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation), the UMD provides private driver data describing the allocation. *Dxgkrnl* takes this private driver data and passes it to the KMD who then fills out a description of each allocation in a way understood by *VidMm*. The UMD data contains information such as the resource type (texture, swapchain, etc). The KMD translates this data to things like size, alignment, a set of memory segments that the allocation can be located, preferences for these segments, and so forth.

**D3DKMTCreateAllocation** can also be called to add additional allocations to a resource at anytime. The only restrictions are that all shared allocations must be associated with a resource and additional allocations cannot be added to an existing shared resource.

### Examples

#### Creating a stand-alone allocation in video memory that isn't associated with a resource

The following code example demonstrates how **D3DKMTCreateAllocation** can be used to create a stand-alone allocation in video memory that is not associated with a resource.

```c
D3DKMT_HANDLE CreateStandAloneAllocation(D3DKMT_HANDLE hDevice, VOID* pPrivateAllocationInfo, UINT Size)
{
    D3DKMT_CREATEALLOCATION CreateAllocation;
    D3DDDI_ALLOCATIONINFO AllocationInfo;

    memset(&CreateAllocation, 0, sizeof(CreateAllocation));
    CreateAllocation.hDevice = hDevice;
    CreateAllocation.NumAllocations = 1;
    CreateAllocation.pAllocationInfo = &AllocationInfo;

    AllocationInfo.hAllocation = NULL;
    AllocationInfo.pSystemMem = NULL;  // Vidmem allocation
    AllocationInfo.pPrivateDriverData = pPrivateAllocationInfo;  // Contains format, size, and so on.
    AllocationInfo.PrivateDriverDataSize = Size;

    if (NT_SUCCESS((*pfnKTCreateAllocation)(&CreateAllocation))) {
        return AllocationInfo.hAllocation;
    }
    return 0;
}
```

#### Creating a resource with a single system memory allocation

The following code example demonstrates how **D3DKMTCreateAllocation** can be used to create a resource with a single system memory allocation.

```c
HRESULT CreateSysmemResource(D3DKMT_HANDLE hDevice,
                             UINT AllocationSize,
                             VOID* pResourceData,
                             UINT ResourceDataSize,
                             VOID* pAllocationData,
                             UINT AllocationDataSize,
                             D3DKMT_HANDLE* phResource,
                             D3DKMT_HANDLE* phAllocation)
{
    D3DKMT_CREATEALLOCATION CreateAllocation;
    D3DDDI_ALLOCATIONINFO AllocationInfo;
    VOID* pSysMem;

    *phResource = NULL;
    *phAllocation = NULL;

    // For a sysmem allocation, preallocate the memory.
    pSysMem = MemAlloc(AllocationSize);
    if (pSysMem == NULL) {
        return E_OUTOFMEMORY;
    }

    memset(&CreateAllocation, 0, sizeof(CreateAllocation));
    CreateAllocation.hDevice = hDevice;
    CreateAllocation.Flags.CreateResource = TRUE;
    CreateAllocation.pPrivateDriverData = pResourceData;
    CreateAllocation.PrivateDriverDataSize = ResourceDataSize;
    CreateAllocation.NumAllocations = 1;
    CreateAllocation.pAllocationInfo = &AllocationInfo;

    AllocationInfo.hAllocation = NULL;
    AllocationInfo.pSystemMem = pSysMem;
    AllocationInfo.pPrivateDriverData = pAllocationData;
    AllocationInfo.PrivateDriverDataSize = AllocationDataSize;

    if (NT_SUCCESS((*pfnKTCreateAllocation)(&CreateAllocation))) {
        *phResource = CreateAllocation.hResource;
        *phAllocation = AllocationInfo.hAllocation;
        return S_OK;
    }
    MemFree(pSysMem);
    return E_FAIL;
}
```

#### Creating a standard allocation with ExistingSysMem

The following code example shows the arguments to pass to **D3DKMTCreateAllocation** to create a standard allocation with **ExistingSysMem**. The existing system memory buffer that the runtime provides to the kernel must be page-aligned and a multiple of the page size; otherwise the kernel fails the call.

```c
    UINT PrivateDriverDataEstimate = 2048;

    D3DDDI_ALLOCATIONINFO2 AllocInfo = {};
    AllocInfo.pSystemMem = SomeValidPageAlignedSysMem;
    AllocInfo.VidPnSourceId = SomeVidPnSourceId;

    D3DKMDT_CREATESTANDARDALLOCATION StandardAlloc = {};
    StandardAlloc.Type = D3DKMT_STANDARDALLOCATIONTYPE_EXISTINGHEAP;
    StandardAlloc.ExistingHeapData.Size = SizeOfSystemMemBuffer; // Multiple of PAGE SIZE

    D3DKMT_CREATEALLOCATION CreateAlloc = {};
    CreateAlloc.hDevice = SomeDevice;
    CreateAlloc.NumAllocations = 1;
    CreateAlloc.pAllocationInfo2 = &AllocInfo;
    CreateAlloc.pStandardAllocation = &StandardAlloc;
    CreateAlloc.Flags.ExistingSysMem = TRUE;

    ntStatus = D3DKMTCreateAllocation(&CreateAlloc);
```

Argument limitations for **D3DKMTCreateAllocation**:

* **ExistingSysMem** (or **ExistingSection**) is only supported with **StandardAllocation** and vice versa.
* **NumAllocations** supported is 1.
* Only one of **ExistingSysMem** or **ExistingSection** can be set.
* When creating a **StandardAllocation**, the **CreateShared** and **CrossAdapter** flags must always be set.
* **ExistingSysMem** (or **ExistingSection**) can't be created against an existing resource (**D3DKMT_CREATALLOCATION::hResource**).

## See also

[**D3DKMT_CREATEALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createallocation)

[**D3DKMTCreateAllocation2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation2)
# D3DKMTCreateAllocation2 function

## Description

The **D3DKMTCreateAllocation2** function creates or adds allocations of system or video memory.

## Parameters

### `unnamedParam1`

[in, out] **pData**: A pointer to a [**D3DKMT_CREATEALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createallocation) structure that contains information for creating allocations.

## Return value

**D3DKMTCreateAllocation2** returns STATUS_SUCCESS if the operation succeeds. Otherwise, it might return an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code such as one of the following values:

| Return code | Description |
| ----------- | ----------- |
| STATUS_DEVICE_REMOVED | The graphics adapter was stopped or the display device was reset. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |
| STATUS_NO_MEMORY | This routine could not complete because of insufficient system memory. |
| STATUS_NO_VIDEO_MEMORY | This routine could not complete because of insufficient video memory. The video memory manager attempts to virtualize video memory. However, if the virtualization fails (such as when virtual address space runs out), the memory manager might return this error code. |

## Remarks

A user-mode graphics client can call **D3DKMTCreateAllocation2** to create allocations and resources. An allocation can be associated with a resource or it can stand alone.

**D3DKMTCreateAllocation2** can also be called to add additional allocations to a resource at anytime. The only restrictions are that all shared allocations must be associated with a resource and additional allocations cannot be added to an existing shared resource.

### Examples

#### Creating a stand-alone allocation in video memory that isn't associated with a resource

The following code example demonstrates how a user-mode graphics client can use **D3DKMTCreateAllocation2** to create a stand-alone allocation in video memory that is not associated with a resource.

```c
D3DKMT_HANDLE CreateStandAloneAllocation(D3DKMT_HANDLE hDevice, VOID* pPrivateAllocationInfo, UINT Size)
{
    D3DKMT_CREATEALLOCATION CreateAllocation;
    D3DDDI_ALLOCATIONINFO2 AllocationInfo;

    memset(&CreateAllocation, 0, sizeof(CreateAllocation));
    CreateAllocation.hDevice = hDevice;
    CreateAllocation.NumAllocations = 1;
    CreateAllocation.pAllocationInfo2 = &AllocationInfo;

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

### Creating a resource with a single system memory allocation

The following code example demonstrates how a user-mode graphics client can use **D3DKMTCreateAllocation2** to create a resource with a single system memory allocation.

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
    D3DDDI_ALLOCATIONINFO2 AllocationInfo;
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

## See also

[**D3DKMT_CREATEALLOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createallocation)
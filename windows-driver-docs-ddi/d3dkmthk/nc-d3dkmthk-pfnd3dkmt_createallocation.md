# PFND3DKMT_CREATEALLOCATION callback function

## Description

The **D3DKMTCreateAllocation** function creates allocations of system or video memory.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_CREATEALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createallocation) structure that contains information for creating allocations.

## Return value

**D3DKMTCreateAllocation** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **STATUS_SUCCESS** | Allocations were successfully created. |
| **STATUS_DEVICE_REMOVED** | The graphics adapter was stopped or the display device was reset. |
| **STATUS_INVALID_PARAMETER** | Parameters were validated and determined to be incorrect. |
| **STATUS_NO_MEMORY** | [D3DKMTCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation) could not complete because of insufficient memory. |
| **STATUS_NO_VIDEO_MEMORY** | [D3DKMTCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation) could not complete because of insufficient video memory. The video memory manager attempts to virtualize video memory; however, if the virtualization fails (such as, when virtual address space runs out), the memory manager might return this error code. |

This function might also return other NTSTATUS values.

## Remarks

The OpenGL ICD uses the **D3DKMTCreateAllocation** function to create allocations and resources. An allocation can be associated with a resource, or an allocation can stand alone. The **D3DKMTCreateAllocation** function can also be used to add additional allocations to a resource at anytime. The only restrictions are that all shared allocations must be associated with a resource and additional allocations cannot be added to an existing shared resource.

#### Examples

The following code example demonstrates how an OpenGL ICD can use **D3DKMTCreateAllocation** to create a stand-alone allocation in video memory that is not associated with a resource.

```cpp
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

The following code example demonstrates how an OpenGL ICD can use **D3DKMTCreateAllocation** to create a resource with a single system memory allocation.

```cpp
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

## See also

[D3DKMT_CREATEALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createallocation)
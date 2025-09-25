# D3DKMTGetSharedPrimaryHandle function

## Description

The **D3DKMTGetSharedPrimaryHandle** function retrieves the global shared handle for the primary surface.

## Parameters

### `unnamedParam1`

*pData* [in, out]

A pointer to a [D3DKMT_GETSHAREDPRIMARYHANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getsharedprimaryhandle) structure that describes the parameters that are required to retrieve the shared handle.

## Return value

**D3DKMTGetSharedPrimaryHandle** returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The handle was successfully retrieved.|
|STATUS_DEVICE_REMOVED|The graphics adapter was stopped or the display device was reset.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other NTSTATUS values.

## Remarks

The primary surface is typically created by the Microsoft DirectX graphics kernel subsystem (*Dxgkrnl.sys*) every time the display mode changes (although, in some situations, the shared primary might not exist). If an OpenGL application attempts to create a primary surface, it typically must open the existing shared primary. To open the shared primary, the OpenGL application must use **D3DKMTGetSharedPrimaryHandle** to retrieve the global shared handle for the primary surface.

**Example**

The following code example demonstrates how an OpenGL ICD can use **D3DKMTGetSharedPrimaryHandle** to create a primary surface by opening the shared handle.

```cpp
HRESULT OpenSharedPrimarySurface(D3DKMT_HANDLE hAdapter,
                                 D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId,
                                 D3DKMT_HANDLE hDevice,
                                 VOID* pPrivateDriverData,
                                 UINT PrivateDriverDataSize,
                                 D3DKMT_HANDLE* phResource,
                                 D3DKMT_HANDLE* phAllocation)
{
    D3DKMT_CREATEALLOCATION CreateAllocation;
    D3DDDI_ALLOCATIONINFO AllocationInfo;
    D3DKMT_GETSHAREDPRIMARYHANDLE GetHandleData;

    *phResource = 0;
    *phAllocation = 0;

    // Get the shared handle.
    GetHandleData.hAdapter = hAdapter;
    GetHandleData.VidPnSourceId = VidPnSourceId;

    if (!NT_SUCCESS((*pfnKTGetSharedPrimaryHandle)(&GetHandleData))) {
        return E_FAIL;
    }

    // Was a shared primary created by the kernel?
    if (GetHandleData.hSharedPrimary == NULL) {
        return E_FAIL;
    }

    CreateAllocation.hDevice = hDevice;
    CreateAllocation.hResource = NULL;
    CreateAllocation.hGlobalShare = GetHandleData.hSharedPrimary;
    CreateAllocation.Flags.CreateResource =
    CreateAllocation.Flags.CreateShared = TRUE;
    CreateAllocation.pPrivateRuntimeData = NULL;
    CreateAllocation.PrivateRuntimeDataSize = 0;
    CreateAllocation.pPrivateDriverData = NULL;
    CreateAllocation.PrivateDriverDataSize = 0;
    CreateAllocation.NumAllocations = 1;
    CreateAllocation.pAllocationInfo = &AllocationInfo;

    AllocationInfo.hAllocation = NULL;
    AllocationInfo.pSystemMem = NULL;
    AllocationInfo.pPrivateDriverData = pPrivateData;
    AllocationInfo.PrivateDriverDataSize = PrivateDataSize;

    if (NT_SUCCESS((*pfnKTCreateAllocation)(&CreateAllocation))) {
        *phResource = CreateAllocation.hResource;
        *phAllocation = AllocationInfo.hAllocation;
        return S_OK;
    }
    return E_FAIL;
}
```

## See also

[D3DKMT_GETSHAREDPRIMARYHANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getsharedprimaryhandle)
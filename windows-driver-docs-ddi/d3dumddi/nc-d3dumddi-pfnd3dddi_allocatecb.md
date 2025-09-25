# PFND3DDDI_ALLOCATECB callback function

## Description

The **pfnAllocateCb** function allocates system or video memory.

## Parameters

### `hDevice` [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDICB_ALLOCATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_allocate) structure that describes the allocation.

## Return value

**pfnAllocateCb** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The memory was successfully allocated. |
| **E_INVALIDARG** | Parameters were validated and determined to be incorrect. |
| **E_OUTOFMEMORY** | pfnAllocateCb could not allocate memory that was required for it to complete. |
| **D3DERR_OUTOFVIDEOMEMORY** | pfnAllocateCb could not complete because of insufficient video memory. The video memory manager attempts to virtualize video memory; however, if the virtualization fails (such as, when virtual address space runs out), the memory manager might return this error code. |
| **D3DDDIERR_DEVICEREMOVED** | pfnAllocateCb could not initiate a call to the display miniport driver's [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function because a Plug and Play (PnP) stop or a Timeout Detection and Recovery (TDR) event occurred. The user-mode display driver function that called pfnAllocateCb (typically, the [CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource), [CreateResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource), or [CreateResource(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource) function) must return this error code back to the Direct3D runtime. <br>**Direct3D Version 9** Note: For more information about returning error codes, see [Returning Error Codes Received from Runtime Functions](https://learn.microsoft.com/windows-hardware/drivers/display/returning-error-codes-received-from-runtime-functions).<br>**Direct3D Versions 10 and 11** Note: If the driver function does not return a value (that is, has VOID for a return parameter type), the driver function calls the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function to send an error code back to the runtime. For more information about handling error codes, see [Handling Errors](https://learn.microsoft.com/windows-hardware/drivers/display/handling-errors). |

This function might also return other HRESULT values.

## Remarks

A user-mode display driver calls **pfnAllocateCb** to allocate system or video memory (also known as an *allocation*). The Microsoft DirectX graphics kernel subsystem (*Dxgkrnl.sys*) then calls the display miniport driver's [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function to interpret and store the private data that was passed in the **pfnAllocateCb** request. The display miniport driver returns information from the *DxgkDdiCreateAllocation* call that the video memory manager (which is part of *Dxgkrnl.sys*) uses to actually allocate the memory.

The user-mode display driver typically creates an allocation in response to a call to its [CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource), [CreateResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource), or [CreateResource(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource) function. However, the user-mode display driver can create an allocation at anytime--for example, when the user-mode display driver's [CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice), or [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function creates scratch-pad areas in video memory.

The user-mode display driver can create the following types of allocations:

* System memory allocations in which the Microsoft Direct3D runtime preallocates the system memory. In this situation, the user-mode display driver cannot set alignment or any other parameter. If the user-mode display driver requires preallocated system memory that is accessible by the hardware, it calls **pfnAllocateCb**. The Direct3D runtime returns the system memory pointer in the **pSystemMem** member of the [D3DDDI_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationinfo) structure for elements in the **pAllocationInfo** member of the [D3DDDICB_ALLOCATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_allocate) structure that is pointed to by *pData*. If the user-mode display driver does not require preallocated system memory that is accessible by the hardware, it should not call **pfnAllocateCb** for this type of memory.
* System and video memory allocations in which the user-mode display driver can participate in the creation.

When the driver attempts to create multiple allocations, the driver can associate all of the allocations with a parent resource (for example, when creating a flipping chain in which each backbuffer is an individual allocation). The driver can perform such an association by setting the **hResource** member of the [D3DDDICB_ALLOCATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_allocate) structure that is pointed to by *pData* to the value that was passed to the driver's [CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource), [CreateResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource), or [CreateResource(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource) function. In response, the Direct3D runtime returns a kernel-mode resource handle (which is of the D3DKMT_HANDLE data type) in the **hKMResource** member of D3DDDICB_ALLOCATE. The user-mode display driver can subsequently insert this kernel-mode resource handle in the command stream for use by the display miniport driver.

The display miniport driver can call the [DxgkCbGetHandleData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_gethandledata) function on this kernel-mode resource handle (typically within its [DxgkDdiRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render) function) to obtain private data that is associated with the resource, or the display miniport driver can call the [DxgkCbEnumHandleChildren](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_enumhandlechildren) function to obtain all of the allocations that are associated with the resource. The display miniport driver can also call the [DxgkCbGetHandleParent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_gethandleparent) function to obtain the parent kernel-mode resource handle from a child allocation handle.

Note that if the **hResource** member of D3DDDICB_ALLOCATE is set to **NULL** when the user-mode display driver calls **pfnAllocateCb**, the allocation is associated with the device instead of with a resource. The driver can determine only that the difference is semantic. Associating allocations with a resource is optional but recommended for debugging and diagnostic purposes.

**Direct3D Version 9 Note:** For more information about creating and destroying resources, see [Handling Resource Creation and Destruction](https://learn.microsoft.com/windows-hardware/drivers/display/handling-resource-creation-and-destruction).

**Direct3D Version 11 Note:** For more information about how the driver calls **pfnAllocateCb**, see [Changes from Direct3D 10](https://learn.microsoft.com/windows-hardware/drivers/display/changes-from-direct3d-10).

The following code example shows how to allocate memory for a resource.

```cpp
    D3DDDICB_ALLOCATE           allocCB;
    D3DDDI_ALLOCATIONINFO       allocInfo;
    HRESULT                     hr;
    memset(&allocInfo,   0, sizeof(allocInfo));
    memset(&allocCB,     0, sizeof(allocCB));
    // Set the VidPN source ID for the primary and fullscreen back buffer
    if (m_dwCurResCaps.Primary) {
        allocInfo.Flags.Primary = TRUE;
        allocInfo.VidPnSourceId = m_VidPnSourceId;
    }
    // Check if the allocation is in system memory
    if (pSysMem) {
        allocInfo.pSystemMem = pSysMem;
    }
    // Use the runtime handle of the resource being created
    // NOTE: This is critical for supporting a shared resource
    allocCB.hResource = m_hCurResRuntime;

    allocCB.NumAllocations = 1;
    allocCB.pAllocationInfo = &allocInfo;

    hr = m_d3dCallbacks.pfnAllocateCb(m_hD3D, &allocCB);

    if (FAILED(hr)) {
        allocInfo.hAllocation = NULL;
    }
    else {
        *phAllocation = allocInfo.hAllocation;
    }

    return (hr);
```

## See also

[CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice)

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource)

[CreateResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createresource)

[CreateResource(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createresource)

[D3DDDICB_ALLOCATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_allocate)

[D3DDDI_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationinfo)

[D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)

[DxgkCbEnumHandleChildren](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_enumhandlechildren)

[DxgkCbGetHandleData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_gethandledata)

[DxgkCbGetHandleParent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_gethandleparent)

[DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)

[Direct3D Runtime Functions Called by the User-Mode Display Drivers](https://learn.microsoft.com/windows-hardware/drivers/display/direct3d-runtime-functions-called-by-user-mode)
# PFND3DDDI_DEALLOCATECB callback function

## Description

The **pfnDeallocateCb** callback function releases allocations or a kernel-mode resource object if the resource object was created.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDICB_DEALLOCATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_deallocate) structure that describes the resource to release.

## Return value

**pfnDeallocateCb** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The memory was successfully released.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

This function might also return other HRESULT values.

## Remarks

The user-mode display driver can release allocations in the following ways:

* Individually, by setting the **hResource** member of the [D3DDDICB_DEALLOCATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_deallocate) structure that is pointed to by *pData* to **NULL** and populating the array in the **HandleList** member of D3DDDICB_DEALLOCATE with handles of the allocations to release
* In a group, by setting **hResource** to a resource handle whose allocations are to be released. If **hResource** is non-**NULL**, the **HandleList** and **NumAllocations** members of D3DDDICB_DEALLOCATE are ignored.

Note that if the user-mode display driver sets **hResource** to **NULL** and populates all array elements in **HandleList** to release all allocations, the driver must subsequently call the **pfnDeallocateCb** function again to only release the resource by setting **hResource** to the handle to the resource.

Note that the **pfnDeallocateCb** function is distinct from the user-mode display driver's [DestroyResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroyresource) or [DestroyResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyresource) function. However, the user-mode display driver typically calls **pfnDeallocateCb** in response to a call to its *DestroyResource* or **DestroyResource(D3D10)** function.

**Direct3D Version 9 Note:** For more information about creating and destroying resources, see [Handling Resource Creation and Destruction](https://learn.microsoft.com/windows-hardware/drivers/display/handling-resource-creation-and-destruction).

**Direct3D Version 11 Note:** For more information about how the driver calls **pfnDeallocateCb**, see [Changes from Direct3D 10](https://learn.microsoft.com/windows-hardware/drivers/display/changes-from-direct3d-10).

The following code example shows how to release a resource.

```
    D3DDDICB_DEALLOCATE deAllocCB;
    HRESULT             hr;
    D3DKMT_HANDLE       hKMAllocHandle;

    memset(&deAllocCB, 0, sizeof(deAllocCB));

    deAllocCB.hResource = m_hCurResRuntime;

    hr = m_d3dCallbacks.pfnDeallocateCb(m_hD3D, &deAllocCB);
    if ((m_hCurResRuntime) && (SUCCEEDED(hr))) {
        m_bCurResFreed = TRUE;
    }
```

## See also

[D3DDDICB_DEALLOCATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_deallocate)

[D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)

[DestroyResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroyresource)

[DestroyResource(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyresource)

[pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb)
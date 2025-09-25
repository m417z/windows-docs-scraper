# PFND3DDDI_PRESENTCB callback function

## Description

The **pfnPresentCb** function copies content from a source allocation.

## Parameters

### `hDevice`

A handle to a display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDICB_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_present) structure that describes the source allocation that content is copied from.

## Return value

**pfnPresentCb** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|Content was successfully copied.|
|E_OUTOFMEMORY|pfnPresentCb could not complete because of insufficient memory.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

This function might also return other HRESULT values.

## Remarks

The user-mode display driver sets the **hContext** member of the [D3DDDICB_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_present) structure that is pointed to by the *pData* parameter to a context that it previously created by calling the [pfnCreateContextCb](https://learn.microsoft.com/previous-versions/ff568895(v=vs.85)) function. The user-mode display driver must create at least one context when the Microsoft Direct3D runtime calls the driver's [CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice) or [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function to create a device. The Direct3D runtime sends the present operation to a created context.

**Direct3D Version 11 Note:** For more information about how the driver calls **pfnPresentCb**, see [Changes from Direct3D 10](https://learn.microsoft.com/windows-hardware/drivers/display/changes-from-direct3d-10).

#### Examples

The following code example shows how to color-fill a destination surface.

```cpp
    HRESULT hr=S_OK;
    // A color-fill request that does not have a source surface
    D3DDDICB_PRESENT    PresentCBData = {0};

    PresentCBData.hContext = m_sContexts[MULTI_ENGINE_NODE_3D].hContext;
    PresentCBData.hSrcAllocation = NULL;

    if (pPresent->hDstResource) {
        DWORD   dwDstSurf = ((DWORD)(DWORD_PTR)pPresent->hDstResource) + pPresent->DstSubResourceIndex;
        _ASSERT(dwDstSurf < m_RTbl.Size());
        m_RTbl[dwDstSurf].m_qwBatch = m_qwBatch;
        PresentCBData.hDstAllocation = R200GetSurfaceAllocHandle(m_pR200Ctx, dwDstSurf);
    }

    hr = m_d3dCallbacks.pfnPresentCb(m_hD3D, &PresentCBData);

    return hr;
```

## See also

[CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice)

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3DDDICB_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_present)

[D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)

[pfnCreateContextCb](https://learn.microsoft.com/previous-versions/ff568895(v=vs.85))
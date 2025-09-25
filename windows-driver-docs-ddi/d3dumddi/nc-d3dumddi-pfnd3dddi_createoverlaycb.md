# PFND3DDDI_CREATEOVERLAYCB callback function

## Description

The **pfnCreateOverlayCb** function creates a kernel-mode overlay object and calls the display miniport driver to display the overlay.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDICB_CREATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_createoverlay) structure that describes the overlay to create.

## Return value

**pfnCreateOverlayCb** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The overlay object was successfully created.|
|D3DDDIERR_NOTAVAILABLE|pfnCreateOverlayCb failed because of a lack of overlay hardware or bandwidth.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|
|E_OUTOFMEMORY|pfnCreateOverlayCb could not allocate memory that was required for it to complete.|

This function might also return other HRESULT values.

## Remarks

The **pfnCreateOverlayCb** function returns a handle to the newly created kernel-mode overlay object in the **hKernelOverlay** member of the [D3DDDICB_CREATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_createoverlay) structure that is pointed to by *pData*. The user-mode display driver passes this handle in calls to the following functions:

* [pfnDestroyOverlayCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroyoverlaycb)
* [pfnFlipOverlayCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_flipoverlaycb)
* [pfnUpdateOverlayCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updateoverlaycb)

The following code example shows how to create an overlay object.

```cpp
D3DKMT_HANDLE g_hOverlay = NULL;

HRESULT CD3DContext::CreateOverlay(D3DDDIARG_CREATEOVERLAY* pCreateOverlay) {
    D3DDDICB_CREATEOVERLAY CreateCB;
    DWORD_PTR dwResource = (DWORD_PTR) pCreateOverlay->OverlayInfo.hResource;
    dwResource += pCreateOverlay->OverlayInfo.SubResourceIndex;
    LONG dwTempPitch;

    pCreateOverlay->hOverlay = (HANDLE) 0x27;

    CreateCB.VidPnSourceId = 0;
    CreateCB.OverlayInfo.hAllocation = R200GetAllocationHandle(m_pR200Ctx,
                                     (DWORD)dwResource,
                                      &dwTempPitch);

    CreateCB.OverlayInfo.DstRect.left = pCreateOverlay->OverlayInfo.DstRect.left;
    CreateCB.OverlayInfo.DstRect.right = pCreateOverlay->OverlayInfo.DstRect.right;
    CreateCB.OverlayInfo.DstRect.top = pCreateOverlay->OverlayInfo.DstRect.top;
    CreateCB.OverlayInfo.DstRect.bottom = pCreateOverlay->OverlayInfo.DstRect.bottom;

    CreateCB.OverlayInfo.SrcRect.left = pCreateOverlay->OverlayInfo.SrcRect.left;
    CreateCB.OverlayInfo.SrcRect.right = pCreateOverlay->OverlayInfo.SrcRect.right;
    CreateCB.OverlayInfo.SrcRect.top = pCreateOverlay->OverlayInfo.SrcRect.top;
    CreateCB.OverlayInfo.SrcRect.bottom = pCreateOverlay->OverlayInfo.SrcRect.bottom;

    CreateCB.OverlayInfo.pPrivateDriverData = "This is a test";
    CreateCB.OverlayInfo.PrivateDriverDataSize = 10;

    HRESULT hr = m_d3dCallbacks.pfnCreateOverlayCb(m_hD3D, &CreateCB);

    if (SUCCEEDED(hr)) {
        g_hOverlay = CreateCB.hKernelOverlay;
    }

    return hr;
}
```

## See also

[D3DDDICB_CREATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_createoverlay)

[D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)

[pfnDestroyOverlayCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroyoverlaycb)

[pfnFlipOverlayCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_flipoverlaycb)

[pfnUpdateOverlayCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updateoverlaycb)
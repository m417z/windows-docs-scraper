# PFND3DDDI_SETDISPLAYMODECB callback function

## Description

The **pfnSetDisplayModeCb** function sets the allocation that is used to scan out to the display.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDICB_SETDISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_setdisplaymode) structure that describes the allocation that is used to scan out.

## Return value

**pfnSetDisplayModeCb** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The display mode was successfully set. |
| **E_INVALIDARG** | Parameters were validated and determined to be incorrect. |
| **D3DDDIERR_INCOMPATIBLEPRIVATEFORMAT** | The user-mode display driver must convert the format of the surface that is associated with the allocation that the hPrimaryAllocation member of [D3DDDICB_SETDISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_setdisplaymode) specifies into the format attribute that the PrivateDriverFormatAttributemember of D3DDDICB_SETDISPLAYMODE specifies. The driver should then call pfnSetDisplayModeCb again. The driver could allocate a new allocation, perform a conversion bit-block transfer (bitblt) from the old primary surface to the new, and then destroy the old primary as long as the driver uses the new allocation handle for this allocation for all subsequent operations. The driver should repeat this process until pfnSetDisplayModeCb returns a different return value. |

This function might also return other HRESULT values.

## Remarks

After the Microsoft Direct3D runtime calls the user-mode display driver's [SetDisplayMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setdisplaymode) or [SetDisplayModeDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_1_ddi_base_functions) function to set the primary surface to be scanned out to the display, the user-mode display driver calls the **pfnSetDisplayModeCb** function to set the underlying primary allocation that is used for scanning out.

**Note** Before the user-mode display driver calls **pfnSetDisplayModeCb** to set a new display mode that uses an extended format, a multiple-sampling method, or both, the driver must ensure that the current GDI display mode has the same resolution as the new display mode; otherwise, **pfnSetDisplayModeCb** returns E_INVALIDARG.

**Direct3D Version 11 Note:** For more information about how the driver calls **pfnSetDisplayModeCb**, see [Changes from Direct3D 10](https://learn.microsoft.com/windows-hardware/drivers/display/changes-from-direct3d-10).

#### Examples

The following code example shows how to set the allocation for scanning out to the display.

```cpp
HRESULT CD3DContext::SetDisplayMode(CONST D3DDDIARG_SETDISPLAYMODE* pSetDisplayMode) {
    DWORD   dwSrcSurf = ((DWORD)(DWORD_PTR)pSetDisplayMode->hResource) + pSetDisplayMode->SubResourceIndex;
    HRESULT hr;
    // Timestamp the source surface
    m_RTbl[dwSrcSurf].m_qwBatch = m_qwBatch;
    // Send the presentation request to the display miniport driver
    D3DDDICB_SETDISPLAYMODE SetDisplayModeCBData = {0};

    SetDisplayModeCBData.hPrimaryAllocation = R200GetSurfaceAllocHandle(m_pR200Ctx,
                                        dwSrcSurf);

    hr = m_d3dCallbacks.pfnSetDisplayModeCb(m_hD3D, &SetDisplayModeCBData);

    return (hr);
}
```

## See also

[D3DDDICB_SETDISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_setdisplaymode)

[D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)

[SetDisplayMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setdisplaymode)

[SetDisplayModeDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_1_ddi_base_functions)
# PFND3DDDI_PRESENTMULTIPLANEOVERLAYCB callback function

## Description

Copies content from a source multiplane overlay allocation to a destination allocation. Can be called by Windows Display Driver Model (WDDM) 1.3 or later user-mode display drivers.

## Parameters

### `hDevice`

A handle to a display device (graphics context).

### `unnamedParam2`

*pPresent* [in]

A pointer to a [D3DDDICB_PRESENTMULTIPLANEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicb_presentmultiplaneoverlay) structure that describes the source and destination allocations that content is copied from and to.

## Return value

Returns one of these values:

|Return code|Description|
|--- |--- |
|S_OK|Content was successfully copied.|
|E_OUTOFMEMORY|The function could not complete because of insufficient memory.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

## Remarks

The user-mode display driver should call this function only after it has successfully processed a call by the Microsoft DirectX Graphics Infrastructure (DXGI) runtime to the [pfnPresentMultiplaneOverlay (D3D)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_presentmultiplaneoverlay) function.

**Note** When the display driver calls **pfnPresentMultiPlaneOverlayCb (D3D)**, it must maintain the same order of allocations in the **AllocationInfo** array member of the [D3DDDICB_PRESENTMULTIPLANEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicb_presentmultiplaneoverlay) structure as it received from the Microsoft Direct3D runtime when the runtime called [pfnPresentMultiplaneOverlay (D3D)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_presentmultiplaneoverlay).

For example, the allocation handle in index 1 of **AllocationInfo** must represent the same resource that was passed to the driver in index 1 of the *pPresentPlanes* member of the [D3DDDIARG_PRESENTMULTIPLANEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddiarg_presentmultiplaneoverlay) structure used with [pfnPresentMultiplaneOverlay (D3D)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_presentmultiplaneoverlay).

## See also

[D3DDDIARG_PRESENTMULTIPLANEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddiarg_presentmultiplaneoverlay)

[D3DDDICB_PRESENTMULTIPLANEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddicb_presentmultiplaneoverlay)

[pfnPresentMultiplaneOverlay (D3D)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_presentmultiplaneoverlay)
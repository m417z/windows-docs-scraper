# PFND3DDDI_SETDISPLAYMODE callback function

## Description

The *SetDisplayMode* function switches to a display mode or primary that is not supported by the GDI desktop.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_SETDISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setdisplaymode) structure that specifies parameters for setting the display mode.

## Return value

*SetDisplayMode* returns S_OK or an appropriate error result if the display mode is not successfully set.

## Remarks

The Microsoft Direct3D runtime calls *SetDisplayMode* to switch to a display mode or primary that is not supported by the GDI desktop. The following list describes examples of such primaries:

* Primaries that are created with 10-bits-per-channel (10:10:10:2) display and render target formats (for example, D3DFMT_A2R10G10B10)
* Multiple-sampled primaries where the multiple-sampling is performed while scanning-out
* Persistent primaries that are used by full-screen Microsoft DirectX version 9.L applications

The Direct3D runtime calls the user-mode display driver's [CreateResource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createresource) function to create the primary to be scanned out. However, the driver should program the hardware to scan out only when its *SetDisplayMode* function is called. Therefore, the runtime sets the **hResource** and **SubResourceIndex** members of the [D3DDDIARG_SETDISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setdisplaymode) structure that is pointed to by the *pData* parameter to the primary that was created through the call to the driver's *CreateResource* function. The driver should then translate the primary that is represented by **hResource** and **SubResourceIndex** to a primary allocation handle. After the driver makes this translation, the driver should pass the resulting handle in a call to the [pfnSetDisplayModeCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setdisplaymodecb) function, which then initiates a call to the display miniport driver's [DxgkDdiCommitVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_commitvidpn) function.

The user-mode display driver can set the **hPrimaryAllocation** member of the [D3DDDICB_SETDISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_setdisplaymode) structure in the call to **pfnSetDisplayModeCb** to scan out any allocation. However, the allocation must be marked as a primary (that is, the user-mode display driver must have set the **Primary** bit-field flag in the **Flags** member of the [D3DDDI_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationinfo) structure in a call to the [pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb) function to create the allocation).

## See also

[D3DDDIARG_SETDISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setdisplaymode)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[pfnSetDisplayModeCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setdisplaymodecb)
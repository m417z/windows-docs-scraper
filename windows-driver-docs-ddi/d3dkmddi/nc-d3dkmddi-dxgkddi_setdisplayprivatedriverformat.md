# DXGKDDI_SETDISPLAYPRIVATEDRIVERFORMAT callback function

## Description

The *DxgkDdiSetDisplayPrivateDriverFormat* function changes the private-format attribute of a video present source.

## Parameters

### `hAdapter` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pSetDisplayPrivateDriverFormat` [in]

A pointer to a [DXGKARG_SETDISPLAYPRIVATEDRIVERFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setdisplayprivatedriverformat) structure that contains function arguments.

## Return value

*DxgkDdiSetDisplayPrivateDriverFormat* returns STATUS_SUCCESS if it succeeds; otherwise, it returns STATUS_UNSUCCESSFUL to indicate that the driver could not change the private-format attribute of the given video present source.

## Remarks

The DirectX graphics kernel subsystem calls the display miniport driver's *DxgkDdiSetDisplayPrivateDriverFormat* function after the user-mode display driver calls the [pfnSetDisplayPrivateDriverFormatCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setdisplayprivatedriverformatcb) callback function. For example, the user-mode display driver might call **pfnSetDisplayPrivateDriverFormatCb** to change the swizzling format of the video present source when a full-screen flipping change is created. The DirectX graphics kernel subsystem then calls the display miniport driver's *DxgkDdiSetDisplayPrivateDriverFormat* to change the private-driver format of the video present source. This allows for the primary allocation to be displayed on the video present source without a need for translation of the primary surface.

**Note** *DxgkDdiSetDisplayPrivateDriverFormat* does not apply the private-driver format that the **PrivateDriverFormatAttribute** member of the [DXGKARG_SETDISPLAYPRIVATEDRIVERFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setdisplayprivatedriverformat) structure that is pointed to by *pSetDisplayPrivateDriverFormat* specifies to any allocation. *DxgkDdiSetDisplayPrivateDriverFormat* applies the private-driver format directly to the video present source. For example, *DxgkDdiSetDisplayPrivateDriverFormat* might reprogram the DAC registers to scan from a different swizzling format.

*DxgkDdiSetDisplayPrivateDriverFormat* should be made pageable.

## See also

[DXGKARG_SETDISPLAYPRIVATEDRIVERFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setdisplayprivatedriverformat)

[pfnSetDisplayPrivateDriverFormatCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setdisplayprivatedriverformatcb)
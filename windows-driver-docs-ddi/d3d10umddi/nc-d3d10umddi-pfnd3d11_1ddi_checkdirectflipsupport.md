# PFND3D11_1DDI_CHECKDIRECTFLIPSUPPORT callback function

## Description

Called by the Desktop Window Manager (DWM) to verify that the user-mode driver supports Direct Flip operations, in which video memory is seamlessly flipped between an application's managed primary allocations and the DWM's managed primary allocations.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hResource1*

A resource in the application's swapchain.

### `unnamedParam3`

*hResource2*

A resource in the DWM's swapchain.

### `CheckDirectFlipFlags`

If this parameter has a value of **D3D11_1DDI_CHECK_DIRECT_FLIP_IMMEDIATE**, seamless flipping should occur immediately and does not have to be synchronized with a VSync interrupt.

### `pSupported` [out]

Set to **TRUE** if the driver can seamlessly flip video memory between an application's managed primary allocations and the DWM's managed primary allocations. Otherwise, set to **FALSE**.

## Remarks

This function is called at least once before the DWM attempts to present to a Direct Flip swapchain. It is also called after each mode change occurs, or after the DWM re-creates its own swapchain for any reason.

The user-mode driver should ensure that the managed primary allocations of the application and the DWM have the following compatible resources:

* Stereo resources.
* Multiple Sample Anti Aliasing (MSAA) formats.
* Swizzle formats. If the swizzle can only be changed at every VSync interval, ensure that the *CheckDirectFlipFlags* parameter does not have a value of **D3D11_1DDI_CHECK_DIRECT_FLIP_IMMEDIATE**.
* Both managed primary allocations should be created using the same **VidPnSourceId** value in the [D3DDDI_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationinfo) structure.
* Display adapter configurations are linked.

The user-mode driver might need to call the kernel-mode driver to perform these validations. To do this, call the [pfnEscapeCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_escapecb) callback function and then call the [DxgkCbGetHandleData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_gethandledata) function to access the kernel-mode driver's resource allocation data.

## See also

[D3D11_1_DDI_CHECK_DIRECT_FLIP_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1_ddi_check_direct_flip_flags)

[D3DDDI_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationinfo)

[DxgkCbGetHandleData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_gethandledata)

[pfnEscapeCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_escapecb)
# PFND3DDDI_CHECKDIRECTFLIPSUPPORT callback function

## Description

Called by the Desktop Window Manager (DWM) to verify that the user-mode driver supports Direct Flip operations, in which video memory is seamlessly flipped between an application's managed primary allocations and the DWM's managed primary allocations.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDIARG_CHECKDIRECTFLIPSUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_checkdirectflipsupport) structure that defines the parameters for the operation.

## Return value

 Returns S_OK or an appropriate error result if the operation is not successfully performed.

## Remarks

This function is called at least once before the DWM attempts to present to a Direct Flip swapchain. It is also called after each mode change occurs, or after the DWM re-creates its own swapchain for any reason.

The user-mode driver should ensure that the managed primary allocations of the application and the DWM have the following compatible resources:

* Stereo resources.
* Multiple Sample Anti Aliasing (MSAA) formats.
* Swizzle formats. If the swizzle can only be changed at every VSync interval, ensure that the *CheckDirectFlipFlags* member of the [D3DDDI_CHECK_DIRECT_FLIP_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_check_direct_flip_flags) structure does not have a value of **D3D11_1DDI_CHECK_DIRECT_FLIP_IMMEDIATE**.
* Both managed primary allocations should be created using the same **VidPnSourceId** value in the [D3DDDI_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationinfo) structure.
* Display adapter configurations are linked.

The user-mode driver might need to call the kernel-mode driver to perform these validations. To do this, call the [pfnEscapeCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_escapecb) callback function and then call the [DxgkCbGetHandleData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_gethandledata) function to access the kernel-mode driver's resource allocation data.

Because the DWM typically creates its own device using the highest possible Microsoft Direct3D feature level, the DWM will not call this function if the hardware supports a Direct3D device driver interface (DDI) that is greater than version 9.3. However, any Microsoft Direct3D 9 driver should implement this function to enable the Direct Flip user experience.

## See also

[D3DDDI_CHECK_DIRECT_FLIP_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_check_direct_flip_flags)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)
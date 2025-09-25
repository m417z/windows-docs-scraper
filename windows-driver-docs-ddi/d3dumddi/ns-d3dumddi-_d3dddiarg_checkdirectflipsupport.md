# _D3DDDIARG_CHECKDIRECTFLIPSUPPORT structure

## Description

Specifies resources used for Direct Flip operations, in which video memory is seamlessly flipped between an application's managed primary allocations and the Desktop Window Manager's (DWM) managed primary allocations. This structure is pointed to by the *pData* parameter of the [CheckDirectFlipSupport](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_checkdirectflipsupport) function.

## Members

### `hAppSwapchainResource` [in]

A resource in the application's swapchain.

### `hDWMSwapchainResource` [in]

A resource in the DWM's swapchain.

### `CheckDirectFlipFlags` [in]

If this member has a value of **D3DDDI_CHECKDIRECTFLIP_IMMEDIATE**, seamless flipping should occur immediately and does not have to be synchronized with a VSync interrupt.

### `Supported` [out]

Set to **TRUE** if the driver can seamlessly flip video memory between an application's managed primary allocations and the DWM's managed primary allocations. Otherwise, set to **FALSE**.

## See also

[CheckDirectFlipSupport](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_checkdirectflipsupport)
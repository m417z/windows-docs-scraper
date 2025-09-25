# PFND3DDDI_RECLAIMRESOURCES callback function

## Description

Called by the Microsoft Direct3D runtime to reclaim video memory resources that it previously offered for reuse.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_RECLAIMRESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_reclaimresources) structure that defines the video memory resources to reclaim.

## Return value

Returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The video memory resources were successfully reclaimed.<br>This error code is returned if the driver does not need to call the [pfnReclaimAllocationsCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reclaimallocationscb) function. |
| **E_INVALIDARG** | An invalid parameter was supplied.<br>This error code is returned if the driver calls the [pfnReclaimAllocationsCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reclaimallocationscb) function and that function returns E_INVALIDARG. |
| **D3DDDIERR_DEVICEREMOVED** | The video memory manager or display miniport driver could not complete the operation because either a Plug and Play (PnP) Stop event or a Timeout Detection and Recovery (TDR) event occurred.<br>This error code is returned if the driver calls the [pfnReclaimAllocationsCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reclaimallocationscb) function and that function returns D3DDDIERR_DEVICEREMOVED.<br>**Note:** If this error code is returned, the driver's calling function (typically the [ReclaimResourcesDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_2_ddi_base_functions) routine) must return this error code to the Direct3D runtime. |

## See also

[D3DDDIARG_RECLAIMRESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_reclaimresources)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[OfferResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_offerresources)

[ReclaimResourcesDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_2_ddi_base_functions)

[pfnReclaimAllocationsCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reclaimallocationscb)
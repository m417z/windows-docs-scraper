# PFND3DDDI_OFFERALLOCATIONS2CB callback function

## Description

Called by the user-mode display driver to offer video memory allocations for reuse.

## Parameters

### `hDevice`

A handle to the display device (graphics context). The Direct3D runtime passed the user-mode driver this handle as the **hDevice** member of the [D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice) structure at device creation.

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDICB_OFFERALLOCATIONS2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_offerallocations2cb) structure that defines the video memory allocations that the driver offers.

## Return value

Returns one of the following values.

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The allocations were successfully offered.<br>**Note:** If the driver does not need to call [pfnOfferAllocations2Cb]() , it should return S_OK.|
| **D3DDDIERR_DEVICEREMOVED** | The video memory manager or display miniport driver could not complete the operation because either a Plug and Play (PnP) Stop event or a Timeout Detection and Recovery (TDR) event occurred.<br>**Note:** If this error code is returned, the driver's calling function (typically the [pfnOfferResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_offerresources) routine) must return this error code to the Direct3D runtime. |
| **E_INVALIDARG** | An invalid parameter was supplied. |

## Remarks

The user-mode display driver calls **pfnOfferAllocations2Cb** to notify the Microsoft DirectX graphics kernel subsystem that, after it completes any previously submitted render operations, it can offer the allocations' memory for other processes to use.

After the driver calls **pfnOfferAllocations2Cb** to offer an allocation to reuse, it must call [pfnReclaimAllocations3Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reclaimallocations3cb) before it locks the allocation or submits it for rendering operations.

**pfnOfferAllocations2Cb** functions identically to [pfnOfferAllocationsCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_offerallocationscb), except that it takes flags into account through the pData parameter.

## See also

[D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice)

[D3DDDICB_OFFERALLOCATIONS2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_offerallocations2cb)

[D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)

[pfnOfferResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_offerresources)

[pfnReclaimAllocations3Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reclaimallocations3cb)
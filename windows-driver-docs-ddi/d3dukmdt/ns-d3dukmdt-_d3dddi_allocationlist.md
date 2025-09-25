# D3DDDI_ALLOCATIONLIST structure

## Description

The **D3DDDI_ALLOCATIONLIST** structure describes information about an allocation specification that is used in direct memory access (DMA) buffering.

## Members

### `hAllocation`

[in] The allocation handle returned by the [**D3DKMTOpenResource**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenresource) function in the **hAllocation** member of the [**D3DDDI_OPENALLOCATIONINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_openallocationinfo) structure, or by the [**D3DKMTCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation) function in the **hAllocation** member of the [**D3DDDI_ALLOCATIONINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationinfo) structure.

### `WriteOperation`

[in] A UINT that can hold information about whether the allocation can be written to. Setting to 1 indicates the allocation can be written to.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `DoNotRetireInstance`

[in] A UINT that can hold information about whether the allocation can be retired. Setting to 1 indicates that the video memory manager should not retire the instance of the allocation because the driver will reference it again in a subsequent DMA buffer (for example, a manual broadcast of a DMA buffer to multiple contexts). All instances of an allocation are eventually retired. This flag is rarely used.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `OfferPriority`

[in] A value from the [**D3DDDI_OFFER_PRIORITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_offer_priority) enumeration that indicates the importance of video memory resources that the user-mode display driver offers for reuse.

If **OfferPriority** does not have a value of **D3DDDI_OFFER_PRIORITY_NONE**, the allocation is considered to be offered after the DMA buffer is processed.

Setting this member is equivalent to setting bits 3 through 5 of the 32-bit **Value** member (0x0000001C).

Supported starting with Windows 8.

### `Reserved`

[in] This member is reserved and should be set to zero.

### `Value`

[in] A 32-bit value that identifies information about an allocation specification used in DMA buffering.

## See also

[**CreateDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice)

[**D3DDDIARG_CREATEDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice)

[**D3DDDICB_RENDER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_render)

[**D3DDDI_OFFER_PRIORITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_offer_priority)

[**pfnRenderCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb)
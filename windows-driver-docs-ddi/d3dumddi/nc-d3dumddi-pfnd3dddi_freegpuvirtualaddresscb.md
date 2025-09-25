# PFND3DDDI_FREEGPUVIRTUALADDRESSCB callback function

## Description

**pfnFreeGpuVirtualAddressCb** releases a range of graphics processing unit (GPU) virtual addresses that was previously reserved or mapped.

The callback is a synchronous operation. The freed virtual address should not be accessed immediately after the call. If there are outstanding [pfnMapGpuVirtualAddressCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_mapgpuvirtualaddresscb) and [pfnUpdateGpuVirtualAddressCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updategpuvirtualaddresscb) operations, which reference the virtual address, they will be ignored after the virtual address is freed. A new virtual address range can be allocated in place of the freed one immediately after return from the function.

The user mode driver must ensure that no allocation, which is used for current rendering operations, is mapped to the address range.

**Note** When an allocation is freed through [pfnDeallocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_deallocatecb) all outstanding GPU virtual addresses are automatically released.

## Parameters

### `hDevice`

A handle to the display device.

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDICB_FREEGPUVIRTUALADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_freegpuvirtualaddress) structure that describes the operation to perform.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[D3DDDICB_FREEGPUVIRTUALADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_freegpuvirtualaddress)

[pfnDeallocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_deallocatecb)

[pfnMapGpuVirtualAddressCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_mapgpuvirtualaddresscb)

[pfnUpdateGpuVirtualAddressCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updategpuvirtualaddresscb)
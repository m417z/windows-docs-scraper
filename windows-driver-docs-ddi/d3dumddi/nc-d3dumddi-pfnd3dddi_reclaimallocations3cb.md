# PFND3DDDI_RECLAIMALLOCATIONS3CB callback function

## Description

**pfnReclaimAllocations3Cb** is called by the user mode driver to reclaim video memory allocations that were previously offered for reuse.

## Parameters

### `hDevice`

A handle to the display device.

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDICB_RECLAIMALLOCATIONS3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reclaimallocations3cb) structure that defines the allocations to reclaim. The previously used discarded array is replaced by a pResults member in this iteration.

## Return value

Returns one of the following values.

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The allocations were successfully reclaimed. |
| **E_INVALIDARG** | An invalid parameter was supplied. |
| **D3DDDIERR_DEVICEREMOVED** | The video memory manager or display miniport driver could not complete the operation because either a Plug and Play (PnP) Stop event or a Timeout Detection and Recovery (TDR) event occurred.<br>**Note:** If this error code is returned, the driver's calling function (typically the [pfnReclaimResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_2_ddi_base_functions) routine) must return this error code to the Direct3D runtime. |

## See also

[D3DDDICB_RECLAIMALLOCATIONS3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reclaimallocations3cb)

[D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)

[pfnReclaimResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_2_ddi_base_functions)
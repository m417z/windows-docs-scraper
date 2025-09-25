# PFND3D11DDI_SETUNORDEREDACCESSVIEWS callback function

## Description

The *CsSetUnorderedAccessViews* function sets unordered access view (UAV) objects for a compute shader.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `StartSlot`

The offset to the first view to set.

### `NumViews` [in]

The total number of views to set.

### `unnamedParam4`

*pUAVInitialCounts* [in]

An array of append and consume buffer offsets. A value of -1 indicates that the current offset should be kept. Any other values set the hidden counter for that appendable and consumable UAV. *pUAVInitialCounts* is only relevant for UAVs of the *phUnorderedAccessView* array that were created with either **D3D11_DDI_BUFFER_UAV_FLAG_APPEND** or **D3D11_DDI_BUFFER_UAV_FLAG_COUNTER** specified in the **Flags** member of the [D3D11DDIARG_BUFFER_UNORDEREDACCESSVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_buffer_unorderedaccessview) structure when the UAV was created; otherwise, the argument is ignored.

### `unnamedParam5`

*phUnorderedAccessView* [in]

An array of handles to the driver's private data for unordered access view objects to set. Note that some handle values can be **NULL**.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Microsoft Direct3D runtime determines that the error is critical. Even if the device is removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED; however, if device removal interferes with the operation of *CsSetUnorderedAccessViews* (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

## See also

[D3D11DDIARG_BUFFER_UNORDEREDACCESSVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_buffer_unorderedaccessview)

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)
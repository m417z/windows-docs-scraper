# PFND3D11DDI_CREATEUNORDEREDACCESSVIEW callback function

## Description

The **CreateUnorderedAccessView** function creates an unordered access view.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pCreateUnorderedAccessView* [in]

A pointer to a [D3D11DDIARG_CREATEUNORDEREDACCESSVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createunorderedaccessview) structure that describes the parameters that the user-mode display driver uses to create an unordered access view.

### `unnamedParam3`

*hUnorderedAccessView* [in]

A handle to the driver's private data for the hull shader.

### `unnamedParam4`

*hRTUnorderedAccessView* [in]

A handle to the unordered access view that the driver should use when it calls back into the Direct3D runtime.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The driver might run out of memory. Therefore, the driver can pass E_OUTOFMEMORY or D3DDDIERR_DEVICEREMOVED in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function. The Direct3D runtime determines that any other errors are critical. If the driver passes any errors, which includes D3DDDIERR_DEVICEREMOVED, the Direct3D runtime determines that the handle is invalid; therefore, the runtime does not call the [DestroyUnorderedAccessView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_destroyunorderedaccessview) function to destroy the handle that the *hUnorderedAccessView* parameter specifies.

## See also

[CalcPrivateUnorderedAccessViewSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_calcprivateunorderedaccessviewsize)

[D3D11DDIARG_CREATEUNORDEREDACCESSVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createunorderedaccessview)

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[DestroyUnorderedAccessView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_destroyunorderedaccessview)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)
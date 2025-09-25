## Description

**CreateUnorderedAccessView(WDDM 2.0)** creates an unordered access view.

## Parameters

### `unnamedParam1`

[in] **hDevice** is a handle to the display device (graphics context).

### `unnamedParam2`

[in] **pCreateUnorderedAccessView** is a pointer to a [**D3DWDDM2_0DDIARG_CREATEUNORDEREDACCESSVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddiarg_createunorderedaccessview) structure that describes the parameters that the user-mode display driver uses to create an unordered access view.

### `unnamedParam3`

[in] **hUnorderedAccessView** is a handle to the driver's private data for the unordered access view.

### `unnamedParam4`

[in] **hRTUnorderedAccessView** is a handle to the unordered access view that the driver should use when it calls back into the Direct3D runtime.

## Remarks

The driver might run out of memory. Therefore, the driver can pass E_OUTOFMEMORY or D3DDDIERR_DEVICEREMOVED in a call to the [**pfnSetErrorCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function. The Direct3D runtime determines that any other errors are critical. If the driver passes any errors, which includes D3DDDIERR_DEVICEREMOVED, the Direct3D runtime determines that the handle is invalid; therefore, the runtime does not call the [**DestroyUnorderedAccessView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_destroyunorderedaccessview) function to destroy the handle that the **hUnorderedAccessView** parameter specifies.

## See also

[**CalcPrivateUnorderedAccessViewSize (WDDM 2.0)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_calcprivateunorderedaccessviewsize)

[**D3DWDDM2_0DDIARG_CREATEUNORDEREDACCESSVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddiarg_createunorderedaccessview)

[**DestroyUnorderedAccessView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_destroyunorderedaccessview)

[**D3D11DDI_DEVICEFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[**pfnSetErrorCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)
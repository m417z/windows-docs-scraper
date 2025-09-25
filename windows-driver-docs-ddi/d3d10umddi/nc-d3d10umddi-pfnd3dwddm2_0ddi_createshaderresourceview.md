## Description

**CreateShaderResourceView(WDDM 2.0)** creates a shader resource view.

## Parameters

### `unnamedParam1`

[in] **hDevice** is a handle to the display device (graphics context).

### `unnamedParam2`

[in] **pCreateShaderResourceView** is a pointer to a [**D3DWDDM2_0DDIARG_CREATESHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddiarg_createshaderresourceview) structure that describes the parameters that the user-mode display driver uses to create a shader resource view.

### `unnamedParam3`

[in] **hShaderResourceView** is a handle to the driver's private data for the shader resource view.

### `unnamedParam4`

[in] **hRTShaderResourceView** is a handle to the shader resource view that the driver should use when it calls back into the Direct3D runtime.

## Remarks

The driver might run out of memory. Therefore, the driver can pass E_OUTOFMEMORY or D3DDDIERR_DEVICEREMOVED in a call to the [**pfnSetErrorCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function. The Direct3D runtime determines that any other errors are critical. If the driver passes any errors, which includes D3DDDIERR_DEVICEREMOVED, the Direct3D runtime determines that the handle is invalid; therefore, the runtime does not call the [**DestroyShaderResourceView**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyshaderresourceview) function to destroy the handle that the **hShaderResourceView** parameter specifies.

## See also

[**CalcPrivateShaderResourceViewSize(WDDM 2.0)**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_calcprivateshaderresourceviewsize)

[**D3DWDDM2_0DDIARG_CREATESHADERRESOURCEVIEW**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm2_0ddiarg_createshaderresourceview)
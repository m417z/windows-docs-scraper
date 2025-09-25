# PFND3D11_1DDI_ASSIGNDEBUGBINARY callback function

## Description

Provides the full shader binary that is available after shader creation. The full shader binary lets a driver retrieve debugging information or other shader binary information that would not normally be available to the driver.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hShader* [in]

A handle to the driver's private data for the shader object.

### `uBinarySize`

The size, in bytes, of the full shader binary.

### `pBinary` [in]

A pointer to the full shader binary.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

*AssignDebugBinary* is called only if all of the following are true:

* The device can be debugged.
* The user-mode display driver has set the [D3D11_1DDI_D3D11_OPTIONS_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_d3d11_options_data).**AssignDebugBinarySupport** flag to **TRUE**.
* A shader creation function *CreateXxxShaderXxx* has been called, has succeeded, and has returned a handle to the shader.

The driver should not encounter any error, except for **D3DDDIERR_DEVICEREMOVED**. Therefore, if the driver passes any error, except for **D3DDDIERR_DEVICEREMOVED**, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Microsoft Direct3D runtime will determine that the error is critical. Even if the device was removed, the driver is not required to return **D3DDDIERR_DEVICEREMOVED**; however, if device removal interfered with the operation of *AssignDebugBinary* (which typically should not happen), the driver can return **D3DDDIERR_DEVICEREMOVED**.

## See also

[D3D11_1DDI_D3D11_OPTIONS_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddi_d3d11_options_data)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)
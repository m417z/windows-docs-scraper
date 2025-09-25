# PFND3D11DDI_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT callback function

## Description

The **CreateGeometryShaderWithStreamOutput(D3D11)** function creates a geometry shader with stream output.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pCreateGeometryWithShaderOutput* [in]

A pointer to a [D3D11DDIARG_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_creategeometryshaderwithstreamoutput) structure that describes the parameters that the user-mode display driver uses to create a geometry shader with stream output.

### `unnamedParam3`

*hShader* [in]

A handle to the driver's private data for the geometry shader with stream output. The driver returns the size, in bytes, of the memory region that the Microsoft Direct3D runtime must allocate for the private data from a call to the driver's [CalcPrivateGeometryShaderWithStreamOutput(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_calcprivategeometryshaderwithstreamoutput) function. The handle is just a pointer to a region of memory, the size of which the driver requested. The driver uses this region of memory to store internal data structures that are related to its shader object.

### `unnamedParam4`

*hRTShader* [in]

A handle to the geometry shader with stream output that the driver should use when it calls back into the Direct3D runtime.

### `unnamedParam5`

*pSignatures* [in]

A pointer to a [D3D10DDIARG_STAGE_IO_SIGNATURES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_stage_io_signatures) structure that forms the shader's signature.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The driver can pass E_OUTOFMEMORY (if the driver runs out of memory) or D3DDDIERR_DEVICEREMOVED (if the device is removed) in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function. The Direct3D runtime determines that any other errors are critical. If the driver passes any errors, which includes D3DDDIERR_DEVICEREMOVED, the Direct3D runtime determines that the handle is invalid; therefore, the runtime does not call the [DestroyShader](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyshader) function to destroy the handle that the *hShader* parameter specifies.

## See also

[CalcPrivateGeometryShaderWithStreamOutput(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_calcprivategeometryshaderwithstreamoutput)

[D3D10DDIARG_STAGE_IO_SIGNATURES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_stage_io_signatures)

[D3D11DDIARG_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_creategeometryshaderwithstreamoutput)

[D3D11DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddi_devicefuncs)

[DestroyShader](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_destroyshader)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)
# PFND3D11_1DDI_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT callback function

## Description

Creates a geometry shader with stream output.

## Parameters

### `unnamedParam1`

*hDevice*

A handle to the display device (graphics context).

### `unnamedParam2`

*pOutput* [in]

A pointer to a [D3D11DDIARG_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_creategeometryshaderwithstreamoutput) structure that describes the parameters that the user-mode display driver uses to create a geometry shader with stream output.

### `unnamedParam3`

*hShader*

A handle to the driver's private data for the geometry shader with stream output. The driver returns the size, in bytes, of the memory region that the Direct3D runtime must allocate for the private data from a call to the driver's [CalcPrivateGeometryShaderWithStreamOutput(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivategeometryshaderwithstreamoutput) function. The handle is just a pointer to a region of memory, the size of which the driver requested. The driver uses this region of memory to store internal data structures that are related to its shader object.

### `unnamedParam4`

*hRTShader*

A handle to the geometry shader with stream output that the driver should use when it calls back into the Direct3D runtime.

### `unnamedParam5`

*pSignatures* [in]

A pointer to a [D3D11_1DDIARG_STAGE_IO_SIGNATURES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_stage_io_signatures) structure that forms the shader's signature.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

## See also

[CalcPrivateGeometryShaderWithStreamOutput(D3D11_1)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_calcprivategeometryshaderwithstreamoutput)

[D3D11DDIARG_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_creategeometryshaderwithstreamoutput)

[D3D11_1DDIARG_STAGE_IO_SIGNATURES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_stage_io_signatures)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)
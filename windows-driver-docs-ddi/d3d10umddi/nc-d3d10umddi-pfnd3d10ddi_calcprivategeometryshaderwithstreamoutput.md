# PFND3D10DDI_CALCPRIVATEGEOMETRYSHADERWITHSTREAMOUTPUT callback function

## Description

The [CalcPrivateGeometryShaderWithStreamOutput](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_calcprivategeometryshaderwithstreamoutput) function determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for a geometry shader with stream output.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pCreateGeometryShaderWithStreamOutput* [in]

A pointer to a [D3D10DDIARG_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_creategeometryshaderwithstreamoutput) structure that describes the parameters that the user-mode display driver uses to calculate the size of the memory region.

### `unnamedParam3`

*pSignatures* [in]

A pointer to a [D3D10DDIARG_STAGE_IO_SIGNATURES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_stage_io_signatures) structure that makes up the shader's signature.

## Return value

[CalcPrivateGeometryShaderWithStreamOutput](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_calcprivategeometryshaderwithstreamoutput) returns the size of the memory region that the driver requires for creating a geometry shader with stream output.

## See also

[D3D10DDIARG_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_creategeometryshaderwithstreamoutput)

[D3D10DDIARG_STAGE_IO_SIGNATURES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_stage_io_signatures)

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)
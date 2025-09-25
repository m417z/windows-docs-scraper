# D3D11DDIARG_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT structure

## Description

The D3D11DDIARG_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT structure describes the geometry shader with stream output to create.

## Members

### `pShaderCode` [in]

An array of CONST UINT tokens that make up the geometry shader code.

### `pOutputStreamDecl` [in]

An array of [D3D11DDIARG_STREAM_OUTPUT_DECLARATION_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_stream_output_declaration_entry) structures that describes the stream output for the geometry shader.

### `NumEntries` [in]

The number of elements in that array that the **pOutputStreamDecl** member specifies.

### `BufferStridesInBytes` [in]

An array of strides (bytes from one vertex to the next vertex).

### `NumStrides` [in]

The number of strides in the array that the **BufferStridesInBytes** member specifies.

### `RasterizedStream` [in]

A value that identifies the rasterized stream.

## See also

[CalcPrivateGeometryShaderWithStreamOutput](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivategeometryshaderwithstreamoutput)

[CreateGeometryShaderWithStreamOutput](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_creategeometryshaderwithstreamoutput)

[D3D11DDIARG_STREAM_OUTPUT_DECLARATION_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_stream_output_declaration_entry)
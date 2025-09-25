# _D3DHAL_DP2CREATEVERTEXSHADER structure

## Description

 DirectX 8.0 and later versions only.

The D3DHAL_DP2CRE[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)ATEVERTEXSHADER structure is used to create a vertex shader when a D3DDP2OP_CREATEVERTEXSHADER opcode is received by .

## Members

### `dwHandle`

Specifies the handle to the vertex shader that is assigned by the runtime. This value is guaranteed to be subzero. Furthermore, although flexible vertex format (FVF) codes are part of the shader handle namespace, it is guaranteed that the handle passed will not be an FVF code.

### `dwDeclSize`

Specifies the shader declaration size in bytes.

### `dwCodeSize`

Specifies the shader code size in bytes.

## Remarks

Before invoking the driver, the runtime performs validation to ensure that the specified shader is legal for the specified shader language version. The runtime flushes all pending state and rendering when this token is to be sent to the driver. Thus, processing of this token is assumed to be synchronous with the runtime and the driver reports failure of the creation request by failing the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) DDI call. Thus, the driver should validate the given shader declaration and code on receipt of this token and report success or failure accordingly.

See [Direct3D Driver Shader Codes](https://learn.microsoft.com/windows-hardware/drivers/ddi/) for information about the format of an individual shader code and the tokens that comprise each shader code.

## See also

D3DDP2OP_CREATEVERTEXSHADER

[D3DHAL_DP2VERTEXSHADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2vertexshader)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)
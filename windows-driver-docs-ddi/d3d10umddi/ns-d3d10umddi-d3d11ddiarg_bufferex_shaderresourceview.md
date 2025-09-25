# D3D11DDIARG_BUFFEREX_SHADERRESOURCEVIEW structure

## Description

The D3D11DDIARG_BUFFEREX_SHADERRESOURCEVIEW structure describes a buffer that is used to create a shader resource view in a call to the [CreateShaderResourceView(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createshaderresourceview) function.

## Members

### `FirstElement` [in]

The offset, in bytes, to the first element in the buffer.

### `ElementOffset` [in]

The offset, in bytes, to the first element in the buffer.

### `NumElements` [in]

The number of elements in the buffer.

### `ElementWidth` [in]

The width, in elements, in the buffer.

### `Flags` [in]

A valid bitwise OR of flag values that describe the buffer. Currently, the Direct3D runtime supports only the D3D11_DDI_BUFFEREX_SRV_FLAG_RAW (0x00000001) flag. If this flag is set, the buffer is in raw format.

## See also

[CalcPrivateShaderResourceViewSize(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_calcprivateshaderresourceviewsize)

[CreateShaderResourceView(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createshaderresourceview)

[D3D11DDIARG_CREATESHADERRESOURCEVIEW](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11ddiarg_createshaderresourceview)
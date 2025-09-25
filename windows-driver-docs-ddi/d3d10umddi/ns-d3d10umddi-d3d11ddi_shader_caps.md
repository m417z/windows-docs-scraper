# D3D11DDI_SHADER_CAPS structure

## Description

The D3D11DDI_SHADER_CAPS structure contains display device shader capabilities.

## Members

### `Caps` [in]

A valid bitwise **OR** of values that describe the shader capabilities of the display device. The Direct3D runtime supports the following values.

#### D3D11DDICAPS_SHADER_DOUBLES (0x1)

The display device supports shaders that can internally operate on double-precision floating-point numbers. However, these shaders can neither input nor output double values, and they cannot perform atomic operations on double values. Only operations that are internal to such a shader can use double values. The shader must form double values by combining input values at the start of the shader. The shader must break apart double values into multiple output values at the end of the shader.

#### D3D11DDICAPS_SHADER_COMPUTE_PLUS_RAW_AND_STRUCTURED_BUFFERS_IN_SHADER_4_X (0x2)

The display device supports compute shaders as well as raw and structured buffers. The runtime can successfully call the driver's [CreateComputeShader](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createcomputeshader) function to create a compute shader and the driver's [CreateShaderResourceView(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createshaderresourceview) and [CreateUnorderedAccessView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createunorderedaccessview) functions to create raw and structured buffers.

Drivers that run the [Direct3D version 11 pipeline](https://learn.microsoft.com/windows-hardware/drivers/display/pipelines-for-direct3d-version-11) (the D3D11DDI_3DPIPELINELEVEL_11_0 value of the [D3D11DDI_3DPIPELINELEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11ddi_3dpipelinelevel) enumeration) and greater must report this shader capability.

## See also

[CreateComputeShader](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createcomputeshader)

[CreateShaderResourceView(D3D11)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createshaderresourceview)

[CreateUnorderedAccessView](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11ddi_createunorderedaccessview)

[D3D10_2DDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_2ddicaps_type)

[GetCaps(D3D10_2)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10_2ddi_getcaps)
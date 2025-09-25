## Description

The **D3D12DDI_WAVE_MMA_ACCUM_DATATYPE** enumeration is a bitwise-OR of the data types supported for the accumulator in a matrix-multiply-accumulate (MMA) operation.

## Constants

### `D3D12DDI_WAVE_MMA_ACCUM_DATATYPE_NONE:0`

The accumulator data type is not specified.

### `D3D12DDI_WAVE_MMA_ACCUM_DATATYPE_INT32:0x1`

The driver supports 32-bit integer data.

### `D3D12DDI_WAVE_MMA_ACCUM_DATATYPE_FLOAT16:0x2`

The driver supports 16-bit floating-point data.

### `D3D12DDI_WAVE_MMA_ACCUM_DATATYPE_FLOAT:0x4`

The driver supports 32-bit floating-point data.

## Remarks

For more information, see [Wave MMA](https://microsoft.github.io/DirectX-Specs/d3d/HLSL_SM_6_x_WaveMatrix.html).

## See also

[**D3D12DDI_WAVE_MMA_DATA_0103**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_wave_mma_data_0103)
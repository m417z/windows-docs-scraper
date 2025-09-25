## Description

The **D3D12DDI_WAVE_MMA_DATA_0103** structure describes a driver's support for Direct3D matrix-multiply-accumulate (MMA) operations.

## Members

### `InputDataType`

[in] A [**D3D12DDI_WAVE_MMA_INPUT_DATATYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_wave_mma_input_datatype) enumeration that specifies the type of the input data.

### `M`

[in] A [**D3D12DDI_WAVE_MMA_DIMENSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_wave_mma_dimension) enumeration that specifies the dimension of the matrix operation that corresponds to the number of rows in the left matrix.

### `N`

[in] A [**D3D12DDI_WAVE_MMA_DIMENSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_wave_mma_dimension) enumeration that specifies the dimension of the matrix operation that corresponds to the number of columns in the right matrix.

### `Supported`

[out] Set to TRUE if the hardware supports the specified matrix dimensions and data type; otherwise FALSE.

### `K`

[out] Specifies the shared dimension size supported by the device for the given combination of **M** and ((N)). This value must be an even multiple of 16.

### `AccumDataTypes`

[out] The [**D3D12DDI_WAVE_MMA_ACCUM_DATATYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_wave_mma_accum_datatype) enumeration that specifies the supported accumulation data types.

### `RequiredWaveLaneCountMin`

[out] The minimum number of wave lanes required to support the wave MMA intrinsics.

### `RequiredWaveLaneCountMax`

[out] The maximum number of wave lanes that can be used to support the wave MMA intrinsics.

## Remarks

The matrix multiplication unit is defined by three dimensions **M**, **N**, and **K**. The matrix multiplication unit thus is defined to be a multiplication of two matrices of dimensions **MxK** (left matrix) and **KxN** (right matrix) with a resulting matrix of size **MxN**.

A hardware implementation can support only one **K** value for each combination of **M**, **N**, and **InputDataType**. The possible dimensions of **M** and **N** are restricted to the allowed enum values defined by [**D3D12DDI_WAVE_MMA_DIMENSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_wave_mma_dimension) **M** and **D3D12DDI_WAVE_MMA_DIMENSION** **N**. The K dimension is defined to be an even multiple of 16 provided by the driver through the D3D12_FEATURE_DATA_WAVE_MMA CheckFeatureSupport Caps. The **K** value is considered a constant and the driver should unroll loops using it, if possible.

For more information, see [Wave MMA](https://microsoft.github.io/DirectX-Specs/d3d/HLSL_SM_6_x_WaveMatrix.html).

## See also

[**D3D12DDI_WAVE_MMA_ACCUM_DATATYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_wave_mma_accum_datatype)

[**D3D12DDI_WAVE_MMA_DIMENSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_wave_mma_dimension)

[**D3D12DDI_WAVE_MMA_INPUT_DATATYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_wave_mma_input_datatype)
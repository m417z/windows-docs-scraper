# D3D12DDI_3DPIPELINELEVEL enumeration

## Description

The **D3D12DDI_3DPIPELINELEVEL** enumeration contains values that identify the pipeline level that the driver supports.

## Constants

### `D3D12DDI_3DPIPELINELEVEL_1_0_GENERIC:1`

The driver supports the baseline Direct3D version 1.0 pipeline.

### `D3D12DDI_3DPIPELINELEVEL_1_0_CORE:2`

Internal.

### `D3D12DDI_3DPIPELINELEVEL_11_0:10`

The driver supports Direct3D version 11 pipeline.

### `D3D12DDI_3DPIPELINELEVEL_11_1:11`

The driver supports Direct3D version 11.1 pipeline.

### `D3D12DDI_3DPIPELINELEVEL_12_0:12`

The driver supports Direct3D version 12.0 pipeline.

### `D3D12DDI_3DPIPELINELEVEL_12_1:13`

The driver supports Direct3D version 12.1 pipeline.

### `D3D12DDI_3DPIPELINELEVEL_12_2:14`

The driver supports Direct3D version 12.2 pipeline.

## Remarks

Drivers only report the maximum level they support.

## See also

[**D3D12DDI_3DPIPELINESUPPORT1_DATA_0081**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_3dpipelinesupport1_data_0081)

[**D3D12DDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[**PFND3DDDI_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)
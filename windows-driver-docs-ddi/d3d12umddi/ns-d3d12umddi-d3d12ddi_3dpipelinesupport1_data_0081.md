## Description

**D3D12DDI_3DPIPELINESUPPORT1_DATA_0081** is used to indicate the highest feature level of 3D pipeline support in the Direct3D runtime and the driver.

## Members

### `HighestRuntimeSupportedFeatureLevel` [in]

A [**D3D12DDI_3DPIPELINELEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_3dpipelinelevel) value that indicates the runtime's highest supported 3D pipeline feature level.

### `MaximumDriverSupportedFeatureLevel` [out]

A [**D3D12DDI_3DPIPELINELEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_3dpipelinelevel) value that indicates the driver's maximum supported 3D pipeline feature level. **MaximumDriverSupportedFeatureLevel** must be less than or equal to **HighestRuntimeSupportedFeatureLevel**.

## Remarks

**D3D12DDI_3DPIPELINESUPPORT1_DATA_0081** is the structure passed to [**PFND3DDDI_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) when the cap type is **D3D12DDICAPS_TYPE_0081_3DPIPELINESUPPORT1**.

## See also

[**D3D12DDI_3DPIPELINELEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_3dpipelinelevel)

[**D3D12DDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[**D3DDDICAPS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type)

[**PFND3DDDI_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)
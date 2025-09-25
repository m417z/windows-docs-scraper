# D3DKMT_QUERY_GPUMMU_CAPS structure

## Description

The **D3DKMT_QUERY_GPUMMU_CAPS** structure describes the capabilities of the GPU MMU (memory management unit).

## Members

### `PhysicalAdapterIndex`

[in] The physical adapter index in the LDA (linked display adapter) chain.

### `Caps`

[out] A [**D3DKMT_GPUMMU_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_gpummu_caps) structure that describes the capabilities of the GPU MMU.

## See also

[**D3DKMTQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo)
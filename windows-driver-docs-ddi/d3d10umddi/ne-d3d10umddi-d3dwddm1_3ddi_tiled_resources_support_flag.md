# D3DWDDM1_3DDI_TILED_RESOURCES_SUPPORT_FLAG enumeration

## Description

Indicates the level of support by the hardware and user-mode display driver for tiled resources.

## Constants

### `D3DWDDM1_3DDI_TILED_RESOURCES_TIER_1_SUPPORTED`

Tiled resources are supported to a minimal level.

### `D3DWDDM1_3DDI_TILED_RESOURCES_TIER_2_SUPPORTED`

Tiled resources are supported to a greater extent than for **D3DWDDM1_3DDI_TILED_RESOURCES_TIER_1_SUPPORTED**.

If this flag is set, the Direct3D runtime assumes that the support level of the **D3DWDDM1_3DDI_TILED_RESOURCES_TIER_1_SUPPORTED** flag also applies.

### `D3DWDDM2_0DDI_TILED_RESOURCES_TIER_3_SUPPORTED`

## See also

[D3DWDDM1_3DDI_D3D11_OPTIONS_DATA1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3dwddm1_3ddi_d3d11_options_data1)
# D3D12DDI_VARIABLE_SHADING_RATE_TIER enumeration

## Description

A **D3D12DDI_VARIABLE_SHADING_RATE_TIER** value indicates the tier that the hardware supports for variable rate shading.

## Constants

### `D3D12DDI_VARIABLE_SHADING_RATE_TIER_NOT_SUPPORTED:0`

Variable rate shading is not supported.

### `D3D12DDI_VARIABLE_SHADING_RATE_TIER_1:1`

Variable rate shading is supported at tier 1.

### `D3D12DDI_VARIABLE_SHADING_RATE_TIER_2:2`

Variable rate shading is supported at tier 2.

## Remarks

*Variable rate shading* is a mechanism to enable allocation of rendering performance and power at varying rates across the rendered image.

The following capabilities are defined for each tier.

* Tier 1 support

  * The shading rate can only be specified on a per-draw-basis; nothing more granular than that.
  * The shading rate applies uniformly to what is drawn independently of where it lies within the render target.

* Tier 2 support

  * The shading rate can be specified on a per-draw-basis, as in Tier 1. It can also be specified by a combination of per-draw-basis, and of semantic from the per-provoking-vertex and a screen space image.
  * Shading rates from the three sources are combined using a set of combiners.
  * Screen space image tile size is 16x16 or smaller.
  * Shading rate requested by the app is guaranteed to be delivered exactly (for precision of temporal and other reconstruction filters).
  * SV_ShadingRate PS input is supported, where SV_ShadingRate provides more info about the shading rate.
  * The per-provoking vertex rate, also referred to as per-primitive rate, is only valid when one viewport is used and SV_ViewportIndex is not written to.

## See also

[**D3D12DDI_D3D12_OPTIONS_DATA_0089**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_d3d12_options_data_0089)
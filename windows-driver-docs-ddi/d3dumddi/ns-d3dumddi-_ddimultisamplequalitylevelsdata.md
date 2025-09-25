# _DDIMULTISAMPLEQUALITYLEVELSDATA structure

## Description

The DDIMULTISAMPLEQUALITYLEVELSDATA structure describes the number of multiple-sample quality levels for a given render-target format.

## Members

### `Format` [in]

A [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)-typed value that indicates the surface format of the multiple-sampled render target.

### `Flip` [in]

A Boolean value that specifies whether the resolution is flip or bit-block transfer (blt) style. **TRUE** indicates flip-style resolution; **FALSE** indicates blt-style resolution.

### `MsType` [in]

A [D3DDDIMULTISAMPLE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddimultisample_type)-typed value that indicates the level of full-scene multiple sampling. If the display device supports maskable multiple sampling (that is, more than one sample for a multiple-sample render-target format plus antialias support), the user-mode display driver must provide the number of quality levels for the D3DDDIMULTISAMPLE_NONMASKABLE (1) value.

### `QualityLevels` [in]

The number of multiple-sample quality levels that the user-mode display driver supports for the render-target format that is specified by the **Format**, **bFlip**, and **MSType** members.

## See also

[D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[D3DDDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddicaps_type)

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[D3DDDIMULTISAMPLE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddimultisample_type)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)
# _D3DDDIARG_GENERATEMIPSUBLEVELS structure

## Description

The D3DDDIARG_GENERATEMIPSUBLEVELS structure describes how to generate the sublevels of a MIP-map texture.

## Members

### `hResource` [in]

A handle to the MIP-map texture surface.

### `Filter` [in]

A D3DDDITEXTUREFILTERTYPE-typed value that indicates the texture magnification or minification filter type that is used in generating the sublevels of the MIP-map texture. This member can be one of the following values.

| **Value** | **Meaning** |
|:--|:--|
| D3DDDITEXF_NONE | MIP-map filtering is disabled. |
| D3DDDITEXF_POINT | Point filtering. The texel with coordinates that are nearest to the required pixel value is used. The texture filter to be used between MIP-map levels is nearest-point MIP-map filtering. |
| D3DDDITEXF_LINEAR | Bilinear-interpolation filtering. A weighted average of a 2x2 area of texels that surround the required pixel is used. The texture filter to use between MIP-map levels is trilinear MIP-map interpolation. |
| D3DDDITEXF_ANISOTROPIC | Anisotropic texture filtering. This filtering compensates for distortion that is caused by the difference in angle between the texture polygon and the plane of the screen. |
| D3DDDITEXF_PYRAMIDALQUAD | Four-sample tent filtering. |

## See also

[GenerateMipSubLevels](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_generatemipsublevels)
# IDirect3DBaseTexture9::GetAutoGenFilterType

## Description

Get the filter type that is used for automatically generated mipmap sublevels.

## Return value

Type: **[D3DTEXTUREFILTERTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dtexturefiltertype)**

Filter type. See [D3DTEXTUREFILTERTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dtexturefiltertype). A texture must be created with [D3DUSAGE_AUTOGENMIPMAP](https://learn.microsoft.com/windows/desktop/direct3d9/d3dusage) to use this method. Any other usage value will cause this method to return D3DTEXF_NONE.

## Remarks

Changing the filter type "dirties" the mipmap sublevels and causes them to be regenerated.

The (default) filter type set at texture creation time is D3DTEXF_LINEAR. If the driver doesn't support a linear filter, the filter type will be set to D3DTEXF_POINT. All filter types supported by the driver for regular texture filtering are supported for autogeneration except D3DTEXF_NONE. For each resource type, drivers should support all the filter types reported in the corresponding texture, CubeTexture, and volumetexture filter caps. For more information about texture types, see [D3DTEXTUREFILTERTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dtexturefiltertype).

This method has no effect if the texture is not created with [D3DUSAGE_AUTOGENMIPMAP](https://learn.microsoft.com/windows/desktop/direct3d9/d3dusage).

## See also

[GenerateMipSubLevels](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dbasetexture9-generatemipsublevels)

[IDirect3DBaseTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dbasetexture9)

[SetAutoGenFilterType](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dbasetexture9-setautogenfiltertype)
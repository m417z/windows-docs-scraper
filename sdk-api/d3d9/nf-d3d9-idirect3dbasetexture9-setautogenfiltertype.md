# IDirect3DBaseTexture9::SetAutoGenFilterType

## Description

Set the filter type that is used for automatically generated mipmap sublevels.

## Parameters

### `FilterType` [in]

Type: **[D3DTEXTUREFILTERTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dtexturefiltertype)**

Filter type. See [D3DTEXTUREFILTERTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dtexturefiltertype). This method will fail if the filter type is invalid or not supported.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

Changing the filter type "dirties" the mipmap sublevels and causes them to be regenerated.

The (default) filter type set at texture creation time is D3DTEXF_LINEAR. If the driver does not support a linear filter, the filter type will be set to D3DTEXF_POINT. All filter types supported by the driver for regular texture filtering are supported for autogeneration except D3DTEXF_NONE. **SetAutoGenFilterType** will fail unless the driver sets the appropriate D3DPTFILTERCAPS_MINFxxx caps. These values are specified in the TextureFilterCaps and/or CubeTextureFilterCaps members of [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9).
For more information about texture filter types, see [D3DTEXTUREFILTERTYPE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dtexturefiltertype).

This method has no effect if the texture is not created with D3DUSAGE_AUTOGENMIPMAP. In this case, no failure is returned. For more information about usage constants, see [D3DUSAGE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dusage).

## See also

[GenerateMipSubLevels](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dbasetexture9-generatemipsublevels)

[GetAutoGenFilterType](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dbasetexture9-getautogenfiltertype)

[IDirect3DBaseTexture9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dbasetexture9)
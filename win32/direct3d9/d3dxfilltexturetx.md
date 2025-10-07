# D3DXFillTextureTX function

Uses a compiled high-level shader language (HLSL) function to fill each texel of each mipmap level of a texture.

## Parameters

*pTexture* \[in, out\]

Type: **[**LPDIRECT3DTEXTURE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dtexture9)**

Pointer to an [**IDirect3DTexture9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dtexture9) object, representing the texture to be filled.

*pTextureShader* \[in\]

Type: **[**LPD3DXTEXTURESHADER**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxtextureshader)**

Pointer to a [**ID3DXTextureShader**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxtextureshader) texture shader object.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following: D3DERR\_NOTAVAILABLE, D3DERR\_INVALIDCALL.

## Remarks

The texture target must be an HLSL function that takes contains the following semantics:

- One input parameter must use a POSITION semantic.
- One input parameter must use a PSIZE semantic.
- The function must return a parameter that uses the COLOR semantic.

The following is an example of such an HLSL function:

```
float4 TextureGradientFill(
  float2 vTexCoord : POSITION,
  float2 vTexelSize : PSIZE) : COLOR
  {
    float r,g, b, xSq,ySq, a;
    xSq = 2.f*vTexCoord.x-1.f; xSq *= xSq;
    ySq = 2.f*vTexCoord.y-1.f; ySq *= ySq;
    a = sqrt(xSq+ySq);
    if (a > 1.0f) {
        a = 1.0f-(a-1.0f);
    }
    else if (a < 0.2f) {
        a = 0.2f;
    }
    r = 1-vTexCoord.x;
    g = 1-vTexCoord.y;
    b = vTexCoord.x;
    return float4(r, g, b, a);

  };
```

Note that the input parameters can be in any order, but both input semantics must be represented.

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9tex.h |
| Library<br> | D3dx9.lib |

## See also

[Texture Functions in D3DX 9](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-texture)

[**D3DXFillCubeTextureTX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxfillcubetexturetx)

[**D3DXFillVolumeTextureTX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxfillvolumetexturetx)


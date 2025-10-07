# D3DXFillVolumeTexture function

Uses a user-provided function to fill each texel of each mip level of a given volume texture.

## Parameters

*pTexture* \[out\]

Type: **[**LPDIRECT3DVOLUMETEXTURE9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dvolumetexture9)**

Pointer to an [**IDirect3DVolumeTexture9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dvolumetexture9) interface, representing the filled texture.

*pFunction* \[in\]

Type: **[LPD3DXFILL3D](https://learn.microsoft.com/windows/win32/direct3d9/lpd3dxfill3d)**

Pointer to a user-provided evaluator function, which will be used to compute the value of each texel. The function follows the prototype of [LPD3DXFILL3D](https://learn.microsoft.com/windows/win32/direct3d9/lpd3dxfill3d).

*pData* \[in\]

Type: **[**LPVOID**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pointer to an arbitrary block of user-defined data. This pointer will be passed to the function provided in *pFunction*.

## Return value

Type: **[**HRESULT**](https://msdn.microsoft.com/library/Bb401631(v=MSDN.10).aspx)**

If the function succeeds, the return value is D3D\_OK. If the function fails, the return value can be one of the following values: D3DERR\_INVALIDCALL.

## Remarks

If the volume is non-dynamic (because usage is set to 0 when it is created), and located in video memory (the memory pool set to D3DPOOL\_DEFAULT), **D3DXFillVolumeTexture** will fail because the volume cannot be locked.

This example creates a function called ColorVolumeFill, which relies on D3DXFillVolumeTexture.

```
// Define a function that matches the prototype of LPD3DXFILL3D
VOID WINAPI ColorVolumeFill (D3DXVECTOR4* pOut, const D3DXVECTOR3* pTexCoord,
const D3DXVECTOR3* pTexelSize, LPVOID pData)
{
   *pOut = D3DXVECTOR4(pTexCoord->x, pTexCoord->y, pTexCoord->z, 0.0f);
}

// Fill volume texture
if (FAILED (hr = D3DXFillVolumeTexture (m_pTexture, ColorVolumeFill, NULL)))
{
       return hr;
}
```

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Header<br> | D3dx9tex.h |
| Library<br> | D3dx9.lib |

## See also

[Texture Functions in D3DX 9](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-functions-texture)


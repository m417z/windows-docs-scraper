# IDirect3DDevice9::SetVertexShader

## Description

Sets the vertex shader.

## Parameters

### `pShader` [in]

Type: **[IDirect3DVertexShader9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexshader9)***

Vertex shader interface. For more information, see [IDirect3DVertexShader9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dvertexshader9).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

To set a fixed-function vertex shader (after having set a programmable vertex shader), call **IDirect3DDevice9::SetVertexShader**(NULL) to release the programmable shader, and then call [IDirect3DDevice9::SetFVF](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setfvf) with the fixed-function vertex format.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetVertexShader](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getvertexshader)
# IDirect3DDevice9::BeginStateBlock

## Description

Signals Direct3D to begin recording a device-state block.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_INVALIDCALL, E_OUTOFMEMORY.

## Remarks

Applications can ensure that all recorded states are valid by calling the [IDirect3DDevice9::ValidateDevice](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-validatedevice) method prior to calling this method.

The following methods can be recorded in a state block, after calling **IDirect3DDevice9::BeginStateBlock** and before [IDirect3DDevice9::EndStateBlock](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-endstateblock).

* [IDirect3DDevice9::LightEnable](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-lightenable)
* [IDirect3DDevice9::SetClipPlane](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setclipplane)
* [IDirect3DDevice9::SetCurrentTexturePalette](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setcurrenttexturepalette)
* [IDirect3DDevice9::SetFVF](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setfvf)
* [IDirect3DDevice9::SetIndices](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setindices)
* [IDirect3DDevice9::SetLight](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setlight)
* [IDirect3DDevice9::SetMaterial](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setmaterial)
* [IDirect3DDevice9::SetNPatchMode](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setnpatchmode)
* [IDirect3DDevice9::SetPixelShader](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setpixelshader)
* [IDirect3DDevice9::SetPixelShaderConstantB](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setpixelshaderconstantb)
* [IDirect3DDevice9::SetPixelShaderConstantF](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setpixelshaderconstantf)
* [IDirect3DDevice9::SetPixelShaderConstantI](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setpixelshaderconstanti)
* [IDirect3DDevice9::SetRenderState](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setrenderstate)
* [IDirect3DDevice9::SetSamplerState](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setsamplerstate)
* [IDirect3DDevice9::SetScissorRect](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setscissorrect)
* [IDirect3DDevice9::SetStreamSource](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setstreamsource)
* [IDirect3DDevice9::SetStreamSourceFreq](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setstreamsourcefreq)
* [IDirect3DDevice9::SetTexture](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-settexture)
* [IDirect3DDevice9::SetTextureStageState](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-settexturestagestate)
* [IDirect3DDevice9::SetTransform](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-settransform)
* [IDirect3DDevice9::SetViewport](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setviewport)
* [IDirect3DDevice9::SetVertexDeclaration](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setvertexdeclaration)
* [IDirect3DDevice9::SetVertexShader](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setvertexshader)
* [IDirect3DDevice9::SetVertexShaderConstantB](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setvertexshaderconstantb)
* [IDirect3DDevice9::SetVertexShaderConstantF](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setvertexshaderconstantf)
* [IDirect3DDevice9::SetVertexShaderConstantI](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setvertexshaderconstanti)

The ordering of state changes in a state block is not guaranteed. If the same state is specified multiple times in a state block, only the last value is used.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::CreateStateBlock](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-createstateblock)

[IDirect3DDevice9::EndStateBlock](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-endstateblock)
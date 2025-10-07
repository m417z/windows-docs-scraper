# D3DX11\_PASS\_SHADER\_DESC structure

Describes an effect pass.

## Members

**pShaderVariable**

Type: **[**ID3DX11EffectShaderVariable**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11effectshadervariable)\***

The variable that this shader came from.

**ShaderIndex**

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The element of pShaderVariable (if an array) or 0 if not applicable.

## Remarks

D3DX11\_PASS\_SHADER\_DESC is used with [**ID3DX11EffectPass**](https://learn.microsoft.com/windows/win32/direct3d11/id3dx11effectpass) Get\*ShaderDesc methods.

If this is an inline shader assignment, the returned interface will be an anonymous shader variable, which is not retrievable any other way. It's name in the variable description will be "$Anonymous". If there is no assignment of this type in the pass block, pShaderVariable != **NULL**, but pShaderVariable->IsValid() == **FALSE**.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------------|
| Header<br> | D3dx11effect.h |

## See also

[Effects 11 Structures](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-effects11-structures)


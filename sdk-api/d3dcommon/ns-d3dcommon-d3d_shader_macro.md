# D3D_SHADER_MACRO structure

## Description

Defines a shader macro.

## Members

### `Name`

The macro name.

### `Definition`

The macro definition.

## Remarks

You can use shader macros in your shaders. The **D3D_SHADER_MACRO** structure defines a single shader macro as shown in the following example:

```

D3D_SHADER_MACRO Shader_Macros[] = { "zero", "0", NULL, NULL };

```

The following shader or effect creation functions take an array of shader macros as an input parameter:

* [D3D10CompileShader](https://learn.microsoft.com/windows/desktop/api/d3d10shader/nf-d3d10shader-d3d10compileshader)
* [D3DX10CreateEffectFromFile](https://learn.microsoft.com/windows/desktop/direct3d10/d3dx10createeffectfromfile)
* [D3DX10PreprocessShaderFromFile](https://learn.microsoft.com/windows/desktop/direct3d10/d3dx10preprocessshaderfromfile)
* [D3DX11CreateAsyncShaderPreprocessProcessor](https://learn.microsoft.com/windows/desktop/direct3d11/d3dx11createasyncshaderpreprocessprocessor)

## See also

[Common Version Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-common-structures)
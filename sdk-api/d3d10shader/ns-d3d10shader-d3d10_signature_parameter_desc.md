# D3D10_SIGNATURE_PARAMETER_DESC structure

## Description

Describes a shader signature.

## Members

### `SemanticName`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A per-parameter string that identifies how the data will be used. See [Semantics (DirectX HLSL)](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-semantics).

### `SemanticIndex`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Semantic index that modifies the semantic. Used to differentiate different parameters that use the same semantic.

### `Register`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The register that will contain this variable's data.

### `SystemValueType`

Type: **[D3D10_NAME](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_name)**

A predefined string that determines the functionality of certain pipeline stages. See [D3D10_NAME](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_name).

### `ComponentType`

Type: **[D3D10_REGISTER_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_register_component_type)**

The per-component-data type that is stored in a register. See [D3D10_REGISTER_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_register_component_type). Each register can store up to four-components of data.

### `Mask`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Mask which indicates which components of a register are used.

### `ReadWriteMask`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Mask which indicates whether a given component is never written (if the signature is an output signature) or always read (if the signature is an input signature). The mask is a combination of [D3D10_REGISTER_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_register_component_type) values.

## Remarks

A shader can take n inputs and can produce m outputs. The order of the input (or output) parameters, their associated types, and any attached semantics make up the shader signature. Each shader has an input and an output signature.

When compiling a shader or an effect, some API calls validate shader signatures (such as [D3D10CompileShader](https://learn.microsoft.com/windows/desktop/api/d3d10shader/nf-d3d10shader-d3d10compileshader) and [D3D10CompileEffectFromMemory](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-d3d10compileeffectfrommemory)). That is, they compare the output signature of one shader (like a vertex shader) with the input signature of another shader (like a pixel shader). This ensures that a shader outputs data that is compatible with a downstream shader that is consuming that data. Compatible means that a shader signature is a exact-match subset of the preceding shader stage. Exact match means parameter types and semantics must exactly match. Subset means that a parameter that is not required by a downstream stage, does not need to include that parameter in its shader signature.

Get a shader-signature from a shader or an effect by calling APIs such as [ID3D10ShaderReflection::GetInputParameterDesc](https://learn.microsoft.com/windows/desktop/api/d3d10shader/nf-d3d10shader-id3d10shaderreflection-getinputparameterdesc) or [ID3D10EffectShaderVariable::GetInputSignatureElementDesc](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effectshadervariable-getinputsignatureelementdesc).

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-structures)
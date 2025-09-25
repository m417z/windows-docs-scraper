# D3D12_SIGNATURE_PARAMETER_DESC structure

## Description

Describes a shader signature.

## Members

### `SemanticName`

A per-parameter string that identifies how the data will be used. For more info, see [Semantics](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-semantics).

### `SemanticIndex`

Semantic index that modifies the semantic. Used to differentiate different parameters that use the same semantic.

### `Register`

The register that will contain this variable's data.

### `SystemValueType`

A [D3D_NAME](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_name)-typed value that identifies a predefined string that determines the functionality of certain pipeline stages.

### `ComponentType`

A [D3D_REGISTER_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_register_component_type)-typed value that identifies the per-component-data type that is stored in a register. Each register can store up to four-components of data.

### `Mask`

Mask which indicates which components of a register are used.

### `ReadWriteMask`

Mask which indicates whether a given component is never written (if the signature is an output signature) or always read (if the signature is an input signature).

### `Stream`

Indicates which stream the geometry shader is using for the signature parameter.

### `MinPrecision`

A [D3D_MIN_PRECISION](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_min_precision)-typed value that indicates the minimum desired interpolation precision. For more info, see [Using HLSL minimum precision](https://learn.microsoft.com/windows/desktop/direct3dhlsl/using-hlsl-minimum-precision).

## Remarks

A shader can take n inputs and can produce m outputs. The order of the input (or output) parameters, their associated types, and any attached semantics make up the shader signature. Each shader has an input and an output signature.

When compiling a shader or an effect, some API calls validate shader signatures That is, they compare the output signature of one shader (like a vertex shader) with the input signature of another shader (like a pixel shader). This ensures that a shader outputs data that is compatible with a downstream shader that is consuming that data. Compatible means that a shader signature is a exact-match subset of the preceding shader stage. Exact match means parameter types and semantics must exactly match. Subset means that a parameter that is not required by a downstream stage, does not need to include that parameter in its shader signature.

Get a shader-signature from a shader or an effect by calling APIs such as [ID3D12ShaderReflection::GetInputParameterDesc](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nf-d3d12shader-id3d12shaderreflection-getinputparameterdesc).

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-shader-structures)
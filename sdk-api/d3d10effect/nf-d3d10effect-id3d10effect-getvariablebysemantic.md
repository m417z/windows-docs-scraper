# ID3D10Effect::GetVariableBySemantic

## Description

Get a variable by semantic.

## Parameters

### `Semantic` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The semantic name.

## Return value

Type: **[ID3D10EffectVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable)***

A pointer to the effect variable indicated by the Semantic. See [ID3D10EffectVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable).

## Remarks

Each effect variable can have a semantic attached, which is a user defined metadata string. Some [system-value semantics](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-semantics) are reserved words that trigger built in functionality by pipeline stages.

The method returns a pointer to an [effect-variable interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable) if a variable is not found; you can call [ID3D10Effect::IsValid](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effect-isvalid) to verify whether or not the semantic exists.

## See also

[ID3D10Effect Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effect)
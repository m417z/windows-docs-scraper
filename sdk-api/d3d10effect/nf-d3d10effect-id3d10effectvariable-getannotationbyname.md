# ID3D10EffectVariable::GetAnnotationByName

## Description

Get an annotation by name.

## Parameters

### `Name` [in]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The annotation name.

## Return value

Type: **[ID3D10EffectVariable](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable)***

A pointer to an [ID3D10EffectVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable). Note that if the annotation is not found the **ID3D10EffectVariable Interface** returned will be empty. The [ID3D10EffectVariable::IsValid](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effectvariable-isvalid) method should be called to determine whether the annotation was found.

## Remarks

Annotations can be attached to a technique, a pass or a global variable. For the syntax, see [Annotation Syntax (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-effect-annotation-syntax).

## See also

[ID3D10EffectVariable Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effectvariable)
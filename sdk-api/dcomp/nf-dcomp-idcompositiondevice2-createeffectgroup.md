# IDCompositionDevice2::CreateEffectGroup

## Description

Creates an object that represents multiple effects to be applied to a visual subtree.

## Parameters

### `effectGroup` [out]

Type: **[IDCompositionEffectGroup](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositioneffectgroup)****

The new effect group object. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

An effect group enables an application to apply multiple effects to a single visual subtree.

A new effect group has a default opacity value of 1.0 and no 3D transformations.

To set the opacity and transform values, use the corresponding methods on the [IDCompositionEffectGroup](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositioneffectgroup) that was created.

## See also

[IDCompositionDevice2](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice2)

[IDCompositionVisual::SetEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisual-seteffect)
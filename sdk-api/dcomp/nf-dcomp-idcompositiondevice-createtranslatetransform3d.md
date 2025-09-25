# IDCompositionDevice::CreateTranslateTransform3D

## Description

Creates a 3D translation transform object.

## Parameters

### `translateTransform3D` [out]

Type: **[IDCompositionTranslateTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontranslatetransform3d)****

The new 3D translation transform object. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A newly created 3D translation transform has a static value of 0 for the OffsetX, OffsetY, and OffsetZ properties.

## See also

[IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice)

[IDCompositionEffectGroup::SetTransform3D](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositioneffectgroup-settransform3d)

[IDCompositionVisual::SetEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisual-seteffect)
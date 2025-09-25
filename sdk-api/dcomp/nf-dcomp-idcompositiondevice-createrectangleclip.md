# IDCompositionDevice::CreateRectangleClip

## Description

Creates a clip object that can be used to restrict the rendering of a visual subtree to a rectangular area.

## Parameters

### `clip` [out]

Type: **[IDCompositionRectangleClip](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionrectangleclip)****

The new clip object. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

A newly created clip object has a value of -2^21 for the left and top properties, and a value of 2^21 for the right and bottom properties, effectively making it a no-op clip object.

## See also

[IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice)

[IDCompositionVisual::SetClip](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-idcompositionvisual-setclip(constd2d_rect_f_))
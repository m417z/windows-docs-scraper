# IDCompositionDevice2::CreateVisual

## Description

Creates a new visual object.

## Parameters

### `visual` [out]

Type: **[IDCompositionVisual2](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual2)****

The new visual object. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

A new visual object has a static value of zero for the OffsetX and OffsetY properties, and NULL for the Transform, Clip, and Content properties. Initially, the visual does not cause the contents of a window to change. The visual must be added as a child of another visual, or as the root of a composition target, before it can affect the appearance of a window.

## See also

[IDCompositionDevice2](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice2)

[IDCompositionTarget::SetRoot](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiontarget-setroot)

[IDCompositionVisual::AddVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisual-addvisual)
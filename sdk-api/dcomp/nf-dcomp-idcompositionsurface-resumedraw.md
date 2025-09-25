# IDCompositionSurface::ResumeDraw

## Description

Resumes drawing on this Microsoft DirectComposition surface object.

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code, which can include [DCOMPOSITION_ERROR_SURFACE_BEING_RENDERED](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) and [DCOMPOSITION_ERROR_SURFACE_NOT_BEING_RENDERED](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes).

## Remarks

 This method allows the surface update to continue unless there are other surfaces that have active, unsuspended draws.

## See also

[IDCompositionSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionsurface)

[IDCompositionSurface::SuspendDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-suspenddraw)
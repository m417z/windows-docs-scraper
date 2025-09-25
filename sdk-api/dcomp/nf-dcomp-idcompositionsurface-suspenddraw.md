# IDCompositionSurface::SuspendDraw

## Description

Suspends the drawing on this Microsoft DirectComposition surface object.

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code, which can include [DCOMPOSITION_ERROR_SURFACE_BEING_RENDERED](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) and [DCOMPOSITION_ERROR_SURFACE_NOT_BEING_RENDERED](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes).

## Remarks

Because only one surface can be open for drawing at a time, calling **SuspendDraw** allows the user to call [IDCompositionSurface::BeginDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-begindraw) on a different surface. Drawing to this surface can be resumed by calling [IDCompositionSurface::ResumeDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-resumedraw).

## See also

[IDCompositionSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionsurface)

[IDCompositionSurface::ResumeDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-resumedraw)
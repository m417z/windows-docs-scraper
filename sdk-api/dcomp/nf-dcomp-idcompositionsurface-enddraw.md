# IDCompositionSurface::EndDraw

## Description

Marks the end of drawing on this Microsoft DirectComposition surface object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code, which can include [DCOMPOSITION_ERROR_SURFACE_NOT_BEING_RENDERED](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes).

## Remarks

This method completes an update that was begun by a previous call to the [IDCompositionSurface::BeginDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-begindraw) method. After this method returns, the application can start another update on the same surface object or on a different one.

If the application calls [IDCompositionDevice2::Commit](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice2-commit) before calling **IDCompositionSurface::EndDraw** for a surface with a pending update, that update is not processed by that Commit call. The update only takes effect on screen after the application calls **IDCompositionSurface::EndDraw** followed by the IDCompositionDevice2::Commit method.

## See also

[IDCompositionSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionsurface)

[IDCompositionSurface::BeginDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-begindraw)

[IDCompositionSurface::EndDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-enddraw)
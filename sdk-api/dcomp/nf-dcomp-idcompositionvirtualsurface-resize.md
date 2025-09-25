# IDCompositionVirtualSurface::Resize

## Description

Changes the logical size of this virtual surface object.

## Parameters

### `width` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The new width of the virtual surface, in pixels. The maximum width is 16,777,216 pixels.

### `height` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The new height of the virtual surface, in pixels. The maximum height is 16,777,216 pixels.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

When a virtual surface is resized, its contents are preserved up to the new boundaries of the surface. If the surface is made smaller, any previously allocated pixels that fall outside of the new width or height are discarded.

This method fails if [IDCompositionSurface::BeginDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-begindraw) was called for this bitmap without a corresponding call to [IDCompositionSurface::EndDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-enddraw).

This method fails if *width* or *height* exceeds 16,777,216 pixels.

## See also

[IDCompositionDevice::CreateVirtualSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-createvirtualsurface)

[IDCompositionVirtualSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvirtualsurface)

[IDCompositionVirtualSurface::Trim](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvirtualsurface-trim)
# IDCompositionVirtualSurface::Trim

## Description

Discards pixels that fall outside of the specified trim rectangles.

## Parameters

### `rectangles` [in, optional]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

An array of rectangles to keep.

### `count` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of rectangles in the *rectangles* array.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

A virtual surface might not have enough storage for every pixel in the surface. An application instructs the composition engine to allocate memory for the surface by calling the [IDCompositionSurface::BeginDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-begindraw) method, and to release memory for the surface by calling the **IDCompositionVirtualSurface::Trim** method. The array of rectangles represents the regions of the virtual surface that should remain allocated after this method returns. Any pixels that are outside the specified set of rectangles are no longer used for texturing, and their memory may be reclaimed.

If the *count* parameter is zero, no pixels are kept, and all of the memory allocated for the virtual surface may be reclaimed. The *rectangles* parameter can be NULL only if the *count* parameter is zero.

This method fails if [IDCompositionSurface::BeginDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-begindraw) was called for this bitmap without a corresponding call to [IDCompositionSurface::EndDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-enddraw).

## See also

[IDCompositionDevice::CreateVirtualSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-createvirtualsurface)

[IDCompositionVirtualSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvirtualsurface)

[IDCompositionVirtualSurface::Resize](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvirtualsurface-resize)
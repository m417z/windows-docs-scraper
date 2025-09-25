# IDCompositionSurfaceFactory::CreateSurface

## Description

Creates a surface object that can be associated with one or more visuals for composition.

## Parameters

### `width` [in]

The width of the surface, in pixels.

### `height` [in]

The height of the surface, in pixels.

### `pixelFormat` [in]

The pixel format of the surface.

### `alphaMode` [in]

The format of the alpha channel, if an alpha channel is included in the pixel format. This can be one of DXGI_ALPHA_MODE_PREMULTIPLIED or DXGI_ALPHA_MODE_IGNORE. It can also be DXGI_ALPHA_MODE_UNSPECIFIED, which is interpreted as DXGI_ALPHA_MODE_IGNORE.

### `surface` [out]

The newly created surface object. This parameter must not be NULL.

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

A Microsoft DirectComposition surface is a rectangular array of pixels that can be associated with a visual for composition.

A newly created surface object is in an uninitialized state. While it is uninitialized, the surface has no effect on the composition of the visual tree. It behaves exactly like a surface that has 100% transparent pixels.

To initialize the surface with pixel data, use the [IDCompositionSurface::BeginDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-begindraw) method. The first call to this method must cover the entire surface area to provide an initial value for every pixel. Subsequent calls may specify smaller sub-rectangles of the surface to update.

This method will fail if either the width or height exceed the max texture size. If your scenario requires dimensions beyond the max texture size, use [CreateVirtualSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurfacefactory-createvirtualsurface) method.

DirectComposition surfaces support the following pixel formats:

* DXGI_FORMAT_B8G8R8A8_UNORM
* DXGI_FORMAT_R8G8B8A8_UNORM
* DXGI_FORMAT_R16G16B16A16_FLOAT

## See also

[IDCompositionDevice2::CreateSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice2-createsurface)

[IDCompositionDevice2::CreateVirtualSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice2-createvirtualsurface)

[IDCompositionSurfaceFactory](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionsurfacefactory)

[IDCompositionSurfaceFactory::CreateVirtualSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurfacefactory-createvirtualsurface)
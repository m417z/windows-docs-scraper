# IDCompositionSurfaceFactory::CreateVirtualSurface

## Description

Creates a sparsely populated surface that can be associated with one or more visuals for composition.

## Parameters

### `initialWidth` [in]

The width of the surface, in pixels. The maximum width is 16,777,216 pixels.

### `initialHeight` [in]

The height of the surface, in pixels.
The maximum height is 16,777,216 pixels.

### `pixelFormat` [in]

The pixel format of the surface.

### `alphaMode` [in]

The format of the alpha channel, if an alpha channel is included in the pixel format. This can be one of DXGI_ALPHA_MODE_PREMULTIPLIED or DXGI_ALPHA_MODE_IGNORE. It can also be DXGI_ALPHA_MODE_UNSPECIFIED, which is interpreted as DXGI_ALPHA_MODE_IGNORE.

### `virtualSurface` [out]

The newly created virtual surface object. This parameter must not be NULL.

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

A newly created virtual surface object is in an uninitialized state. While it is uninitialized, the surface has no effect on the composition of the visual tree. It behaves exactly like a surface that is initialized with 100% transparent pixels.

To initialize the surface with pixel data, use the [IDCompositionSurface::BeginDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-begindraw) method. This method not only provides pixels for the surface, but it also allocates actual storage space for those pixels. The memory allocation persists until the application returns some of the memory to the system. The application can free part or all of the allocated memory by calling the [IDCompositionVirtualSurface::Trim](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvirtualsurface-trim) or [IDCompositionVirtualSurface::Resize](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvirtualsurface-resize) method.

Microsoft DirectComposition surfaces support the following pixel formats:

* DXGI_FORMAT_B8G8R8A8_UNORM
* DXGI_FORMAT_R8G8B8A8_UNORM
* DXGI_FORMAT_R16G16B16A16_FLOAT

## See also

[IDCompositionDevice2::CreateSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice2-createsurface)

[IDCompositionDevice2::CreateVirtualSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice2-createvirtualsurface)

[IDCompositionSurfaceFactory](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionsurfacefactory)

[IDCompositionSurfaceFactory::CreateVirtualSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurfacefactory-createvirtualsurface)
# IDCompositionDevice2::CreateVirtualSurface

## Description

 Creates a sparsely populated surface that can be associated with one or more visuals for composition.

## Parameters

### `initialWidth` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The width of the surface, in pixels. The maximum width is 16,777,216 pixels.

### `initialHeight` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The height of the surface, in pixels. The maximum height is 16,777,216 pixels.

### `pixelFormat` [in]

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

The pixel format of the surface.

### `alphaMode` [in]

Type: **[DXGI_ALPHA_MODE](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ne-dxgi1_2-dxgi_alpha_mode)**

The meaning of the alpha channel, if the pixel format contains an alpha channel. It can be one of the following values:

| Value | Meaning |
| --- | --- |
| **DXGI_ALPHA_MODE_UNSPECIFIED** | The alpha channel is not specified. This value has the same effect as **DXGI_ALPHA_MODE_IGNORE**. |
| **DXGI_ALPHA_MODE_PREMULTIPLIED** | The color channels contain values that are premultiplied with the alpha channel. |
| **DXGI_ALPHA_MODE_IGNORE** | The alpha channel should be ignored and the bitmap should be rendered opaquely. |

### `virtualSurface` [out]

Type: **[IDCompositionVirtualSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvirtualsurface)****

The newly created surface object. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

A Microsoft DirectComposition sparse surface is a logical object that behaves like a rectangular array of pixels that can be associated with a visual for composition. The surface is not necessarily backed by any physical video or system memory for every one of its pixels. The application can realize or virtualize parts of the logical surface at different times.

A newly created surface object is in an uninitialized state. While it is uninitialized, the surface has no effect on the composition of the visual tree. It behaves exactly like a surface that is initialized with 100% transparent pixels.

To initialize the surface with pixel data, use the [IDCompositionSurface::BeginDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-begindraw) and [IDCompositionSurface::EndDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-enddraw) methods. This method not only provides pixels for the surface, but it also allocates actual storage space for those pixels. The memory allocation persists until the application returns some of the memory to the system. The application can free part or all of the allocated memory by calling the [IDCompositionVirtualSurface::Trim](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvirtualsurface-trim) method.

DirectComposition surfaces support the following pixel formats:

* **DXGI_FORMAT_B8G8R8A8_UNORM**
* **DXGI_FORMAT_R8G8B8A8_UNORM**
* **DXGI_FORMAT_R16G16B16A16_FLOAT**

This method fails if *initialWidth* or *initialHeight* exceeds 16,777,216 pixels.

## See also

[IDCompositionDevice2](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice2)

[IDCompositionDevice::CreateSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-createsurface)
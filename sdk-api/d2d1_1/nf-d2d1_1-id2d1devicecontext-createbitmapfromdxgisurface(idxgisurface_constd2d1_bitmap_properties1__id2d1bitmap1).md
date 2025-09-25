# ID2D1DeviceContext::CreateBitmapFromDxgiSurface(IDXGISurface,const D2D1_BITMAP_PROPERTIES1 &,ID2D1Bitmap1)

## Description

 Creates a bitmap from a DXGI surface that can be set as a target surface or have additional color context information specified.

## Parameters

### `surface` [in]

Type: **[IDXGISurface](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgisurface)***

The DXGI surface from which the bitmap can be created.

**Note** The DXGI surface must have been created from the same Direct3D device that the Direct2D device context is associated with.

### `bitmapProperties` [in, optional]

Type: **const [D2D1_BITMAP_PROPERTIES1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_bitmap_properties1)***

The bitmap properties specified in addition to the surface.

### `bitmap` [out]

Type: **[ID2D1Bitmap1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1bitmap1)****

When this method returns, contains the address of a pointer to a new bitmap object.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid value was passed to the method. |
| D3DERR_OUTOFVIDEOMEMORY | Direct3D does not have enough display memory to perform the operation. |

## Remarks

If the bitmap properties are not specified, the following information is assumed:

* The bitmap DPI is 96.
* The pixel format matches that of the surface.
* The returned bitmap will inherit the bind flags of the DXGI surface.
  + However, only the subset of flags meaningful to Direct2D will be inherited. For example, D3D10_USAGE_DYNAMIC is not compatible with any public Direct2D flags.
* The color context is unknown.
* The alpha mode of the bitmap will be premultiplied (common case) or straight (A8).

If the bitmap properties are specified, the bitmap properties will be used as follows:

* The bitmap DPI will be specified by the bitmap properties.
* If both dpiX and dpiY are 0, the bitmap DPI will be 96.
* The pixel format must be compatible with the shader resource view or render target view of the surface.
* The bitmap options must be compatible with the bind flags of the DXGI surface. However, they may be a subset. This will influence what resource views are created by the bitmap.
* The color context information will be used from the bitmap properties, if specified.

## See also

[D2D1_BITMAP_PROPERTIES1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_bitmap_properties1)

[ID2D1Bitmap1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1bitmap1)

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)

[ID2D1DeviceContext::SetTarget](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-settarget)
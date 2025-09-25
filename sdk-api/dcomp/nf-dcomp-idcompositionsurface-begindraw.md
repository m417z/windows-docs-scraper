# IDCompositionSurface::BeginDraw

## Description

Initiates drawing on this Microsoft DirectComposition surface object. The update rectangle must be within the boundaries of the surface; otherwise, this method fails.

## Parameters

### `updateRect` [in, optional]

Type: **const [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

The rectangle to be updated. If this parameter is NULL, the entire bitmap is updated.

### `iid` [in]

Type: **REFIID**

The identifier of the interface to retrieve.

### `updateObject` [out]

Type: **void****

Receives an interface pointer of the type specified in the *iid* parameter. This parameter must not be NULL.

**Note** In Windows 8, this parameter was *surface*.

### `updateOffset` [out]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

The offset into the surface where the application should draw updated content. This offset will reference the upper left corner of the update rectangle.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method enables an application to incrementally update the contents of a DirectComposition surface object. The application must use the following sequence:

1. Call **BeginDraw** to initiate the incremental update.
2. Use the retrieved surface as a render target and draw the updated contents at the retrieved offset.
3. Call the [IDCompositionSurface::EndDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-enddraw) method to finish the update.

The update object returned by this method is either a Direct2D device context or a DXGI surface, depending on the value of the *iid* parameter and on how the DirectComposition surface object was created. If the *iid* parameter is __uuidof(ID2D1DeviceContext), then the returned object is a Direct2D device context that already has the DirectComposition surface selected as a render target. Otherwise, it is a DXGI surface which the application may use as a render target. In either case, the returned object is associated with the Direct2D or DXGI device passed by the application to the DCompositionCreateDevice2 function or the [IDCompositionDevice2::CreateSurfaceFactory](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice2-createsurfacefactory) method.

The *iid* parameter may only be __uuidof(ID2D1DeviceContext) if the DirectComposition surface object was created from a DirectComposition device or surface factory that was, itself, created with an associated Direct2D device. In particular, the application must have called either the DCompositionCreateDevice2 function or the [IDCompositionDevice2::CreateSurfaceFactory](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice2-createsurfacefactory) method with a Direct2D device as the *renderingDevice* parameter. If the DirectComposition surface was created via a surface factory that was not associated with a Direct2D device, or if it was created directly via the IDCompositionDevice2 interface and the device was not directly associated with a Direct2D device, then passing __uuidof(ID2D1DeviceContext) as the iid parameter causes this method to return E_INVALIDARG.

If the application successfully retrieves a Direct2D device context as the update object, then the application should not call either the ID2D1DeviceContext::BeginDraw or ID2D1DeviceContext::EndDraw methods on the returned Direct2D device context.

The retrieved offset is not necessarily the same as the top-left corner of the requested update rectangle. The application must transform its rendering primitives to draw within a rectangle of the same width and height as the input rectangle, but at the given offset. The application should not draw outside of this rectangle.

If the *updateRectangle* parameter is NULL, the entire surface is updated. In that case, because the retrieved offset still might not be (0,0), the application still needs to transform its rendering primitives accordingly.

If the surface is not a virtual surface, then the first time the application calls this method for a particular non-virtual surface, the update rectangle must cover the entire surface, either by specifying the full surface in the requested update rectangle, or by specifying NULL as the *updateRectangle* parameter. For virtual surfaces, the first call may be any sub-rectangle of the surface.

Because each call to this method might retrieve a different object in the *updateObject* surface, the application should not cache the retrieved surface pointer. The application should release the retrieved pointer as soon as it finishes drawing.

The retrieved surface rectangle does not contain the previous contents of the bitmap. The application must update every pixel in the update rectangle, either by first clearing the render target, or by issuing enough rendering primitives to fully cover the update rectangle. Because the initial contents of the update surface are undefined, failing to update every pixel leads to undefined behavior.

Only one DirectComposition surface can be updated at a time. An application must suspend drawing on one surface before beginning or resuming to draw on another surface. If the application calls **BeginDraw** twice, either for the same surface or for another surface belonging to the same DirectComposition device, without an intervening call to [IDCompositionSurface::EndDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-enddraw), the second call fails. If the application calls [IDCompositionDevice2::Commit](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice2-commit) without calling **EndDraw**, the update remains pending. The update takes effect only after the application calls **EndDraw** and then calls the **IDCompositionDevice2::Commit** method.

## See also

[IDCompositionSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionsurface)

[IDCompositionSurface::EndDraw](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionsurface-enddraw)
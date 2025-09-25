# IDCompositionVisual::SetContent

## Description

Sets the Content property of this visual to the specified bitmap or window wrapper.

## Parameters

### `content` [in, optional]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

The object that is the new content of this visual. This parameter can be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

The *content* parameter must point to one of the following:

* An object that implements the [IDCompositionSurface](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionsurface) interface.
* An object that implements the **IDXGISwapChain1** interface.
* A wrapper object that is returned by the [CreateSurfaceFromHandle](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-createsurfacefromhandle) or [CreateSurfaceFromHwnd](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-createsurfacefromhwnd) method.

The new content replaces any content that was previously associated with the visual. If the *content* parameter is NULL, the visual has no associated content.

A visual can be associated with a bitmap object or a window wrapper. A bitmap is either a Microsoft DirectX swap chain or a Microsoft DirectComposition surface.

A window wrapper is created with the [CreateSurfaceFromHwnd](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-createsurfacefromhwnd) method and is a stand-in for the rasterization of another window, which must be a top-level window or a layered child window. A window wrapper is conceptually equivalent to a bitmap that is the size of the target window on which the contents of the window are drawn. The contents include the target window's child windows (layered or otherwise), and any DirectComposition content that is drawn in the child windows.

A DirectComposition surface wrapper is created with the [CreateSurfaceFromHandle](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-createsurfacefromhandle) method and is a reference to a swap chain. An application might use a surface wrapper in a cross-process scenario where one process creates the swap chain and another process associates the bitmap with a visual.

The bitmap is always drawn at position (0,0) relative to the visual's coordinate system, although the coordinate system is directly affected by the OffsetX, OffsetY, and Transform properties, as well as indirectly by the transformations on ancestor visuals. The bitmap of a visual is always drawn behind the children of that visual.

## See also

[IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual)

**IDXGIFactory2::CreateSwapChain1**
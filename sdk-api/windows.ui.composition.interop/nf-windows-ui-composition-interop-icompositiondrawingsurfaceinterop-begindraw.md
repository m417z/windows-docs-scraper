# ICompositionDrawingSurfaceInterop::BeginDraw (windows.ui.composition.interop.h)

## Description

Initiates drawing on the surface.

## Parameters

### `updateRect` [in, optional]

Type: **const RECT***

The section of the surface to update. The update rectangle must be within the boundaries of the surface. Specifying nullptr indicates the entire surface should be updated.

### `iid` [in]

Type: **REFIID**

The identifier of the interface to retrieve.

### `updateObject` [out]

Type: **void****

Receives an interface pointer of the type specified in the iid parameter. This parameter must not be NULL.

### `updateOffset` [out]

Type: **POINT***

The offset into the surface where the application should draw updated content. This offset will reference the upper left corner of the update rectangle.

## Return value

Type: **HRESULT**

If this method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## See also

[ICompositionDrawingSurfaceInterop](https://learn.microsoft.com/windows/desktop/api/windows.ui.composition.interop/nn-windows-ui-composition-interop-icompositiondrawingsurfaceinterop)
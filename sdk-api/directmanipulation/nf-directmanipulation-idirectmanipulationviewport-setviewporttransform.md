# IDirectManipulationViewport::SetViewportTransform

## Description

Specifies the transform from the viewport coordinate system to the window client coordinate system.

## Parameters

### `matrix` [in]

The transform matrix, in row-wise order: _11, _12, _21, _22, _31, _32.

### `pointCount` [in]

The size of the transform matrix. This value is always 6, because a 3x2 matrix is used for all direct manipulation transforms.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call this function to specify the viewport position, scaling and orientation on the screen. Viewport position, scaling, orientation and size are uniquely determined by the viewport transform and the viewport rectangle. The application can specify the viewport transform using this method, and the viewport rectangle using [SetViewportRect](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-setviewportrect).

The viewport rectangle (the rectangular area inside the content that is visible to the user) is specified in viewport coordinates. If the viewport rectangle top-left point is (0,0), the viewport rectangle is positioned exactly at the viewport coordinate system origin. Viewports offset from the viewport coordinate system origin can be specified in two ways:

* Through the viewport rectangle top-left point
* Through the viewport transform translation component (_31, _32)

The viewport transform converts from the viewport coordinate system to the window client coordinate system. [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal) ignores the window RTL property, so the client area origin is always the top-left point.
The transforms are applied in the following order:

1. Viewport rectangle offset
2. Viewport transform (from viewport to client coordinate system)
3. Client to screen mapping (from client to screen coordinate system)

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)
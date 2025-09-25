# IDirectManipulationViewport::ZoomToRect

## Description

Moves the viewport to a specific area of the primary content and specifies whether to animate the transition.

## Parameters

### `left` [in]

The leftmost coordinate of the rectangle in the primary content coordinate space.

### `top` [in]

The topmost coordinate of the rectangle in the primary content coordinate space.

### `right` [in]

The rightmost coordinate of the rectangle in the primary content coordinate space.

### `bottom` [in]

The bottommost coordinate of the rectangle in the primary content coordinate space.

### `animate` [in]

Specifies whether to animate the zoom behavior.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)
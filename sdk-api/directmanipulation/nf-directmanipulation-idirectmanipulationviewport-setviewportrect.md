# IDirectManipulationViewport::SetViewportRect

## Description

 Sets the bounding rectangle for the viewport, relative to the origin of the viewport coordinate system.

## Parameters

### `viewport` [in]

The bounding rectangle.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The viewport rectangle specifies the region of content that is visible to the user. In conjunction with the primary content rectangle, the viewport rectangle is used to determine chaining behaviors.

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)
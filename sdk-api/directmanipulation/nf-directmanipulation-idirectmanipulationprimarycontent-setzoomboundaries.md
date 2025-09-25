# IDirectManipulationPrimaryContent::SetZoomBoundaries

## Description

Specifies the minimum and maximum boundaries for zoom.

## Parameters

### `zoomMinimum` [in]

The minimum zoom level allowed. Must be greater than or equal to 0.1f, which corresponds to 100% zoom.

### `zoomMaximum` [in]

The maximum zoom allowed. Must be greater than *zoomMinimum* and less than [FLT_MAX](https://learn.microsoft.com/previous-versions/ms858507(v=msdn.10)).

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the content is outside the new boundaries, and the viewport is ENABLED or READY, then the content is reset to be within the new boundaries. If inertia configuration is enabled, the reset operation uses an inertia animation.

## See also

[IDirectManipulationPrimaryContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationprimarycontent)
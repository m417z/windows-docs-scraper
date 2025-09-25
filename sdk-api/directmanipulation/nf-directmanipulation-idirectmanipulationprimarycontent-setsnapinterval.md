# IDirectManipulationPrimaryContent::SetSnapInterval

## Description

 Specifies snap points for the inertia end position at uniform intervals.

## Parameters

### `motion` [in]

One of the [DIRECTMANIPULATION_MOTION_TYPES](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_motion_types) enumeration values.

### `interval` [in]

The interval between each snap point.

### `offset` [in]

The offset from the coordinate specified in [SetSnapCoordinate](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationprimarycontent-setsnapcoordinate).

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Snap point locations are in content coordinate units.

Specify snap points through [SetSnapPoints](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationprimarycontent-setsnappoints) or **SetSnapInterval**.

If snap points are invalid (for example, outside of the content boundaries), they are ignored and the content is always within the content boundaries.

Snap points are not at boundaries by default. If you wish for content to stop at a boundary, a snap point must be set at the boundary.

 Snap points set by **SetSnapInterval** can be cleared by calling **SetSnapInterval** with an interval of 0.0f.

#### Examples

The following example shows how to set the coordinate system for X translation snap points to the origin. Snap points are set every 45 pixels, beginning at the origin along the X-axis.

```
HRESULT hr = SetSnapCoordinate(testWindow, 0, DIRECTMANIPULATION_MOTION_TRANSLATEX, DIRECTMANIPULATION_COORDINATE_ORIGIN, 0.0f);
hr = pContent->SetSnapInterval(DIRECTMANIPULATION_MOTION_TRANSLATEX, 45.0f, 0.0f);
```

## See also

[IDirectManipulationPrimaryContent](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationprimarycontent)

[SetSnapCoordinate](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationprimarycontent-setsnapcoordinate)

[SetSnapPoints](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationprimarycontent-setsnappoints)
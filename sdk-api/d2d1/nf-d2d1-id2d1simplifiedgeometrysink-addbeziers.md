# ID2D1SimplifiedGeometrySink::AddBeziers

## Description

Creates a sequence of cubic Bezier curves and adds them to the geometry sink.

## Parameters

### `beziers` [in]

Type: **const [D2D1_BEZIER_SEGMENT](https://learn.microsoft.com/windows/win32/api/d2d1/ns-d2d1-d2d1_bezier_segment)***

A pointer to an array of Bezier segments that describes the Bezier curves to create. A curve is drawn from the geometry sink's current point (the end point of the last segment drawn or the location specified by [BeginFigure](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1simplifiedgeometrysink-beginfigure)) to the end point of the first Bezier segment in the array. if the array contains additional Bezier segments, each subsequent Bezier segment uses the end point of the preceding Bezier segment as its start point.

### `beziersCount`

Type: **UINT**

The number of Bezier segments in the *beziers* array.

## See also

[ID2D1SimplifiedGeometrySink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1simplifiedgeometrysink)
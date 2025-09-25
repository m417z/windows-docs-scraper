# ID2D1SimplifiedGeometrySink::AddLines

## Description

Creates a sequence of lines using the specified points and adds them to the geometry sink.

## Parameters

### `points` [in]

Type: **const [D2D1_POINT_2F](https://learn.microsoft.com/windows/win32/Direct2D/d2d1-point-2f)***

A pointer to an array of one or more points that describe the lines to draw. A line is drawn from the geometry sink's current point (the end point of the last segment drawn or the location specified by [BeginFigure](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1simplifiedgeometrysink-beginfigure)) to the first point in the array. if the array contains additional points, a line is drawn from the first point to the second point in the array, from the second point to the third point, and so on.

### `pointsCount`

Type: **UINT**

The number of points in the *points* array.

## See also

[ID2D1SimplifiedGeometrySink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1simplifiedgeometrysink)
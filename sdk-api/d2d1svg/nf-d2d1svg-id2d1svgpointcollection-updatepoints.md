# ID2D1SvgPointCollection::UpdatePoints

## Description

Updates the points array. Existing points not updated by this method are preserved. The array is resized larger if necessary to accommodate the new points.

## Parameters

### `points` [in]

Type: **const D2D1_POINT_2F***

The points array.

### `pointsCount`

Type: **UINT32**

The number of points to update.

### `startIndex`

Type: **UINT32**

The index at which to begin updating points. Must be less than or equal to the size of the array.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[ID2D1SvgPointCollection](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgpointcollection)
# ID2D1SvgDocument::CreatePointCollection

## Description

Creates a points object which can be used to set a points attribute on a polygon or polyline element.

## Parameters

### `points` [in, optional]

Type: **const D2D1_POINT_2F***

The points in the point collection.

### `pointsCount`

Type: **UINT32**

The number of points in the points argument.

### `pointCollection` [out]

Type: **ID2D1SvgPointCollection****

The created [ID2D1SvgPointCollection](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgpointcollection) object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[ID2D1SvgDocument](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgdocument)
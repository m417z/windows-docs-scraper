# ID2D1PathGeometry1::ComputePointAndSegmentAtLength(FLOAT,UINT32,const D2D1_MATRIX_3X2_F,D2D1_POINT_DESCRIPTION)

## Description

Computes the point that exists at a given distance along the path geometry along with the index of the segment
the point is on and the directional vector at that point.

## Parameters

### `length`

Type: **FLOAT**

The distance to walk along the path.

### `startSegment`

Type: **UINT32**

The index of the segment at which to begin walking. Note: This index is global to the entire path, not just a particular figure.

### `worldTransform` [in, optional]

Type: **const [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f)***

The transform to apply to the path prior to walking.

### `pointDescription` [out]

Type: **[D2D1_POINT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_point_description)***

When this method returns, contains a description of the point that can be found at the given location.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | One of the inputs was in an invalid range. |

## See also

[ID2D1PathGeometry1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1pathgeometry1)
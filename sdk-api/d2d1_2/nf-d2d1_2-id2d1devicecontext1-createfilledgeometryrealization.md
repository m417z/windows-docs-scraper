# ID2D1DeviceContext1::CreateFilledGeometryRealization

## Description

Creates a device-dependent representation of the fill of the geometry that can be subsequently rendered.

## Parameters

### `geometry` [in]

Type: **[ID2D1Geometry](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1geometry)***

The geometry to realize.

### `flatteningTolerance`

Type: **FLOAT**

The flattening tolerance to use when converting Beziers to line segments. This parameter shares the same units as the coordinates of the geometry.

### `geometryRealization`

Type: **[ID2D1GeometryRealization](https://learn.microsoft.com/windows/desktop/api/d2d1_2/nn-d2d1_2-id2d1geometryrealization)****

When this method returns, contains the address of a pointer to a new geometry realization object.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid value was passed to the method. |

## Remarks

This method is used in conjunction with [ID2D1DeviceContext1::DrawGeometryRealization](https://learn.microsoft.com/windows/desktop/api/d2d1_2/nf-d2d1_2-id2d1devicecontext1-drawgeometryrealization). The [D2D1::ComputeFlatteningTolerance](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn280327(v=vs.85)) helper API may be used to determine the proper flattening tolerance.

If the provided stroke style specifies a stroke transform type other than [D2D1_STROKE_TRANSFORM_TYPE_NORMAL](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_stroke_transform_type), then the stroke will be realized assuming the identity transform and a DPI of 96.

## See also

[ID2D1DeviceContext1](https://learn.microsoft.com/windows/desktop/api/d2d1_2/nn-d2d1_2-id2d1devicecontext1)
# IInkDisp::NearestPoint

## Description

Retrieves the [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) within the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object that is nearest to a known point, optionally providing the index of the nearest point and the distance to the stroke from the specified point.

## Parameters

### `X` [in]

The `x-` position in ink space of the point.

### `Y` [in]

Specifies the `y-` position in ink space of the point.

### `PointOnStroke` [in, out, optional]

Optional. Retrieves the point on the line of the stroke that is closest to the specified point within the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object. For example, a value of 1.5 indicates that the point falls halfway between the first and second packets of the stroke. This parameter can be **NULL**. The default value is 0.

### `DistanceFromPacket` [in, out, optional]

Optional. Retrieves the distance between the specified point in ink space and the nearest stroke in the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object. This parameter can be **NULL**. the default value is 0.

### `Stroke` [out, retval]

When this method returns, contains the [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) that contains a point that is closest to the specified point in the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object. If more than one stroke contains a point that is the same distance from the specified point, the value of this result is arbitrary.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_OUTOFMEMORY** | Cannot allocate memory operation. |

## Remarks

The output *point* parameter is defined as a floating-point number because the point on the line of the stroke can fall between two physical coordinate points. Use this value to split the stroke with the [Split](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-split) method, or round the value up or down to index a packet in the stroke.

The *distanceFromPacket* parameter describes the distance from the point to the envelope of the stroke. This is the distance between the two points minus half the width of the stroke.

## See also

[IInkDisp](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdisp)

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[NearestPoint Method [IInkStrokeDisp Interface]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-nearestpoint)

[Split Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-split)
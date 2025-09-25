# IInkStrokeDisp::get_PolylineCusps

## Description

Gets an array that contains the indices of the cusps of the [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object.

This property is read-only.

## Parameters

## Remarks

The array returned by the **PolylineCusps** property is an index into the array returned by the [GetPoints](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-getpoints) method. Each index in the **PolylineCusps** property corresponds to a point in the array returned by the **GetPoints** method that is a cusp of the points of the stroke.

A cusp is a point on the stroke where the direction of writing changes in a discontinuous fashion. For example, if the stroke represents the capital letter "L", this property returns three cusps: two corresponding to the first and last control points on the stroke and the third representing the corner of the "L".

The location of a cusp can be determined by using the cusp as an index into the array returned by the [GetPoints](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-getpoints) method.

## See also

[GetPoints Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-getpoints)

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)
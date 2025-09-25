# IInkStrokeDisp::get_BezierCusps

## Description

Gets an array that contains the indices of the **cusps** of the Bezier approximation of the stroke.

This property is read-only.

## Parameters

## Remarks

**Note** The array of Bezier control points that the [BezierPoints](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-get_bezierpoints) property returns are made up of x and y values. The **BezierCusps** property refers only to the x values in this array. The y values can be retrieved by an action similar to the following below.

A cusp is a point on the stroke where the direction of writing changes in a discontinuous fashion. For example, if the stroke represents the capital letter "L", this property returns three cusps: two corresponding to the first and last control points on the stroke and the third representing the corner of the "L".

The following code extracts the x and y values of the Bezier cusps of an [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp), `theStroke`, and stores them in a two-dimensional array called `BezierCuspValues`.

## See also

[BezierPoints Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-get_bezierpoints)

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)
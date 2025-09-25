# InkBoundingBoxMode enumeration

## Description

Specifies which characteristics of a stroke, such as drawing attributes, are used to calculate the bounding box of the ink.

The bounding box is the smallest rectangle that includes all points in the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object. The size of the rectangle varies depending on whether you use drawing attributes, Bezier curve fitting, or just the points of the stroke to calculate the rectangle.

## Constants

### `IBBM_Default:0`

 The definition of each stroke (polyline or Bezier) is used to calculate the bounding box; includes the drawing attributes, such as pen width, in the calculation.

### `IBBM_NoCurveFit:1`

 The polyline of the strokes (ignoring Bezier curve fitting requests) is used to calculate the bounding box; includes the drawing attributes in the calculation.

### `IBBM_CurveFit:2`

The Bezier curve fitting line of the strokes (apply Bezier curve fitting to all strokes) is used to calculate the bounding box; includes the drawing attributes in the calculation.

### `IBBM_PointsOnly:3`

 Only the points of the strokes are used to calculate the bounding box.

### `IBBM_Union:4`

 The union of a NoCurveFit request and a CurveFit request.

## See also

[GetBoundingBox Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-getboundingbox)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)
# IInkStrokeDisp::get_SelfIntersections

## Description

Gets the self-intersections of the stroke.

This property is read-only.

## Parameters

## Remarks

A self-intersection is the point of a stroke where the stroke crosses over itself.

A floating point index is a float value that represents a location somewhere between two points in the stroke. As examples, if 0.0 is the first point in the stroke and 1.0 is the second point in the stroke, 0.5 is halfway between the first and second points. Similarly, a floating point index value of 37.25 represents a location that is 25 percent along the line between points 37 and 38 of the stroke.

**Note** A floating point index is returned for each intersection and line segment combination. If a stroke has one intersection, this property returns two self intersections, one for each line segment that is part of the intersection.

## See also

[IInkStrokeDisp Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)
# LinearGradientBrush::LinearGradientBrush(IN const Rect &,IN const Color &,IN const Color &,IN REAL,IN BOOL)

## Description

Creates a **LinearGradientBrush::LinearGradientBrush** object from a rectangle and angle of direction.

## Parameters

### `rect` [in, ref]

Type: **const [Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)**

Reference to a rectangle that specifies the starting and ending points of the gradient. The upper-left corner of the rectangle is the starting point. The lower-right corner is the ending point.

### `color1` [in, ref]

Type: **const [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)**

Reference to a [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) object that specifies the color at the starting boundary line of this linear gradient brush.

### `color2` [in, ref]

Type: **const [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)**

Reference to a [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) object that specifies the color at the ending boundary line of this linear gradient brush.

### `angle` [in]

Type: **REAL**

Real number that, if *isAngleScalable* is **TRUE**, specifies the base angle from which the angle of the directional line is calculated, or that, if *isAngleScalable* is **FALSE**, specifies the angle of the directional line. The angle is measured from the top of the rectangle that is specified by *rect* and must be in degrees. The gradient follows the directional line.

### `isAngleScalable` [in]

Type: **BOOL**

Boolean value that specifies whether the angle is scalable. If *isAngleScalable* is **TRUE**, the angle of the directional line is scalable; otherwise, the angle is not scalable.

## Remarks

The "directional line," an imaginary straight line, is defined by the starting point (upper-left corner of the rectangle *rect*) and the angle *angle*. The starting boundary of the gradient is a straight line that is perpendicular to the directional line and that passes through the starting point. The ending boundary of the gradient is a straight line that is parallel to the starting boundary line and that passes through the ending point (lower-right corner of the rectangle *rect*). The gradient color is constant along lines that are parallel to the boundary lines. The gradient gradually changes from the starting color to the ending color along the directional line.

If *isAngleScalable* is **TRUE**, the base angle is scaled to produce the angle of the directional line:

ß = arctan( (width / height) tan(ø) )

where ß is the new angle of the directional line; width and height are the dimensions of the rectangle rect; and ø is the base angle *angle*. This relationship is valid only if angle is less than 90 degrees.

## See also

[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush)
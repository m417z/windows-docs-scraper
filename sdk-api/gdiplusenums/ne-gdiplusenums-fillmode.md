# FillMode enumeration

## Description

The **FillMode** enumeration specifies how to fill areas that are formed when a path or curve intersects itself. This enumeration is used by several methods of the [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) class, including
[FillClosedCurve](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillclosedcurve(inconstbrush_inconstpointf_inint_infillmode_inreal)) and
[FillPolygon](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillpolygon(inconstbrush_inconstpointf_inint_infillmode)), and by the constructors of the
[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath) class.

## Constants

### `FillModeAlternate`

Specifies that areas are filled according to the even-odd parity rule. According to this rule, you can determine whether a test point is inside or outside a closed curve as follows: Draw a line from the test point to a point that is distant from the curve. If that line crosses the curve an odd number of times, the test point is inside the curve; otherwise, the test point is outside the curve.

### `FillModeWinding`

Specifies that areas are filled according to the nonzero winding rule. According to this rule, you can determine whether a test point is inside or outside a closed curve as follows: Draw a line from a test point to a point that is distant from the curve. Count the number of times the curve crosses the test line from left to right, and count the number of times the curve crosses the test line from right to left. If those two numbers are the same, the test point is outside the curve; otherwise, the test point is inside the curve.

## See also

[FillClosedCurve Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillclosedcurve(inconstbrush_inconstpointf_inint_infillmode_inreal))

[FillPolygon Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-fillpolygon(inconstbrush_inconstpointf_inint_infillmode))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[GraphicsPath Constructors](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspath-graphicspath(constgraphicspath_))
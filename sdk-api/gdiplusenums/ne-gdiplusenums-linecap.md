# LineCap enumeration

## Description

The **LineCap** enumeration specifies the type of graphic shape to use on the end of a line drawn with a Windows GDI+ pen. The cap can be a square, circle, triangle, arrowhead, custom, or masked (hidden). End caps can also "anchor" the line by centering the cap at the end of the line.

## Constants

### `LineCapFlat:0`

Specifies that the line ends at the last point. The end is squared off.

### `LineCapSquare:1`

Specifies a square cap. The center of the square is the last point in the line. The height and width of the square are the line width.

### `LineCapRound:2`

Specifies a circular cap. The center of the circle is the last point in the line. The diameter of the circle is the line width.

### `LineCapTriangle:3`

Specifies a triangular cap. The base of the triangle is the last point in the line. The base of the triangle is the line width.

### `LineCapNoAnchor:0x10`

Specifies that the line ends are not anchored.

### `LineCapSquareAnchor:0x11`

Specifies that the line ends are anchored with a square. The center of the square is the last point in the line. The height and width of the square are the line width.

### `LineCapRoundAnchor:0x12`

Specifies that the line ends are anchored with a circle. The center of the circle is at the last point in the line. The circle is wider than the line.

### `LineCapDiamondAnchor:0x13`

Specifies that the line ends are anchored with a diamond (a square turned at 45 degrees). The center of the diamond is at the last point in the line. The diamond is wider than the line.

### `LineCapArrowAnchor:0x14`

Specifies that the line ends are anchored with arrowheads. The arrowhead point is located at the last point in the line. The arrowhead is wider than the line.

### `LineCapCustom:0xff`

Specifies that the line ends are made from a
[CustomLineCap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-customlinecap).

### `LineCapAnchorMask:0xf0`
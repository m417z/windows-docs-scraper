# PenAlignment enumeration

## Description

The **PenAlignment** enumeration specifies the alignment of a pen relative to the stroke that is being drawn.

## Constants

### `PenAlignmentCenter:0`

Specifies that the pen is aligned on the center of the line that is drawn.

### `PenAlignmentInset:1`

Specifies, when drawing a polygon, that the pen is aligned on the inside of the edge of the polygon.

## Remarks

If you set the alignment of a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object to ****PenAlignmentInset****, you cannot use that pen to draw compound lines or triangular dash caps.
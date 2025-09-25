# DashCap enumeration

## Description

The **DashCap** enumeration specifies the type of graphic shape to use on both ends of each dash in a dashed line.

## Constants

### `DashCapFlat:0`

Specifies a square cap that squares off both ends of each dash.

### `DashCapRound:2`

Specifies a circular cap that rounds off both ends of each dash.

### `DashCapTriangle:3`

Specifies a triangular cap that points both ends of each dash.

## Remarks

If you set the alignment of a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) object to **PenAlignmentInset**, you cannot use that pen to draw triangular dash caps.
# StringAlignment enumeration

## Description

The **StringAlignment** enumeration specifies how a string is aligned in reference to the bounding rectangle. A bounding rectangle is used to define the area in which the text displays.

## Constants

### `StringAlignmentNear:0`

Specifies that alignment is towards the origin of the bounding rectangle. May be used for alignment of characters along the line or for alignment of lines within the rectangle. For a right to left bounding rectangle ([StringFormatFlagsDirectionRightToLeft](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-stringformatflags)), the origin is at the upper right.

### `StringAlignmentCenter:1`

Specifies that alignment is centered between origin and extent (width or height) of the formatting rectangle.

### `StringAlignmentFar:2`

Specifies that alignment is to the far extent (lower right) of the formatting rectangle.
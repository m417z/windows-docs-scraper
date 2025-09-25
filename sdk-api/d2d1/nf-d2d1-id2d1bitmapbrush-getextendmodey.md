# ID2D1BitmapBrush::GetExtendModeY

## Description

 Gets the method by which the brush vertically tiles those areas that extend past its bitmap.

## Return value

Type: **[D2D1_EXTEND_MODE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_extend_mode)**

A value that specifies how the brush vertically tiles those areas that extend past its bitmap.

## Remarks

Like all brushes, [ID2D1BitmapBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmapbrush) defines an infinite plane of content.

 Because bitmaps are finite, it relies on an extend mode to determine how the plane is filled horizontally and vertically.

## See also

[ID2D1BitmapBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmapbrush)

[ID2D1BitmapBrush::SetExtendModeY](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1bitmapbrush-setextendmodey)
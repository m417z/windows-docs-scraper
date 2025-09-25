# PathGradientBrush::PathGradientBrush(IN const PointF,IN INT,IN WrapMode)

## Description

Creates a [PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object based on an array of points. Initializes the wrap mode of the path gradient brush.

## Parameters

### `points` [in]

Type: **const [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)***

Pointer to an array of points that specifies the boundary path of the path gradient brush.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the *points* array.

### `wrapMode` [in]

Type: **[WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode)**

Optional. Element of the [WrapMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-wrapmode) enumeration that specifies how areas painted with the path gradient brush will be tiled. The default value is WrapModeClamp.

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Creating a Path Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-creating-a-path-gradient-use)

[Filling a Shape with a Color Gradient](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-color-gradient-use)

[GraphicsPath](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-graphicspath)

[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush)

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)
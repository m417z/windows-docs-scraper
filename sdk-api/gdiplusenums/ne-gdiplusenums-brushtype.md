# BrushType enumeration

## Description

The **BrushType** enumeration indicates the type of brush. There are five types of brushes.

## Constants

### `BrushTypeSolidColor:0`

Indicates a brush of type [SolidBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-solidbrush). A solid brush paints a single, constant color that can be opaque or transparent.

### `BrushTypeHatchFill:1`

Indicates a brush of type [HatchBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-hatchbrush). A hatch brush paints a background and paints, over that background, a pattern of lines, dots, dashes, squares, crosshatch, or some variation of these. The hatch brush consists of two colors: one for the background and one for the pattern over the background. The color of the background is called the
*background color*, and the color of the pattern is called the
*foreground color*.

### `BrushTypeTextureFill:2`

Indicates a brush of type [TextureBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-texturebrush). A texture brush paints an image. The image or
*texture* is either a portion of a specified image or a scaled version of a specified image. The type of image (metafile or nonmetafile) determines whether the texture is a portion of the image or a scaled version of the image.

### `BrushTypePathGradient:3`

Indicates a brush of type [PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush). A path gradient brush paints a color gradient in which the color changes from a center point outward to a boundary that is defined by a closed curve or path. The color gradient has one color at the center point and one or multiple colors at the boundary.

### `BrushTypeLinearGradient:4`

Indicates a brush of type [LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush). A linear gradient brush paints a color gradient in which the color changes evenly from the starting boundary line of the linear gradient brush to the ending boundary line of the linear gradient brush. The boundary lines of a linear gradient brush are two parallel straight lines. The color gradient is perpendicular to the boundary lines of the linear gradient brush, changing gradually across the stroke from the starting boundary line to the ending boundary line. The color gradient has one color at the starting boundary line and another color at the ending boundary line.

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[HatchBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-hatchbrush)

[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush)

[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush)

[SolidBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-solidbrush)

[TextureBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-texturebrush)

[Using a Brush to Fill Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-a-brush-to-fill-shapes-use)
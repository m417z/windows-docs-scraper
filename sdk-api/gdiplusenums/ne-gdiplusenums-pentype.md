# PenType enumeration

## Description

The **PenType** enumeration indicates the type of pattern, texture, or gradient that a pen draws.

## Constants

### `PenTypeSolidColor`

Indicates that the pen draws with a solid color.

### `PenTypeHatchFill`

Indicates that the pen draws with a hatch pattern that is specified by a
[HatchBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-hatchbrush) object.

### `PenTypeTextureFill`

Indicates that the pen draws with a texture that is specified by a
[TextureBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-texturebrush) object.

### `PenTypePathGradient`

Indicates that the pen draws with a color gradient that is specified by a
[PathGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nl-gdipluspath-pathgradientbrush) object.

### `PenTypeLinearGradient`

Indicates that the pen draws with a color gradient that is specified by a
[LinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-lineargradientbrush) object.

### `PenTypeUnknown:-1`

Indicates that the pen type is unknown.

## Remarks

A pen's type is determined when the pen is constructed. For example, if you pass a
[HatchBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-hatchbrush) object to a
[Pen](https://learn.microsoft.com/windows/desktop/api/gdipluspen/nl-gdipluspen-pen) constructor, then the pen that is constructed has a pen type of ****PenTypeHatchFill****. If you pass a
[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) object or a
[SolidBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-solidbrush) object to a
**Pen** constructor, then the pen that is constructed has a pen type of ****PenTypeSolidColor****.
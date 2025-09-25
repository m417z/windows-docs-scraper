# Graphics::SetInterpolationMode

## Description

The **Graphics::SetInterpolationMode** method sets the interpolation mode of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object. The interpolation mode determines the algorithm that is used when images are scaled or rotated.

## Parameters

### `interpolationMode` [in]

Type: **[InterpolationMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-interpolationmode)**

Element of the [InterpolationMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-interpolationmode) enumeration that specifies the interpolation mode.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::GetInterpolationMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getinterpolationmode)

[InterpolationMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-interpolationmode)

[Using Interpolation Mode to Control Image Quality During Scaling](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-interpolation-mode-to-control-image-quality-during-scaling-use)
# HatchBrush::GetBackgroundColor

## Description

The **HatchBrush::GetBackgroundColor** method gets the background color of this hatch brush.

## Parameters

### `color` [out]

Type: **[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)***

Pointer to a [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) object that receives the background color. The background color defines the color over which the hatch lines are drawn.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Brushes and Filled Shapes](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-brushes-and-filled-shapes-about)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Filling a Shape with a Hatch Pattern](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-filling-a-shape-with-a-hatch-pattern-use)

[HatchBrush](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nl-gdiplusbrush-hatchbrush)

[HatchBrush::GetForegroundColor](https://learn.microsoft.com/windows/desktop/api/gdiplusbrush/nf-gdiplusbrush-hatchbrush-getforegroundcolor)

[HatchStyle](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-hatchstyle)
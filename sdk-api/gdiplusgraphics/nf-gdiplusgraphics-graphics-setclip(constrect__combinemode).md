# Graphics::SetClip(IN const Rect &,IN CombineMode)

## Description

The **Graphics::SetClip** method updates the clipping region of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object to a region that is the combination of itself and a rectangle.

## Parameters

### `rect` [in, ref]

Type: **const [Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)**

Reference to a rectangle to be combined with the clipping region of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object.

### `combineMode` [in, optional]

Type: **[CombineMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-combinemode)**

Element of the [CombineMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-combinemode) enumeration that specifies how the specified rectangle is combined with the clipping region of this [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object. The default value is CombineModeReplace.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Clipping](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-about)

[Clipping with a Region](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-clipping-with-a-region-use)

[CombineMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-combinemode)

[GetClipBounds Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getclipbounds(outrect))

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Graphics::GetClip](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getclip)

[Graphics::IsClipEmpty](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-isclipempty)

[Graphics::ResetClip](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-resetclip)

[IntersectClip Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-intersectclip(inconstrect_))

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[TranslateClip Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-translateclip(inint_inint))
# CompositingMode enumeration

## Description

The **CompositingMode** enumeration specifies how rendered colors are combined with background colors. This enumeration is used by the [Graphics::GetCompositingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getcompositingmode) and [Graphics::SetCompositingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setcompositingmode) methods of the
**Graphics** class.

## Constants

### `CompositingModeSourceOver`

Specifies that when a color is rendered, it is blended with the background color. The blend is determined by the alpha component of the color being rendered.

### `CompositingModeSourceCopy`

Specifies that when a color is rendered, it overwrites the background color. This mode cannot be used along with TextRenderingHintClearTypeGridFit.

## See also

[Graphics::GetCompositingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getcompositingmode)

[Graphics::SetCompositingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setcompositingmode)

[TextRenderingHint](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-textrenderinghint)
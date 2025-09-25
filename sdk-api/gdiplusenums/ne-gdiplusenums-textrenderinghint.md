# TextRenderingHint enumeration

## Description

The **TextRenderingHint** enumeration specifies the process used to render text. The process affects the quality of the text.

## Constants

### `TextRenderingHintSystemDefault:0`

Specifies that a character is drawn using the currently selected system font smoothing mode (also called a rendering hint).

### `TextRenderingHintSingleBitPerPixelGridFit`

Specifies that a character is drawn using its glyph bitmap and hinting to improve character appearance on stems and curvature.

### `TextRenderingHintSingleBitPerPixel`

Specifies that a character is drawn using its glyph bitmap and no hinting. This results in better performance at the expense of quality.

### `TextRenderingHintAntiAliasGridFit`

Specifies that a character is drawn using its antialiased glyph bitmap and hinting. This results in much better quality due to antialiasing at a higher performance cost.

### `TextRenderingHintAntiAlias`

Specifies that a character is drawn using its antialiased glyph bitmap and no hinting. Stem width differences may be noticeable because hinting is turned off.

### `TextRenderingHintClearTypeGridFit`

Specifies that a character is drawn using its glyph ClearType bitmap and hinting. This type of text rendering cannot be used along with [CompositingModeSourceCopy](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-compositingmode).

Windows XP and Windows Server 2003 and later versions of Windows only: ClearType rendering is supported only on Windows XP and Windows Server 2003 and later versions of Windows. Therefore, [TextRenderingHintClearTypeGridFit](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-textrenderinghint) is ignored on other operating systems even though GDI+ is supported on those operating systems.

## Remarks

The quality associated with each process varies according to the circumstances. ****TextRenderingHintClearTypeGridFit**** provides the best quality for most LCD monitors and relatively small font sizes. ****TextRenderingHintAntiAlias**** provides the best quality for rotated text. Generally, a process that produces higher quality text is slower than a process that produces lower quality text.

## See also

[Antialiasing with Text](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-antialiasing-with-text-use)

[CompositingMode](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-compositingmode)

[DrawString Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawstring(constwchar_int_constfont_constpointf__constbrush))

[Graphics::GetTextRenderingHint](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-gettextrenderinghint)

[Graphics::SetTextRenderingHint](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-settextrenderinghint)
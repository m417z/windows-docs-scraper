# StringTrimming enumeration

## Description

The **StringTrimming** enumeration specifies how to trim characters from a string so that the string fits into a layout rectangle. The layout rectangle is used to position and size the display string.

## Constants

### `StringTrimmingNone:0`

Specifies that no trimming is done.

### `StringTrimmingCharacter:1`

Specifies that the string is broken at the boundary of the last character that is inside the layout rectangle. This is the default.

### `StringTrimmingWord:2`

Specifies that the string is broken at the boundary of the last word that is inside the layout rectangle.

### `StringTrimmingEllipsisCharacter:3`

Specifies that the string is broken at the boundary of the last character that is inside the layout rectangle and an ellipsis (...) is inserted after the character.

### `StringTrimmingEllipsisWord:4`

Specifies that the string is broken at the boundary of the last word that is inside the layout rectangle and an ellipsis (...) is inserted after the word.

### `StringTrimmingEllipsisPath:5`

Specifies that the center is removed from the string and replaced by an ellipsis. The algorithm keeps as much of the last portion of the string as possible.

## Remarks

Trimming affects only the last visible or partly visible (due to clipping) line of text.

## See also

[DrawString Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawstring(constwchar_int_constfont_constpointf__constbrush))

[Formatting Text](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-formatting-text-use)

[MeasureString Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-measurestring(inconstwchar_inint_inconstfont_inconstpointf__inconststringformat_outrectf))

[StringAlignment](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-stringalignment)

[StringDigitSubstitute](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-stringdigitsubstitute)

[StringFormat::SetTrimming](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nf-gdiplusstringformat-stringformat-settrimming)

[StringFormatFlags](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-stringformatflags)
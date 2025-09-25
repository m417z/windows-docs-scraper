## Description

The **StringFormat::SetMeasurableCharacterRanges** method sets a series of character ranges for this [StringFormat](https://learn.microsoft.com/windows/win32/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat) object that, when in a string, can be measured by the [MeasureCharacterRanges](https://learn.microsoft.com/windows/win32/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-measurecharacterranges) method.

## Parameters

### `rangeCount` [in]

Type: **INT**

Integer that specifies the number of character ranges in the *ranges* array (no more than 32).

### `ranges` [in]

Type: **const [CharacterRange](https://learn.microsoft.com/windows/win32/api/gdiplustypes/nl-gdiplustypes-characterrange)***

Pointer to an array of [CharacterRange](https://learn.microsoft.com/windows/win32/api/gdiplustypes/nl-gdiplustypes-characterrange) objects that specify the character ranges to be measured.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/win32/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/win32/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/win32/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[MeasureCharacterRanges](https://learn.microsoft.com/windows/win32/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-measurecharacterranges)

[StringFormat](https://learn.microsoft.com/windows/win32/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat)

[StringFormat::GetMeasurableCharacterRangeCount](https://learn.microsoft.com/windows/win32/api/gdiplusstringformat/nf-gdiplusstringformat-stringformat-getmeasurablecharacterrangecount)
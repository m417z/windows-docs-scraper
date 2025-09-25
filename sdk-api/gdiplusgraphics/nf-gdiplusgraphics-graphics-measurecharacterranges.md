# Graphics::MeasureCharacterRanges

## Description

The **Graphics::MeasureCharacterRanges** method gets a set of regions each of which bounds a range of character positions within a string.

## Parameters

### `string` [in]

Type: **const WCHAR***

Pointer to a wide-character string.

**Important** For bidirectional languages, such as Arabic, the string length must not exceed 2046 characters.

### `length` [in]

Type: **INT**

Integer that specifies the number of characters in the *string* array. If the *string* parameter points to a **NULL**-terminated string, this parameter can be set to –1.

### `font` [in]

Type: **const [Font](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-font)***

Pointer to a *Font* object that specifies the font characteristics (the family name, size, and style of the font) to be applied to the string.

### `layoutRect` [in, ref]

Type: **const Rectf**

Reference to a rectangle that bounds the string.

### `stringFormat` [in]

Type: **const [StringFormat](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nl-gdiplusstringformat-stringformat)***

Pointer to a *StringFormat* object that specifies the character ranges and layout information, such as alignment, trimming, tab stops, and so forth.

### `regionCount` [in]

Type: **INT**

Integer that specifies the number of regions that are expected to be received into the *regions* array. This number should be equal to the number of character ranges currently in the *StringFormat* object.

### `regions` [out]

Type: **[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region)***

Pointer to an array of *Region* objects that receives the regions, each of which bounds a range of text.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A character range is a range of character positions within a string of text. The area of the display that is occupied by a group of characters that are specified by the character range, is the bounding region. A character range is set by [SetMeasurableCharacterRanges](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nf-gdiplusstringformat-stringformat-setmeasurablecharacterranges). The number of ranges that are currently set can be determined by calling [GetMeasurableCharacterRangeCount](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nf-gdiplusstringformat-stringformat-getmeasurablecharacterrangecount). This number is also the number of regions expected to be obtained by the **MeasureCharacterRanges** method.

#### Examples

The following example defines three ranges of character positions within a string and sets those ranges in a *StringFormat* object. Next, the **MeasureCharacterRanges** method is used to get the three regions of the display that are occupied by the characters that are specified by the ranges. This is done for three different layout rectangles to show how the regions change according to the layout of the string. Also, on the third repetition of this, the string format flags are changed so that the regions measured will include trailing spaces.

```cpp
VOID MeasureCharRanges(HDC hdc)
{
   Graphics graphics(hdc);

   // Brushes and pens used for drawing and painting
   SolidBrush blueBrush(Color(255, 0, 0, 255));
   SolidBrush redBrush(Color(100, 255, 0, 0));
   Pen        blackPen(Color(255, 0, 0, 0));

   // Layout rectangles used for drawing strings
   RectF   layoutRect_A(20.0f, 20.0f, 130.0f, 130.0f);
   RectF   layoutRect_B(160.0f, 20.0f, 165.0f, 130.0f);
   RectF   layoutRect_C(335.0f, 20.0f, 165.0f, 130.0f);

   // Three different ranges of character positions within the string
   CharacterRange charRanges[3] = { CharacterRange(3, 5),
                                    CharacterRange(15, 2),
                                    CharacterRange(30, 15), };

   // Font and string format to apply to string when drawing
   Font         myFont(L"Times New Roman", 16.0f);
   StringFormat strFormat;

    // Other variables
   Region* pCharRangeRegions; // pointer to CharacterRange regions
   short   i;                 // loop counter
   INT     count;             // number of character ranges set
   WCHAR   string[] = L"The quick, brown fox easily jumps over the lazy dog.";

   // Set three ranges of character positions.
   strFormat.SetMeasurableCharacterRanges(3, charRanges);

   // Get the number of ranges that have been set, and allocate memory to
   // store the regions that correspond to the ranges.
   count = strFormat.GetMeasurableCharacterRangeCount();
   pCharRangeRegions = new Region[count];

   // Get the regions that correspond to the ranges within the string when
   // layout rectangle A is used. Then draw the string, and show the regions.
   graphics.MeasureCharacterRanges(string, -1,
      &myFont, layoutRect_A, &strFormat, count, pCharRangeRegions);
   graphics.DrawString(string, -1,
      &myFont, layoutRect_A, &strFormat, &blueBrush);
   graphics.DrawRectangle(&blackPen, layoutRect_A);
   for ( i = 0; i < count; i++)
   {
      graphics.FillRegion(&redBrush, pCharRangeRegions + i);
   }

   // Get the regions that correspond to the ranges within the string when
   // layout rectangle B is used. Then draw the string, and show the regions.
   graphics.MeasureCharacterRanges(string, -1,
      &myFont, layoutRect_B, &strFormat, count, pCharRangeRegions);
   graphics.DrawString(string, -1,
      &myFont, layoutRect_B, &strFormat, &blueBrush);
   graphics.DrawRectangle(&blackPen, layoutRect_B);
   for ( i = 0; i < count; i++)
   {
      graphics.FillRegion(&redBrush, pCharRangeRegions + i);
   }

   // Get the regions that correspond to the ranges within the string when
   // layout rectangle C is used. Set trailing spaces to be included in the
   // regions. Then draw the string, and show the regions.
   strFormat.SetFormatFlags(StringFormatFlagsMeasureTrailingSpaces);
   graphics.MeasureCharacterRanges(string, -1,
      &myFont, layoutRect_C, &strFormat, count, pCharRangeRegions);
   graphics.DrawString(string, -1,
      &myFont, layoutRect_C, &strFormat, &blueBrush);
   graphics.DrawRectangle(&blackPen, layoutRect_C);
   for ( i = 0; i < count; i++)
   {
      graphics.FillRegion(&redBrush, pCharRangeRegions + i);
   }
   // Delete memory for the range regions.
   delete [] pCharRangeRegions;
}
```

## See also

[CharacterRange](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-characterrange)

[GetMeasurableCharacterRangeCount](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nf-gdiplusstringformat-stringformat-getmeasurablecharacterrangecount)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[SetMeasurableCharacterRanges](https://learn.microsoft.com/windows/desktop/api/gdiplusstringformat/nf-gdiplusstringformat-stringformat-setmeasurablecharacterranges)
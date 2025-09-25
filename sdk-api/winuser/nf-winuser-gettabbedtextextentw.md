# GetTabbedTextExtentW function

## Description

The **GetTabbedTextExtent** function computes the width and height of a character string. If the string contains one or more tab characters, the width of the string is based upon the specified tab stops. The **GetTabbedTextExtent** function uses the currently selected font to compute the dimensions of the string.

## Parameters

### `hdc` [in]

A handle to the device context.

### `lpString` [in]

A pointer to a character string.

### `chCount` [in]

The length of the text string. For the ANSI function it is a BYTE count and for the Unicode function it is a WORD count. Note that for the ANSI function, characters in SBCS code pages take one byte each, while most characters in DBCS code pages take two bytes; for the Unicode function, most currently defined Unicode characters (those in the Basic Multilingual Plane (BMP)) are one WORD while Unicode surrogates are two WORDs.

### `nTabPositions` [in]

The number of tab-stop positions in the array pointed to by the *lpnTabStopPositions* parameter.

### `lpnTabStopPositions` [in]

A pointer to an array containing the tab-stop positions, in device units. The tab stops must be sorted in increasing order; the smallest x-value should be the first item in the array.

## Return value

If the function succeeds, the return value is the dimensions of the string in logical units. The height is in the high-order word and the width is in the low-order word.

If the function fails, the return value is 0. **GetTabbedTextExtent** will fail if *hDC* is invalid and if *nTabPositions* is less than 0.

## Remarks

The current clipping region does not affect the width and height returned by the **GetTabbedTextExtent** function.

Because some devices do not place characters in regular cell arrays (that is, they kern the characters), the sum of the extents of the characters in a string may not be equal to the extent of the string.

If the *nTabPositions* parameter is zero and the *lpnTabStopPositions* parameter is **NULL**, tabs are expanded to eight times the average character width.

If *nTabPositions* is 1, the tab stops are separated by the distance specified by the first value in the array to which *lpnTabStopPositions* points.

> [!NOTE]
> The winuser.h header defines GetTabbedTextExtent as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetTextExtentPoint32](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpoint32a)

[TabbedTextOut](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-tabbedtextouta)
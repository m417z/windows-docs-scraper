# GetTextFaceA function

## Description

The **GetTextFace** function retrieves the typeface name of the font that is selected into the specified device context.

## Parameters

### `hdc` [in]

A handle to the device context.

### `c` [in]

The length of the buffer pointed to by *lpFaceName*. For the ANSI function it is a BYTE count and for the Unicode function it is a WORD count. Note that for the ANSI function, characters in SBCS code pages take one byte each, while most characters in DBCS code pages take two bytes; for the Unicode function, most currently defined Unicode characters (those in the Basic Multilingual Plane (BMP)) are one WORD while Unicode surrogates are two WORDs.

### `lpName` [out]

A pointer to the buffer that receives the typeface name. If this parameter is **NULL**, the function returns the number of characters in the name, including the terminating null character.

## Return value

If the function succeeds, the return value is the number of characters copied to the buffer.

If the function fails, the return value is zero.

## Remarks

The typeface name is copied as a null-terminated character string.

If the name is longer than the number of characters specified by the *nCount* parameter, the name is truncated.

> [!NOTE]
> The wingdi.h header defines GetTextFace as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetTextAlign](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextalign)

[GetTextColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextcolor)

[GetTextExtentPoint32](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextextentpoint32a)

[GetTextMetrics](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextmetrics)
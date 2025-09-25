# DrawTextW function

## Description

The **DrawText** function draws formatted text in the specified rectangle. It formats the text according to the specified method (expanding tabs, justifying characters, breaking lines, and so forth).

To specify additional formatting options, use the [DrawTextEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawtextexa) function.

## Parameters

### `hdc` [in]

A handle to the device context.

### `lpchText` [in, out]

A pointer to the string that specifies the text to be drawn. If the *nCount* parameter is -1, the string must be null-terminated.

If *uFormat* includes DT_MODIFYSTRING, the function could add up to four additional characters to this string. The buffer containing the string should be large enough to accommodate these extra characters.

### `cchText` [in]

The length, in characters, of the string. If *nCount* is -1, then the *lpchText* parameter is assumed to be a pointer to a null-terminated string and **DrawText** computes the character count automatically.

### `lprc` [in, out]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the rectangle (in logical coordinates) in which the text is to be formatted.

### `format` [in]

The method of formatting the text. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **DT_BOTTOM** | Justifies the text to the bottom of the rectangle. This value is used only with the DT_SINGLELINE value. |
| **DT_CALCRECT** | Determines the width and height of the rectangle. If there are multiple lines of text, **DrawText** uses the width of the rectangle pointed to by the *lpRect* parameter and extends the base of the rectangle to bound the last line of text. If the largest word is wider than the rectangle, the width is expanded. If the text is less than the width of the rectangle, the width is reduced. If there is only one line of text, **DrawText** modifies the right side of the rectangle so that it bounds the last character in the line. In either case, **DrawText** returns the height of the formatted text but does not draw the text. |
| **DT_CENTER** | Centers text horizontally in the rectangle. |
| **DT_EDITCONTROL** | Duplicates the text-displaying characteristics of a multiline edit control. Specifically, the average character width is calculated in the same manner as for an edit control, and the function does not display a partially visible last line. |
| **DT_END_ELLIPSIS** | For displayed text, if the end of a string does not fit in the rectangle, it is truncated and ellipses are added. If a word that is not at the end of the string goes beyond the limits of the rectangle, it is truncated without ellipses.<br><br>The string is not modified unless the DT_MODIFYSTRING flag is specified.<br><br>Compare with DT_PATH_ELLIPSIS and DT_WORD_ELLIPSIS. |
| **DT_EXPANDTABS** | Expands tab characters. The default number of characters per tab is eight. The DT_WORD_ELLIPSIS, DT_PATH_ELLIPSIS, and DT_END_ELLIPSIS values cannot be used with the DT_EXPANDTABS value. |
| **DT_EXTERNALLEADING** | Includes the font external leading in line height. Normally, external leading is not included in the height of a line of text. |
| **DT_HIDEPREFIX** | Ignores the ampersand (&) prefix character in the text. The letter that follows will not be underlined, but other mnemonic-prefix characters are still processed.<br><br>Example:<br><br>input string: "A&bc&&d"<br><br>normal: "Abc&d"<br><br>DT_HIDEPREFIX: "Abc&d"<br><br>Compare with DT_NOPREFIX and DT_PREFIXONLY. |
| **DT_INTERNAL** | Uses the system font to calculate text metrics. |
| **DT_LEFT** | Aligns text to the left. |
| **DT_MODIFYSTRING** | Modifies the specified string to match the displayed text. This value has no effect unless DT_END_ELLIPSIS or DT_PATH_ELLIPSIS is specified. |
| **DT_NOCLIP** | Draws without clipping. **DrawText** is somewhat faster when DT_NOCLIP is used. |
| **DT_NOFULLWIDTHCHARBREAK** | Prevents a line break at a DBCS (double-wide character string), so that the line breaking rule is equivalent to SBCS strings. For example, this can be used in Korean windows, for more readability of icon labels. This value has no effect unless DT_WORDBREAK is specified. |
| **DT_NOPREFIX** | Turns off processing of prefix characters. Normally, **DrawText** interprets the mnemonic-prefix character & as a directive to underscore the character that follows, and the mnemonic-prefix characters && as a directive to print a single &. By specifying DT_NOPREFIX, this processing is turned off. For example,<br><br>Example:<br><br>input string: "A&bc&&d"<br><br>normal: "Abc&d"<br><br>DT_NOPREFIX: "A&bc&&d"<br><br>Compare with DT_HIDEPREFIX and DT_PREFIXONLY. |
| **DT_PATH_ELLIPSIS** | For displayed text, replaces characters in the middle of the string with ellipses so that the result fits in the specified rectangle. If the string contains backslash (\\) characters, DT_PATH_ELLIPSIS preserves as much as possible of the text after the last backslash.<br><br>The string is not modified unless the DT_MODIFYSTRING flag is specified.<br><br>Compare with DT_END_ELLIPSIS and DT_WORD_ELLIPSIS. |
| **DT_PREFIXONLY** | Draws only an underline at the position of the character following the ampersand (&) prefix character. Does not draw any other characters in the string. For example,<br><br>Example:<br><br>input string: "A&bc&&d"n<br><br>normal: "Abc&d"<br><br>DT_PREFIXONLY: " _ "<br><br>Compare with DT_HIDEPREFIX and DT_NOPREFIX. |
| **DT_RIGHT** | Aligns text to the right. |
| **DT_RTLREADING** | Layout in right-to-left reading order for bidirectional text when the font selected into the *hdc* is a Hebrew or Arabic font. The default reading order for all text is left-to-right. |
| **DT_SINGLELINE** | Displays text on a single line only. Carriage returns and line feeds do not break the line. |
| **DT_TABSTOP** | Sets tab stops. Bits 15-8 (high-order byte of the low-order word) of the *uFormat* parameter specify the number of characters for each tab. The default number of characters per tab is eight. The DT_CALCRECT, DT_EXTERNALLEADING, DT_INTERNAL, DT_NOCLIP, and DT_NOPREFIX values cannot be used with the DT_TABSTOP value. |
| **DT_TOP** | Justifies the text to the top of the rectangle. |
| **DT_VCENTER** | Centers text vertically. This value is used only with the DT_SINGLELINE value. |
| **DT_WORDBREAK** | Breaks words. Lines are automatically broken between words if a word would extend past the edge of the rectangle specified by the *lpRect* parameter. A carriage return-line feed sequence also breaks the line.<br><br>If this is not specified, output is on one line. |
| **DT_WORD_ELLIPSIS** | Truncates any word that does not fit in the rectangle and adds ellipses.<br><br>Compare with DT_END_ELLIPSIS and DT_PATH_ELLIPSIS. |

## Return value

If the function succeeds, the return value is the height of the text in logical units. If DT_VCENTER or DT_BOTTOM is specified, the return value is the offset from `lpRect->top` to the bottom of the drawn text

If the function fails, the return value is zero.

## Remarks

The **DrawText** function uses the device context's selected font, text color, and background color to draw the text. Unless the DT_NOCLIP format is used, **DrawText** clips the text so that it does not appear outside the specified rectangle. Note that text with significant overhang may be clipped, for example, an initial "W" in the text string or text that is in italics. All formatting is assumed to have multiple lines unless the DT_SINGLELINE format is specified.

If the selected font is too large for the specified rectangle, the **DrawText** function does not attempt to substitute a smaller font.

The text alignment mode for the device context must include the TA_LEFT, TA_TOP, and TA_NOUPDATECP flags.

> [!NOTE]
> The winuser.h header defines DrawText as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DrawTextEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawtextexa)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GrayString](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-graystringa)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[TabbedTextOut](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-tabbedtextouta)

[TextOut](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-textouta)
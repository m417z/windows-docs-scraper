# CreateFontA function

## Description

The **CreateFont** function creates a logical font with the specified characteristics. The logical font can subsequently be selected as the font for any device.

## Parameters

### `cHeight` [in]

The height, in logical units, of the font's character cell or character. The character height value (also known as the em height) is the character cell height value minus the internal-leading value. The font mapper interprets the value specified in *nHeight* in the following manner.

| Value | Meaning |
| --- | --- |
| > 0 | The font mapper transforms this value into device units and matches it against the cell height of the available fonts. |
| 0 | The font mapper uses a default height value when it searches for a match. |
| < 0 | The font mapper transforms this value into device units and matches its absolute value against the character height of the available fonts. |

For all height comparisons, the font mapper looks for the largest font that does not exceed the requested size.

This mapping occurs when the font is used for the first time.

For the MM_TEXT mapping mode, you can use the following formula to specify a height for a font with a specified point size:

```cpp

nHeight = -MulDiv(PointSize, GetDeviceCaps(hDC, LOGPIXELSY), 72);

```

### `cWidth` [in]

The average width, in logical units, of characters in the requested font. If this value is zero, the font mapper chooses a closest match value. The closest match value is determined by comparing the absolute values of the difference between the current device's aspect ratio and the digitized aspect ratio of available fonts.

### `cEscapement` [in]

The angle, in tenths of degrees, between the escapement vector and the x-axis of the device. The escapement vector is parallel to the base line of a row of text.

When the graphics mode is set to GM_ADVANCED, you can specify the escapement angle of the string independently of the orientation angle of the string's characters.

When the graphics mode is set to GM_COMPATIBLE, *nEscapement* specifies both the escapement and orientation. You should set *nEscapement* and *nOrientation* to the same value.

### `cOrientation` [in]

The angle, in tenths of degrees, between each character's base line and the x-axis of the device.

### `cWeight` [in]

The weight of the font in the range 0 through 1000. For example, 400 is normal and 700 is bold. If this value is zero, a default weight is used.

The following values are defined for convenience.

| Weight | Value |
| --- | --- |
| **FW_DONTCARE** | 0 |
| **FW_THIN** | 100 |
| **FW_EXTRALIGHT** | 200 |
| **FW_ULTRALIGHT** | 200 |
| **FW_LIGHT** | 300 |
| **FW_NORMAL** | 400 |
| **FW_REGULAR** | 400 |
| **FW_MEDIUM** | 500 |
| **FW_SEMIBOLD** | 600 |
| **FW_DEMIBOLD** | 600 |
| **FW_BOLD** | 700 |
| **FW_EXTRABOLD** | 800 |
| **FW_ULTRABOLD** | 800 |
| **FW_HEAVY** | 900 |
| **FW_BLACK** | 900 |

### `bItalic` [in]

Specifies an italic font if set to **TRUE**.

### `bUnderline` [in]

Specifies an underlined font if set to **TRUE**.

### `bStrikeOut` [in]

A strikeout font if set to **TRUE**.

### `iCharSet` [in]

The character set. For a list of possible values, see *lfCharSet* field of the [LOGFONT structure](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta).

Fonts with other character sets may exist in the operating system. If an application uses a font with an unknown character set, it should not attempt to translate or interpret strings that are rendered with that font.

To ensure consistent results when creating a font, do not specify **OEM_CHARSET** or **DEFAULT_CHARSET**. If you specify a typeface name in the *pszFaceName* parameter, make sure that the *iCharSet* value matches the character set of the typeface specified in *pszFaceName*.

### `iOutPrecision` [in]

The output precision. The output precision defines how closely the output must match the requested font's height, width, character orientation, escapement, pitch, and font type. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| **OUT_CHARACTER_PRECIS** | Not used. |
| **OUT_DEFAULT_PRECIS** | The default font mapper behavior. |
| **OUT_DEVICE_PRECIS** | Instructs the font mapper to choose a Device font when the system contains multiple fonts with the same name. |
| **OUT_OUTLINE_PRECIS** | This value instructs the font mapper to choose from TrueType and other outline-based fonts. |
| **OUT_PS_ONLY_PRECIS** | Instructs the font mapper to choose from only PostScript fonts. If there are no PostScript fonts installed in the system, the font mapper returns to default behavior. |
| **OUT_RASTER_PRECIS** | Instructs the font mapper to choose a raster font when the system contains multiple fonts with the same name. |
| **OUT_STRING_PRECIS** | This value is not used by the font mapper, but it is returned when raster fonts are enumerated. |
| **OUT_STROKE_PRECIS** | This value is not used by the font mapper, but it is returned when TrueType, other outline-based fonts, and vector fonts are enumerated. |
| **OUT_TT_ONLY_PRECIS** | Instructs the font mapper to choose from only TrueType fonts. If there are no TrueType fonts installed in the system, the font mapper returns to default behavior. |
| **OUT_TT_PRECIS** | Instructs the font mapper to choose a TrueType font when the system contains multiple fonts with the same name. |

Applications can use the OUT_DEVICE_PRECIS, OUT_RASTER_PRECIS, OUT_TT_PRECIS, and OUT_PS_ONLY_PRECIS values to control how the font mapper chooses a font when the operating system contains more than one font with a specified name. For example, if an operating system contains a font named Symbol in raster and TrueType form, specifying OUT_TT_PRECIS forces the font mapper to choose the TrueType version. Specifying OUT_TT_ONLY_PRECIS forces the font mapper to choose a TrueType font, even if it must substitute a TrueType font of another name.

### `iClipPrecision` [in]

The clipping precision. The clipping precision defines how to clip characters that are partially outside the clipping region. It can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CLIP_CHARACTER_PRECIS** | Not used. |
| **CLIP_DEFAULT_PRECIS** | Specifies default clipping behavior. |
| **CLIP_DFA_DISABLE** | Windows XP SP1: Turns off font association for the font. Note that this flag is not guaranteed to have any effect on any platform after Windows Server 2003. |
| **CLIP_EMBEDDED** | You must specify this flag to use an embedded read-only font. |
| **CLIP_LH_ANGLES** | When this value is used, the rotation for all fonts depends on whether the orientation of the coordinate system is left-handed or right-handed.<br><br>If not used, device fonts always rotate counterclockwise, but the rotation of other fonts is dependent on the orientation of the coordinate system.<br><br>For more information about the orientation of coordinate systems, see the description of the *nOrientation* parameter |
| **CLIP_MASK** | Not used. |
| **CLIP_DFA_OVERRIDE** | Turns off font association for the font. This is identical to CLIP_DFA_DISABLE, but it can have problems in some situations; the recommended flag to use is CLIP_DFA_DISABLE. |
| **CLIP_STROKE_PRECIS** | Not used by the font mapper, but is returned when raster, vector, or TrueType fonts are enumerated.<br><br>For compatibility, this value is always returned when enumerating fonts. |
| **CLIP_TT_ALWAYS** | Not used. |

### `iQuality` [in]

The output quality. The output quality defines how carefully GDI must attempt to match the logical-font attributes to those of an actual physical font. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ANTIALIASED_QUALITY** | Font is antialiased, or smoothed, if the font supports it and the size of the font is not too small or too large. |
| **CLEARTYPE_QUALITY** | If set, text is rendered (when possible) using ClearType antialiasing method. See Remarks for more information. |
| **DEFAULT_QUALITY** | Appearance of the font does not matter. |
| **DRAFT_QUALITY** | Appearance of the font is less important than when the PROOF_QUALITY value is used. For GDI raster fonts, scaling is enabled, which means that more font sizes are available, but the quality may be lower. Bold, italic, underline, and strikeout fonts are synthesized, if necessary. |
| **NONANTIALIASED_QUALITY** | Font is never antialiased, that is, font smoothing is not done. |
| **PROOF_QUALITY** | Character quality of the font is more important than exact matching of the logical-font attributes. For GDI raster fonts, scaling is disabled and the font closest in size is chosen. Although the chosen font size may not be mapped exactly when PROOF_QUALITY is used, the quality of the font is high and there is no distortion of appearance. Bold, italic, underline, and strikeout fonts are synthesized, if necessary. |

If the output quality is DEFAULT_QUALITY, DRAFT_QUALITY, or PROOF_QUALITY, then the font is antialiased if the SPI_GETFONTSMOOTHING system parameter is **TRUE**. Users can control this system parameter from the Control Panel. (The precise wording of the setting in the Control panel depends on the version of Windows, but it will be words to the effect of "Smooth edges of screen fonts".)

### `iPitchAndFamily` [in]

The pitch and family of the font. The two low-order bits specify the pitch of the font and can be one of the following values:

* DEFAULT_PITCH
* FIXED_PITCH
* VARIABLE_PITCH

The four high-order bits specify the font family and can be one of the following values.

| Value | Meaning |
| --- | --- |
| **FF_DECORATIVE** | Novelty fonts. Old English is an example. |
| **FF_DONTCARE** | Use default font. |
| **FF_MODERN** | Fonts with constant stroke width, with or without serifs. Pica, Elite, and Courier New are examples. |
| **FF_ROMAN** | Fonts with variable stroke width and with serifs. MS Serif is an example. |
| **FF_SCRIPT** | Fonts designed to look like handwriting. Script and Cursive are examples. |
| **FF_SWISS** | Fonts with variable stroke width and without serifs. MS?Sans Serif is an example. |

An application can specify a value for the *fdwPitchAndFamily* parameter by using the Boolean OR operator to join a pitch constant with a family constant.

Font families describe the look of a font in a general way. They are intended for specifying fonts when the exact typeface requested is not available.

### `pszFaceName` [in]

A pointer to a null-terminated string that specifies the typeface name of the font. The length of this string must not exceed 32 characters, including the terminating null character. The [EnumFontFamilies](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesa) function can be used to enumerate the typeface names of all currently available fonts. For more information, see the Remarks.

If *pszFaceName* is **NULL** or empty string, GDI uses the first font that matches the other specified attributes.

## Return value

If the function succeeds, the return value is a handle to a logical font.

If the function fails, the return value is **NULL**.

## Remarks

When you no longer need the font, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

To help protect the copyrights of vendors who provide fonts for Windows, applications should always report the exact name of a selected font. Because available fonts can vary from system to system, do not assume that the selected font is always the same as the requested font. For example, if you request a font named Palatino, but no such font is available on the system, the font mapper will substitute a font that has similar attributes but a different name. Always report the name of the selected font to the user.

To get the appropriate font on different language versions of the OS, call [EnumFontFamiliesEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesexa) with the desired font characteristics in the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure, then retrieve the appropriate typeface name and create the font using **CreateFont** or [CreateFontIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfontindirecta).

The font mapper for **CreateFont**,[CreateFontIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfontindirecta), and [CreateFontIndirectEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfontindirectexa) recognizes both the English and the localized typeface name, regardless of locale.

The following situations do not support ClearType antialiasing:

* Text rendered on a printer.
* A display set for 256 colors or less.
* Text rendered to a terminal server client.
* The font is not a TrueType font or an OpenType font with TrueType outlines. For example, the following do not support ClearType antialiasing: Type 1 fonts, Postscript OpenType fonts without TrueType outlines, bitmap fonts, vector fonts, and device fonts.
* The font has tuned embedded bitmaps, only for the font sizes that contain the embedded bitmaps. For example, this occurs commonly in East Asian fonts.

#### Examples

```cpp
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int wmId, wmEvent;
    PAINTSTRUCT ps;
    HDC hdc;
    switch (message)
    {

    case WM_PAINT:
        {
        RECT rect;
        HFONT hFontOriginal, hFont1, hFont2, hFont3;
        hdc = BeginPaint(hWnd, &ps);

            //Logical units are device dependent pixels, so this will create a handle to a logical font that is 48 pixels in height.
            //The width, when set to 0, will cause the font mapper to choose the closest matching value.
            //The font face name will be Impact.
            hFont1 = CreateFont(48,0,0,0,FW_DONTCARE,FALSE,TRUE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY, VARIABLE_PITCH,TEXT("Impact"));
            hFontOriginal = (HFONT)SelectObject(hdc, hFont1);

            //Sets the coordinates for the rectangle in which the text is to be formatted.
            SetRect(&rect, 100,100,700,200);
            SetTextColor(hdc, RGB(255,0,0));
            DrawText(hdc, TEXT("Drawing Text with Impact"), -1,&rect, DT_NOCLIP);

            //Logical units are device dependent pixels, so this will create a handle to a logical font that is 36 pixels in height.
            //The width, when set to 20, will cause the font mapper to choose a font which, in this case, is stretched.
            //The font face name will be Times New Roman.  This time nEscapement is at -300 tenths of a degree (-30 degrees)
            hFont2 = CreateFont(36,20,-300,0,FW_DONTCARE,FALSE,TRUE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY, VARIABLE_PITCH,TEXT("Times New Roman"));
            SelectObject(hdc,hFont2);

            //Sets the coordinates for the rectangle in which the text is to be formatted.
            SetRect(&rect, 100, 200, 900, 800);
            SetTextColor(hdc, RGB(0,128,0));
            DrawText(hdc, TEXT("Drawing Text with Times New Roman"), -1,&rect, DT_NOCLIP);

            //Logical units are device dependent pixels, so this will create a handle to a logical font that is 36 pixels in height.
            //The width, when set to 10, will cause the font mapper to choose a font which, in this case, is compressed.
            //The font face name will be Arial. This time nEscapement is at 250 tenths of a degree (25 degrees)
            hFont3 = CreateFont(36,10,250,0,FW_DONTCARE,FALSE,TRUE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS,ANTIALIASED_QUALITY, VARIABLE_PITCH,TEXT("Arial"));
            SelectObject(hdc,hFont3);

            //Sets the coordinates for the rectangle in which the text is to be formatted.
            SetRect(&rect, 500, 200, 1400, 600);
            SetTextColor(hdc, RGB(0,0,255));
            DrawText(hdc, TEXT("Drawing Text with Arial"), -1,&rect, DT_NOCLIP);

            SelectObject(hdc,hFontOriginal);
            DeleteObject(hFont1);
            DeleteObject(hFont2);
            DeleteObject(hFont3);

        EndPaint(hWnd, &ps);
        break;
        }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

```

For another example, see "Setting Fonts for Menu-Item Text Strings" in [Using Menus](https://learn.microsoft.com/windows/desktop/menurc/using-menus).

> [!NOTE]
> The wingdi.h header defines CreateFont as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateFontIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfontindirecta)

[CreateFontIndirectEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfontindirectexa)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

**EnumFontFamilies**

[EnumFontFamiliesEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontfamiliesexa)

[EnumFonts](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumfontsa)

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)
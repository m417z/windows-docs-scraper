# CHARFORMAT2A structure overview

## Description

Contains information about character formatting in a rich edit control. **CHARFORMAT2** is a Microsoft Rich Edit 2.0 extension of the [CHARFORMAT](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charformata) structure. Microsoft Rich Edit 2.0 allows you to use either structure with the [EM_GETCHARFORMAT](https://learn.microsoft.com/windows/win32/controls/em-getcharformat) and [EM_SETCHARFORMAT](https://learn.microsoft.com/windows/win32/controls/em-setcharformat) messages.

## Members

### `wWeight`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Font weight. This member is the same as the **lfWeight** member of the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure. To use this member, set the **CFM_WEIGHT** flag in the **dwMask** member.

### `sSpacing`

Type: **[SHORT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Horizontal space between letters, in twips. This value has no effect on the text displayed by a rich edit control; it is included for compatibility with Windows TOM interfaces. To use this member, set the **CFM_SPACING** flag in the **dwMask** member.

### `crBackColor`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Background color. To use this member, set the **CFM_BACKCOLOR** flag in the **dwMask** member. This member is ignored if the **CFE_AUTOBACKCOLOR** character effect is specified. To generate a , use the macro.

### `lcid`

Type: **[LCID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A 32-bit locale identifier that contains a language identifier in the lower word and a sorting identifier and reserved value in the upper word. This member has no effect on the text displayed by a rich edit control, but spelling and grammar checkers can use it to deal with language-dependent problems. You can use the macro to create an **LCID** value. To use this member, set the **CFM_LCID** flag in the **dwMask** member.

### `dwCookie`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Client cookie. This member is opaque to a rich edit control.

### `dwReserved`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Reserved; the value must be zero.

### `sStyle`

Type: **[SHORT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Character style handle. This value has no effect on the text displayed by a rich edit control; it is included for compatibility with WindowsTOM interfaces. To use this member, set the **CFM_STYLE** flag in the **dwMask** member. For more information see the TOM documentation.

### `wKerning`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value of the font size, above which to kern the character (**yHeight**). This value has no effect on the text displayed by a rich edit control; it is included for compatibility with TOM interfaces. To use this member, set the **CFM_KERNING** flag in the **dwMask** member.

### `bUnderlineType`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the underline type. To use this member, set the **CFM_UNDERLINETYPE** flag in the **dwMask** member. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CFU_CF1UNDERLINE** | The structure maps [CHARFORMAT](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charformata)'s bit underline to **CHARFORMAT2**, (that is, it performs a **CHARFORMAT** type of underline on this text). |
| **CFU_INVERT** | For IME composition, fake a selection. |
| **CFU_UNDERLINE** | Text underlined with a single solid line. |
| **CFU_UNDERLINEDASH** | Text underlined with dashes. |
| **CFU_UNDERLINEDASHDOT** | Text underlined with a dashed and dotted line. |
| **CFU_UNDERLINEDASHDOTDOT** | Text underlined with a dashed and doubled dotted line. |
| **CFU_UNDERLINEDOTTED** | Text underlined with a dotted line. For versions earlier than Microsoft Rich Edit 3.0, text is displayed with a solid underline. |
| **CFU_UNDERLINEDOUBLE** | Text underlined with a double line. The rich edit control displays the text with a solid underline. |
| **CFU_UNDERLINEDOUBLEWAVE** | Display as **CFU_UNDERLINEWAVE**. |
| **CFU_UNDERLINEHAIRLINE** | Display as **CFU_UNDERLINE**. |
| **CFU_UNDERLINEHEAVYWAVE** | Display as **CFU_UNDERLINEWAVE**. |
| **CFU_UNDERLINELONGDASH** | Display as **CFU_UNDERLINEDASH**. |
| **CFU_UNDERLINENONE** | No underline. This is the default. |
| **CFU_UNDERLINETHICK** | Display as **CFU_UNDERLINE**. |
| **CFU_UNDERLINETHICKDASH** | Display as **CFU_UNDERLINEDASH**. |
| **CFU_UNDERLINETHICKDASHDOT** | Display as **CFU_UNDERLINEDASHDOT**. |
| **CFU_UNDERLINETHICKDASHDOTDOT** | Display as **CFU_UNDERLINEDASHDOT**. |
| **CFU_UNDERLINETHICKDOTTED** | Display as **CFU_UNDERLINEDOT**. |
| **CFU_UNDERLINETHICKLONGDASH** | Display as **CFU_UNDERLINEDASH**. |
| **CFU_UNDERLINEWAVE** | **RichEdit 4.1 and later**: Text underlined with a wavy line. |
| **CFU_UNDERLINEWORD** | **RichEdit 4.1 and later**: Underline words only. The rich edit control displays the text with a solid underline. |

### `bAnimation`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Text animation type. This value has no effect on the text displayed by a rich edit control; it is included for compatibility with TOM interfaces. To use this member, set the **CFM_ANIMATION** flag in the **dwMask** member.

### `bRevAuthor`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An index that identifies the author making a revision. The rich edit control uses different text colors for each different author index. To use this member, set the **CFM_REVAUTHOR** flag in the **dwMask** member.

### `bUnderlineColor`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Underline color:

* UnderlineColor_Black = 0x00;
* UnderlineColor_Blue = 0x01;
* UnderlineColor_Aqua = 0x02;
* UnderlineColor_Lime = 0x03;
* UnderlineColor_Fuchsia = 0x04;
* UnderlineColor_Red = 0x05;
* UnderlineColor_Yellow = 0x06;
* UnderlineColor_White = 0x07;
* UnderlineColor_Navy = 0x08;
* UnderlineColor_Teal = 0x09;
* UnderlineColor_Green = 0x0A;
* UnderlineColor_Purple = 0x0B;
* UnderlineColor_Maroon = 0x0C;
* UnderlineColor_Olive = 0x0D;
* UnderlineColor_DkGray = 0x0E;
* UnderlineColor_LtGray = 0x0F;

### `_charformat`

### `bCharSet`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Character set value. It can be one of the values specified for the **lfCharSet** member of the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure. To use this member, set the **CFM_CHARSET** flag in the **dwMask** member.

### `bPitchAndFamily`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the font family and pitch. This member is the same as the **lfPitchAndFamily** member of the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure.

### `cbSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the size, in bytes, of the structure. Before passing this structure to a rich edit control, set **cbSize** to the size of the [CHARFORMAT](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charformata) or **CHARFORMAT2** structure. If **cbSize** equals the size of a **CHARFORMAT** structure, the control uses only the **CHARFORMAT** members.

### `crTextColor`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Text color. To use this member, set the **CFM_COLOR** flag in the **dwMask** member. This member is ignored if the **CFE_AUTOCOLOR** character effect is specified. To generate a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref), use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

### `dwEffects`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A set of bit flags that specify character effects. Some of the flags are included only for compatibility with Microsoft [Text Object Model](https://learn.microsoft.com/windows/win32/controls/text-object-model) (TOM) interfaces; the rich edit control stores the value but does not use it to display text.

This member can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **CFE_ALLCAPS** | Characters are all capital letters. The value does not affect the way the control displays the text. This value applies only to versions earlier than Microsoft Rich Edit 3.0. |
| **CFE_AUTOBACKCOLOR** | The background color is the return value of [GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor)(**COLOR_WINDOW**). If this flag is set, **crBackColor** member is ignored. |
| **CFE_AUTOCOLOR** | The text color is the return value of [GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor)(**COLOR_WINDOWTEXT**). If this flag is set, the **crTextColor** member is ignored. |
| **CFE_BOLD** | Characters are bold. |
| **CFE_DISABLED** | Characters are displayed with a shadow that is offset by 3/4 point or one pixel, whichever is larger. |
| **CFE_EMBOSS** | Characters are embossed. The value does not affect how the control displays the text. |
| **CFE_EXTENDED** | The characters are less common members of a script. A font that supports a script should check if it has glyphs for such characters. |
| **CFE_FONTBOUND** | Font is chosen by the rich edit control because the active font doesn't support the characters. This process is called font binding. |
| **CFE_HIDDEN** | For Microsoft Rich Edit 3.0 and later, characters are not displayed. |
| **CFE_IMPRINT** | Characters are displayed as imprinted characters. The value does not affect how the control displays the text. |
| **CFE_ITALIC** | Characters are italic. |
| **CFE_LINK** | A rich edit control can send [EN_LINK](https://learn.microsoft.com/windows/win32/controls/en-link) notification codes when it receives mouse messages while the mouse pointer is over text with the **CFE_LINK** effect. |
| **CFE_LINKPROTECTED** | Characters are part of a friendly name link. |
| **CFE_MATH** | Characters are in a math zone. |
| **CFE_MATHNOBUILDUP** | Characters do not participate in a math build up. For example, when applied to a /, the / will not be used to build up a fraction. |
| **CFE_MATHORDINARY** | Characters are displayed as ordinary text within a math zone. |
| **CFE_OUTLINE** | Characters are displayed as outlined characters. The value does not affect how the control displays the text. |
| **CFE_PROTECTED** | Characters are protected; an attempt to modify them will cause an [EN_PROTECTED](https://learn.microsoft.com/windows/win32/controls/en-protected) notification code. |
| **CFE_REVISED** | Characters are marked as revised. |
| **CFE_SHADOW** | Characters are displayed as shadowed characters. The value does not affect how the control displays the text. |
| **CFE_SMALLCAPS** | Characters are in small capital letters. The value does not affect how the control displays the text. |
| **CFE_STRIKEOUT** | Characters are struck out. |
| **CFE_SUBSCRIPT** | Characters are subscript. The **CFE_SUPERSCRIPT** and **CFE_SUBSCRIPT** values are mutually exclusive. For both values, the control automatically calculates an offset and a smaller font size. Alternatively, you can use the **yHeight** and **yOffset** members to explicitly specify font size and offset for subscript and superscript characters. |
| **CFE_SUPERSCRIPT** | Characters are superscript. |
| **CFE_UNDERLINE** | Characters are underlined. |

### `dwMask`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the parts of the **CHARFORMAT2** structure that contain valid information. The
**dwMask** member can be a combination of the values from two sets of bit flags. One set indicates the structure members that are valid. Another set indicates the valid attributes in the
**dwEffects** member.

Set the following values to indicate the valid attributes of the **dwEffects** member.

| Value | Meaning |
| --- | --- |
| **CFM_ALL** | A combination of the following values: **CFM_EFFECTS** | **CFM_SIZE** | **CFM_FACE** | **CFM_OFFSET** | **CFM_CHARSET** |
| **CFM_ALL2** | A combination of the following values: **CFM_ALL** | **CFM_EFFECTS2** | **CFM_BACKCOLOR** | **CFM_LCID** | **CFM_UNDERLINETYPE** | **CFM_WEIGHT** | **CFM_REVAUTHOR** | **CFM_SPACING** | **CFM_KERNING** | **CFM_STYLE** | **CFM_ANIMATION** | **CFM_COOKIE** |
| **CFM_ALLCAPS** | The **CFE_ALLCAPS** value is valid. |
| **CFM_EFFECTS** | A combination of the following values: **CFM_EFFECTS2** | **CFM_FONTBOUND** | **CFM_EXTENDED** | **CFM_MATHNOBUILDUP** | **CFM_MATH** | **CFM_MATHORDINARY** |
| **CFM_BOLD** | The **CFE_BOLD** value is valid. |
| **CFM_COLOR** | The **CFE_AUTOCOLOR** value is valid, or the **crTextColor** member is valid. |
| **CFM_COOKIE** | The **dwCookie** value is valid. |
| **CFM_DISABLED** | The **CFE_DISABLED** value is valid. |
| **CFM_EXTENDED** | The **CFE_EXTENDED** value is valid. |
| **CFM_EFFECTS** | A combination of the following values: **CFM_BOLD** | **CFM_ITALIC** | **CFM_UNDERLINE** | **CFM_COLOR** | **CFM_STRIKEOUT** | **CFE_PROTECTED** | **CFM_LINK** |
| **CFM_EFFECTS2** | A combination of the following values: **CFM_EFFECTS** | **CFM_DISABLED** | **CFM_SMALLCAPS** | **CFM_ALLCAPS** | **CFM_HIDDEN** | **CFM_OUTLINE** | **CFM_SHADOW** | **CFM_EMBOSS** | **CFM_IMPRINT** | **CFM_REVISED** | **CFM_SUBSCRIPT** | **CFM_SUPERSCRIPT** | **CFM_BACKCOLOR** |
| **CFM_EMBOSS** | The **CFE_EMBOSS** value is valid. |
| **CFM_FONTBOUND** | The **CFE_FONTBOUND** value is valid. |
| **CFM_HIDDEN** | The **CFE_HIDDEN** value is valid. |
| **CFM_IMPRINT** | The **CFE_IMPRINT** value is valid. |
| **CFM_ITALIC** | The **CFE_ITALIC** value is valid. |
| **CFM_LINK** | The **CFE_LINK** value is valid. |
| **CFM_LINKPROTECTED** | The **CFE_LINKPROTECTED** value is valid. |
| **CFM_MATH** | The **CFE_MATH** value is valid. |
| **CFM_MATHNOBUILDUP** | The **CFE_MATHNOBUILDUP** value is valid. |
| **CFM_MATHORDINARY** | The **CFE_MATHORDINARY** value is valid. |
| **CFM_OUTLINE** | The **CFE_OUTLINE** value is valid. |
| **CFM_PROTECTED** | The **CFE_PROTECTED** value is valid. |
| **CFM_REVISED** | The **CFE_REVISION** value is valid. |
| **CFM_SHADOW** | The **CFE_SHADOW** value is valid. |
| **CFM_SMALLCAPS** | The **CFE_SMALLCAPS** value is valid. |
| **CFM_STRIKEOUT** | The **CFE_STRIKEOUT** value is valid. |
| **CFM_SUBSCRIPT** | The **CFE_SUBSCRIPT** and **CFE_SUPERSCRIPT** values are valid. |
| **CFM_SUPERSCRIPT** | The **CFE_SUBSCRIPT** and **CFE_SUPERSCRIPT** values are valid. |
| **CFM_UNDERLINE** | The **CFE_UNDERLINE** value is valid. |

Set the following values to indicate the valid structure members.

| Value | Meaning |
| --- | --- |
| **CFM_ANIMATION** | The **bAnimation** member is valid. |
| **CFM_BACKCOLOR** | The **crBackColor** member is valid. |
| **CFM_CHARSET** | The **bCharSet** member is valid. |
| **CFM_COLOR** | The **crTextColor** member is valid unless the **CFE_AUTOCOLOR** flag is set in the **dwEffects** member. |
| **CFM_FACE** | The **szFaceName** member is valid. |
| **CFM_KERNING** | The **wKerning** member is valid. |
| **CFM_LCID** | The **lcid** member is valid. |
| **CFM_OFFSET** | The **yOffset** member is valid. |
| **CFM_REVAUTHOR** | The **bRevAuthor** member is valid. |
| **CFM_SIZE** | The **yHeight** member is valid. |
| **CFM_SPACING** | The **sSpacing** member is valid. |
| **CFM_STYLE** | The **sStyle** member is valid. |
| **CFM_UNDERLINETYPE** | The **bUnderlineType** member is valid. |
| **CFM_WEIGHT** | The **wWeight** member is valid. |

### `szFaceName`

Type: **[TCHAR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)[LF_FACESIZE]**

A null-terminated character array specifying the font name. To use this member, set the **CFM_FACE** flag in the **dwMask** member.

### `yHeight`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the character height, in twips (1/1440 of an inch, or 1/20 of a printer's point). To use this member, set the **CFM_SIZE** flag in the **dwMask** member.

### `yOffset`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Character offset from the baseline, in twips. If the value of this member is positive, the character is a superscript; if the value is negative, the character is a subscript. To use this member, set the **CFM_OFFSET** flag in the **dwMask** member.

## Remarks

To turn off a formatting attribute, set the appropriate value in **dwMask** but do not set the corresponding value in **dwEffects**. For example, to turn off italics, set **CFM_ITALIC** but do not set **CFE_ITALIC**.

> [!NOTE]
> The richedit.h header defines CHARFORMAT2 as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CHARFORMAT](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charformata)

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[EM_GETCHARFORMAT](https://learn.microsoft.com/windows/win32/controls/em-getcharformat)

[EM_SETCHARFORMAT](https://learn.microsoft.com/windows/win32/controls/em-setcharformat)

[EN_PROTECTED](https://learn.microsoft.com/windows/win32/controls/en-protected)

[GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor)

[LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)
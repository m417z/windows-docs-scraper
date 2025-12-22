# CHARFORMATW structure

## Description

Contains information about character formatting in a rich edit control.

**Rich Edit 2.0:** The [CHARFORMAT2](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charformat2a) structure is a Microsoft Rich Edit 2.0 extension of the **CHARFORMAT** structure. Microsoft Rich Edit 2.0 and later allows you to use either structure with the [EM_GETCHARFORMAT](https://learn.microsoft.com/windows/win32/controls/em-getcharformat) and [EM_SETCHARFORMAT](https://learn.microsoft.com/windows/win32/controls/em-setcharformat) messages.

## Members

### `cbSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size in bytes of the specified structure. This member must be set before passing the structure to the rich edit control.

### `dwMask`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Members containing valid information or attributes to set. This member can be zero, one, or more than one of the following values.

| Value | Meaning |
| --- | --- |
| **CFM_ALL** | **Windows 8**: A combination of the following values: CFM_EFFECTS \| CFM_SIZE \| CFM_FACE \| CFM_OFFSET \| CFM_CHARSET |
| **CFM_BOLD** | The CFE_BOLD value of the **dwEffects** member is valid. |
| **CFM_CHARSET** | The **bCharSet** member is valid. |
| **CFM_COLOR** | The **crTextColor** member and the CFE_AUTOCOLOR value of the **dwEffects** member are valid. |
| **CFM_EFFECTS** | **Windows 8**: A combination of the following values: CFM_BOLD \| CFM_ITALIC \| CFM_UNDERLINE \| CFM_COLOR \| CFM_STRIKEOUT \| CFE_PROTECTED \| CFM_LINK |
| **CFM_FACE** | The **szFaceName** member is valid. |
| **CFM_ITALIC** | The CFE_ITALIC value of the **dwEffects** member is valid. |
| **CFM_OFFSET** | The **yOffset** member is valid. |
| **CFM_PROTECTED** | The CFE_PROTECTED value of the **dwEffects** member is valid. |
| **CFM_SIZE** | The **yHeight** member is valid. |
| **CFM_STRIKEOUT** | The CFE_STRIKEOUT value of the **dwEffects** member is valid. |
| **CFM_UNDERLINE** | The CFE_UNDERLINE value of the **dwEffects** member is valid. |

### `dwEffects`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Character effects. This member can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **CFE_AUTOCOLOR** | The text color is the return value of [GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor)(COLOR_WINDOWTEXT). |
| **CFE_BOLD** | Characters are bold. |
| **CFE_DISABLED** | **RichEdit 2.0 and later:** Characters are displayed with a shadow that is offset by 3/4 point or one pixel, whichever is larger. |
| **CFE_ITALIC** | Characters are italic. |
| **CFE_STRIKEOUT** | Characters are struck. |
| **CFE_UNDERLINE** | Characters are underlined. |
| **CFE_PROTECTED** | Characters are protected; an attempt to modify them will cause an [EN_PROTECTED](https://learn.microsoft.com/windows/win32/controls/en-protected) notification code. |

### `yHeight`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Character height, in twips (1/1440 of an inch or 1/20 of a printer's point).

### `yOffset`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Character offset, in twips, from the baseline. If the value of this member is positive, the character is a superscript; if it is negative, the character is a subscript.

### `crTextColor`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Text color. This member is ignored if the CFE_AUTOCOLOR character effect is specified. To generate a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref), use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

### `bCharSet`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Character set value. The **bCharSet** member can be one of the values specified for the **lfCharSet** member of the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure. Microsoft Rich Edit 3.0 may override this value if it is invalid for the target characters.

### `bPitchAndFamily`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Font family and pitch. This member is the same as the **lfPitchAndFamily** member of the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure.

### `szFaceName`

Type: **[TCHAR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)[LF_FACESIZE]**

Null-terminated character array specifying the font name.

## Remarks

To turn off a formatting attribute, set the appropriate value in **dwMask** but do not set the corresponding value in **dwEffects**. For example, to turn off italics, set CFM_ITALIC but do not set CFE_ITALIC.

> [!NOTE]
> The richedit.h header defines CHARFORMAT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CHARFORMAT2](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-charformat2a)

[EM_GETCHARFORMAT](https://learn.microsoft.com/windows/win32/controls/em-getcharformat)

[EM_SETCHARFORMAT](https://learn.microsoft.com/windows/win32/controls/em-setcharformat)

[EN_PROTECTED](https://learn.microsoft.com/windows/win32/controls/en-protected)

**Reference**
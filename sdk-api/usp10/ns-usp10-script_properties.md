# SCRIPT_PROPERTIES structure

## Description

Contains information about special processing for each script.

## Members

### `langid`

[Language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) for the language associated with the script. When a script is used for many languages, this member represents a default language. For example, Western script is represented by LANG_ENGLISH although it is also used for French, German, and other European languages.

### `fNumeric`

Value indicating if a script contains only digits and the other characters used in writing numbers by the rules of the Unicode bidirectional algorithm. For example, currency symbols, the thousands separator, and the decimal point are classified as numeric when adjacent to or between digits. Possible values for this member are defined in the following table.

| Value | Meaning |
| --- | --- |
| **TRUE** | The script contains only digits and the other characters used in writing numbers by the rules of the Unicode bidirectional algorithm. |
| **FALSE** | The script does not contain only digits and the other characters used in writing numbers by the rules of the Unicode bidirectional algorithm. |

### `fComplex`

Value indicating a complex script for a language that requires special shaping or layout. Possible values are defined in the following table.

| Value | Meaning |
| --- | --- |
| **TRUE** | The script requires special shaping or layout. |
| **FALSE** | The script contains no combining characters and requires no contextual shaping or reordering. |

### `fNeedsWordBreaking`

Value indicating the type of word break placement for a language. Possible values are defined in the following table.

| Value | Meaning |
| --- | --- |
| **TRUE** | The language has word break placement that requires the application to call [ScriptBreak](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptbreak) and that includes character positions marked by the **fWordStop** member in [SCRIPT_LOGATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_logattr). |
| **FALSE** | Word break placement is identified by scanning for characters marked by the **fWhiteSpace** member in [SCRIPT_LOGATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_logattr), or for glyphs marked by the value SCRIPT_JUSTIFY_BLANK or SCRIPT_JUSTIFY_ARABIC_BLANK for the **uJustification** member of [SCRIPT_VISATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_visattr). |

### `fNeedsCaretInfo`

Value indicating if a language, for example, Thai or Indian, restricts caret placement to cluster boundaries. Possible values are defined in the following table. To determine valid caret positions, the application inspects the **fCharStop** value in the logical attributes retrieved by [ScriptBreak](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptbreak), or compares adjacent values in the *pwLogClust* array retrieved by [ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape).

**Note** [ScriptXtoCP](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptxtocp) and [ScriptCPtoX](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptcptox) automatically apply caret placement restrictions.

| Value | Meaning |
| --- | --- |
| **TRUE** | The language restricts caret placement to cluster boundaries. |
| **FALSE** | The language does not restrict caret placement to cluster boundaries. |

### `bCharSet`

Nominal character set associated with the script. During creation of a font suitable for displaying the script, this character set can be used as the value of the **lfCharSet** member of [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta).

For a new script having no character set defined, the application should typically set **bCharSet** to DEFAULT_CHARSET. See the description of member **fAmbiguousCharSet**.

### `fControl`

Value indicating if only control characters are used in the script. Possible values are defined in the following table. Note that every control character does not end up in a [SCRIPT_CONTROL](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_control) structure.

| Value | Meaning |
| --- | --- |
| **TRUE** | Set only control characters in the script. |
| **FALSE** | Do not set only control characters in the script. |

### `fPrivateUseArea`

Value indicating the use of a private use area, a special set of characters that is privately defined for the Unicode range U+E000 through U+F8FF. Possible values are defined in the following table.

| Value | Meaning |
| --- | --- |
| **TRUE** | Use a private use area. |
| **FALSE** | Do not use a private use area. |

### `fNeedsCharacterJustify`

Value indicating the handling of justification for the script by increasing all the spaces between letters, not just the spaces between words. Possible values are defined in the following table. When performing inter-character justification, Uniscribe inserts extra space only after glyphs marked with the SCRIPT_JUSTIFY_CHARACTER value for the **uJustification** member of [SCRIPT_VISATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_visattr).

| Value | Meaning |
| --- | --- |
| **TRUE** | Use character justification. |
| **FALSE** | Do not use character justification. |

### `fInvalidGlyph`

Value indicating if [ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape) generates an invalid glyph for a script to represent invalid sequences. Possible values are defined in the following table. The application can obtain the glyph index of the invalid glyph for a particular font by calling [ScriptGetFontProperties](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptgetfontproperties).

| Value | Meaning |
| --- | --- |
| **TRUE** | Generate an invalid glyph to represent invalid sequences. |
| **FALSE** | Do not generate an invalid glyph to represent invalid sequences. |

### `fInvalidLogAttr`

Value indicating if [ScriptBreak](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptbreak) marks invalid combinations for a script by setting **fInvalid** in the logical attributes buffer. Possible values are defined in the following table.

| Value | Meaning |
| --- | --- |
| **TRUE** | Mark invalid combinations for the script. |
| **FALSE** | Do not mark invalid combinations for the script. |

### `fCDM`

Value indicating if a script contains an item that has been analyzed by [ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize) as including Combining Diacritical Marks (U+0300 through U+36F). Possible values are defined in the following table.

| Value | Meaning |
| --- | --- |
| **TRUE** | The script contains an item that includes combining diacritical marks. |
| **FALSE** | The script does not contain an item that includes combining diacritical marks. |

### `fAmbiguousCharSet`

Value indicating if a script contains characters that are supported by more than one character set. Possible values are defined in the following table.

| Value | Meaning |
| --- | --- |
| **TRUE** | The script contains characters that are supported by more than one character set. In this case, the **bCharSet** member of this structure should be ignored, and the **lfCharSet** member of [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) should be set to DEFAULT_CHARSET. See the Remarks section for more information. |
| **FALSE** | The script does not contain characters that are supported by more than one character set. |

### `fClusterSizeVaries`

Value indicating if a script, such as Arabic, might use contextual shaping that causes a string to increase in size during removal of characters. Possible values are defined in the following table.

| Value | Meaning |
| --- | --- |
| **TRUE** | Use a variable cluster size for contextual shaping. |
| **FALSE** | Do not use a variable cluster size for contextual shaping. |

### `fRejectInvalid`

Value indicating if a script, for example, Thai, should reject invalid sequences that conventionally cause an editor program, such as Notepad, to beep and ignore keystrokes. Possible values are defined in the following table.

| Value | Meaning |
| --- | --- |
| **TRUE** | Reject invalid sequences. |
| **FALSE** | Do not reject invalid sequences. |

## Remarks

This structure is filled by the [ScriptGetProperties](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptgetproperties) function.

Many Uniscribe scripts do not correspond directly to 8-bit character sets. When some of the characters in a script are supported by more than one character set, the **fAmbiguousCharSet** member is set. The application should do further processing to determine the character set to use when requesting a font suitable for the run. For example, it might determine that the run consists of multiple languages and split the run so that a different font is used for each language.

The application uses the following code during initialization to get a pointer to the **SCRIPT_PROPERTIES** array.

```cpp
const SCRIPT_PROPERTIES **ppScriptProperties; // Array of pointers
                                              // to properties
int iMaxScript;
HRESULT hr;

hr = ScriptGetProperties(&ppScriptProperties, &iMaxScript);

```

Then the application can inspect the properties of the script of an item as shown in the next example.

```cpp
hr = ScriptItemize(pwcInChars, cInChars, cMaxItems, psControl, psState, pItems, pcItems);
//...
if (ppScriptProperties[pItems[iItem].a.eScript]->fNeedsCaretInfo)
    {
        // Use ScriptBreak to restrict the caret from entering clusters (for example).
    }

```

## See also

[Language Identifiers](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers)

[SCRIPT_CONTROL](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_control)

[SCRIPT_LOGATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_logattr)

[SCRIPT_VISATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_visattr)

[ScriptBreak](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptbreak)

[ScriptCPtoX](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptcptox)

[ScriptGetFontProperties](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptgetfontproperties)

[ScriptGetProperties](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptgetproperties)

[ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize)

[ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape)

[ScriptXtoCP](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptxtocp)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Structures](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-structures)
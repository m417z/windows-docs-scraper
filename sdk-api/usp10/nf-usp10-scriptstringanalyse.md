# ScriptStringAnalyse function

## Description

Analyzes a plain text string.

## Parameters

### `hdc` [in]

Handle to the device context. If *dwFlags* is set to SSA_GLYPHS, the device context handle is required. If *dwFlags* is set to SSA_BREAK, the device context handle is optional. If the device context handle is provided, the function inspects the current font in the device context. If the current font is a symbolic font, the function treats the character string as a single neutral SCRIPT_UNDEFINED item.

### `pString` [in]

Pointer to the string to analyze. The string must have at least one character. It can be a Unicode string or use the character set from a Windows ANSI [code page](https://learn.microsoft.com/windows/desktop/Intl/code-pages), as specified by the *iCharset* parameter.

### `cString` [in]

Length of the string to analyze. The length is measured in characters for an ANSI string or in wide characters for a Unicode string. The length must be at least 1.

### `cGlyphs` [in]

Size of the glyph buffer, in WORD values. This size is required. The recommended size is `(1.5 * cString + 16)`.

### `iCharset` [in]

Character set descriptor. If the input string is an ANSI string, this descriptor is set to the character set identifier. If the string is a Unicode string, this descriptor is set to -1.

The following character set identifiers are defined:

### `dwFlags` [in]

Flags indicating the analysis that is required. This parameter can have one of the values listed in the following table.

| Value | Meaning |
| --- | --- |
| **SSA_BREAK** | Retrieve break flags, that is, character and word stops. |
| **SSA_CLIP** | Clip the string at *iReqWidth.* |
| **SSA_DZWG** | Provide representation glyphs for control characters. |
| **SSA_FALLBACK** | Use fallback fonts. |
| **SSA_FIT** | Justify the string to *iReqWidth*. |
| **SSA_GCP** | Retrieve missing glyphs and *pwLogClust* with [GetCharacterPlacement](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharacterplacementa) conventions. |
| **SSA_GLYPHS** | Generate glyphs, positions, and attributes. |
| **SSA_HIDEHOTKEY** | Remove the first "&" from displayed string. |
| **SSA_HOTKEY** | Replace "&" with underline on subsequent code point. |
| **SSA_HOTKEYONLY** | Display underline only. The resulting bit pattern might be displayed, using an XOR mask, to toggle the visibility of the hotkey underline without disturbing the text. |
| **SSA_LINK** | Apply East Asian font linking and association to noncomplex text. |
| **SSA_METAFILE** | Write items with [ExtTextOutW](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-exttextouta) calls, not with glyphs. |
| **SSA_PASSWORD** | Duplicate input string containing a single character *cString* times. |
| **SSA_RTL** | Use base embedding level 1. |
| **SSA_TAB** | Expand tabs. |

### `iReqWidth` [in]

Width required for fitting or clipping.

### `psControl` [in, optional]

Pointer to a [SCRIPT_CONTROL](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_control) structure. The application can set this parameter to **NULL** to indicate that all **SCRIPT_CONTROL** members are set to 0.

### `psState` [in, optional]

Pointer to a [SCRIPT_STATE](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_state) structure. The application can set this parameter to **NULL** to indicate that all **SCRIPT_STATE** members are set to 0. The **uBidiLevel** member of **SCRIPT_STATE** is ignored. The value used is derived from the SSA_RTL flag in combination with the layout of the device context.

### `piDx` [in, optional]

Pointer to the requested logical dx array.

### `pTabdef` [in, optional]

Pointer to a [SCRIPT_TABDEF](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_tabdef) structure. This value is only required if *dwFlags* is set to SSA_TAB.

### `pbInClass` [in]

Pointer to a BYTE value that indicates [GetCharacterPlacement](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharacterplacementa) character classifications.

### `pssa` [out]

Pointer to a buffer in which this function retrieves a [SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis) structure. This structure is dynamically allocated on successful return from the function.

## Return value

Returns S_OK if successful. The function returns a nonzero HRESULT value if it does not succeed.

Error returns include:

* E_INVALIDARG. An invalid parameter is found.
* USP_E_SCRIPT_NOT_IN_FONT. SSA_FALLBACK has not been specified, or a standard fallback font is missing.

The function can also return a system error converted to an HRESULT type. An example is an error returned due to lack of memory or a GDI call using the device context.

## Remarks

Use of this function is the first step in handling plain text strings. Such a string has only one font, one style, one size, one color, and so forth. **ScriptStringAnalyse** allocates temporary buffers for item analyses, glyphs, advance widths, and the like. Then it automatically runs [ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize), [ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape), [ScriptPlace](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplace), and [ScriptBreak](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptbreak). The results are available through all the other **ScriptString*** functions.

On successful return from this function, *pssa* indicates a dynamically allocated structure that the application can pass successively to the other **ScriptString*** functions. The application must ultimately free the structure by calling [ScriptStringFree](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptstringfree).

Although the functionality of **ScriptStringAnalyse** can be implemented by direct calls to other functions, use of the function itself drastically reduces the amount of code required in the application for plain text handling.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[SCRIPT_CONTROL](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_control)

[SCRIPT_STATE](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_state)

[SCRIPT_STRING_ANALYSIS](https://learn.microsoft.com/windows/desktop/Intl/script-string-analysis)

[SCRIPT_TABDEF](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_tabdef)

[ScriptBreak](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptbreak)

[ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize)

[ScriptPlace](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplace)

[ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)
# ScriptBreak function

## Description

Retrieves information for determining line breaks.

## Parameters

### `pwcChars` [in]

Pointer to the Unicode characters to process.

### `cChars` [in]

Number of Unicode characters to process.

### `psa` [in]

Pointer to the [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure obtained from an earlier call to [ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize).

### `psla` [out]

Pointer to a buffer in which this function retrieves the character attributes as a [SCRIPT_LOGATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_logattr) structure.

## Return value

Returns 0 if successful. The function returns a nonzero HRESULT value if it does not succeed. The application can test the return value with the **SUCCEEDED** and **FAILED** macros.

## Remarks

See [Displaying Text with Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/displaying-text-with-uniscribe) for a discussion of the context in which this function is normally called.

This function does not require a device context and does not perform glyph shaping.

This function retrieves cursor movement and formatting break positions for an item in an array of [SCRIPT_LOGATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_logattr) structures. To support mixed formatting within a single word correctly, the call to **ScriptBreak** should pass whole items as retrieved by [ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize), and not the finer formatting runs.

The [SCRIPT_LOGATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_logattr) structure identifies valid caret positions and line breaks. The **fCharStop** member specifies a flag that marks cluster boundaries for scripts that are conventionally restricted from moving inside clusters. The same boundaries can also be inferred by inspecting the logical cluster information retrieved by [ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape). However, **ScriptBreak** is considerably faster in implementation and does not require a device context to be prepared.

The flags designated by the **fWordStop**, **fSoftBreak**, and **fWhiteSpace** members of [SCRIPT_LOGATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_logattr) are only available through **ScriptBreak**.

Most shaping engines that identify invalid sequences set the flag indicated by the **fInvalid** member of [SCRIPT_LOGATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_logattr) in **ScriptBreak**. The **fInvalidLogAttr** member of [SCRIPT_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-script_properties) identifies the applicable scripts.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[Displaying Text with Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/displaying-text-with-uniscribe)

[SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis)

[SCRIPT_LOGATTR](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_logattr)

[ScriptItemize](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemize)

[ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)
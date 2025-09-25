# ScriptItemize function

## Description

Breaks a Unicode string into individually shapeable items.

## Parameters

### `pwcInChars` [in]

Pointer to a Unicode string to itemize.

### `cInChars` [in]

Number of characters in *pwcInChars* to itemize.

### `cMaxItems` [in]

Maximum number of [SCRIPT_ITEM](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_item) structures defining items to process.

### `psControl` [in, optional]

Pointer to a [SCRIPT_CONTROL](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_control) structure indicating the type of itemization to perform.

Alternatively, the application can set this parameter to **NULL** if no [SCRIPT_CONTROL](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_control) properties are needed. For more information, see the Remarks section.

### `psState` [in, optional]

Pointer to a [SCRIPT_STATE](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_state) structure indicating the initial bidirectional algorithm state.

Alternatively, the application can set this parameter to **NULL** if the script state is not needed. For more information, see the Remarks section.

### `pItems` [out]

Pointer to a buffer in which the function retrieves [SCRIPT_ITEM](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_item) structures representing the items that have been processed. The buffer should be `(cMaxItems + 1) * sizeof(SCRIPT_ITEM)` bytes in length. It is invalid to call this function with a buffer to hold less than two **SCRIPT_ITEM** structures. The function always adds a terminal item to the item analysis array so that the length of the item with zero-based index "i" is always available as:

`pItems[i+1].iCharPos - pItems[i].iCharPos;`

### `pcItems` [out]

Pointer to the number of [SCRIPT_ITEM](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_item) structures processed.

## Return value

Returns 0 if successful. The function returns a nonzero HRESULT value if it does not succeed.

The function returns E_INVALIDARG if *pwcInChars* is set to **NULL**, *cInChars* is 0, *pItems* is set to **NULL**, or *cMaxItems* < 2.

The function returns E_OUTOFMEMORY if the value of *cMaxItems* is insufficient. As in all error cases, no items are fully processed and no part of the output array contains defined values. If the function returns E_OUTOFMEMORY, the application can call it again with a larger *pItems* buffer.

## Remarks

See [Displaying Text with Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/displaying-text-with-uniscribe) for a discussion of the context in which this function is normally called.

The function delimits items by either a change of shaping engine or a change of direction.

The application can create multiple ranges, or runs that fall entirely within a single item, from each [SCRIPT_ITEM](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_item) structure retrieved by **ScriptItemize**. However, it should not combine multiple items into a single run. Later, when measuring or rendering, the application can call [ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape) for each run and must pass the [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure retrieved by **ScriptItemize** in the [SCRIPT_ITEM](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_item) structure.

If the text handled by an application can include any right-to-left content, the application uses the *psControl* and *psState* parameters in calling **ScriptItemize**. However, the application does not have to do this and can handle bidirectional text itself instead of relying on Uniscribe to do so. The *psControl* and *psState* parameters are useful in some strictly left-to-right scenarios, for example, when the **fLinkStringBefore** member of [SCRIPT_CONTROL](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_control) is not specific to right-to-left scripts. The application sets *psControl* and *psState* to **NULL** to have **ScriptItemize** break the Unicode string purely by character code.

The application can set all parameters to non-**NULL** values to have the function perform a full Unicode bidirectional analysis. To permit a correct Unicode bidirectional analysis, the [SCRIPT_STATE](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_state) structure should be initialized according to the reading order at paragraph start, and **ScriptItemize** should be passed the whole paragraph. In particular, the **uBidiLevel** member should be initialized to 0 for left-to-right and 1 for right-to-left.

The **fRTL** member of [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) is referenced in [SCRIPT_ITEM](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_item) enabled="1". The **fNumeric** member of [SCRIPT_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-script_properties) is retrieved by [ScriptGetProperties](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptgetproperties). These members together provide the same classification as the **lpClass** member of [GCP_RESULTS](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-gcp_resultsa), referenced by *lpResults* in [GetCharacterPlacement](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcharacterplacementa).

European digits U+0030 through U+0039 can be rendered as national digits, as shown in the following table.

| SCRIPT_STATE.fDigitSubstitute | SCRIPT_CONTROL.fContextDigits | Digit shapes displayed for Unicode U+0030 through U+0039 |
| --- | --- | --- |
| **FALSE** | Any | European digits |
| **TRUE** | **FALSE** | As specified in **uDefaultLanguage** member of [SCRIPT_CONTROL](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_control). |
| **TRUE** | **TRUE** | As prior strong text, defaulting to **uDefaultLanguage** member of [SCRIPT_CONTROL](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_control). |

In context digit mode, one of the following actions occurs:

* If the script specified by **uDefaultLanguage** is in the same direction as the output, all digits encountered before the first letters are rendered in the language indicated by **uDefaultLanguage**.
* If the script specified by **uDefaultLanguage** is in the opposite direction from the output, all digits encountered before the first letters are rendered in European digits.

For example, if **uDefaultLanguage** indicates LANG_ARABIC, initial digits are in Arabic-Indic in a right-to-left embedding. However, they are in European digits in a left-to-right embedding.

For more information, see [Digit Shapes](https://learn.microsoft.com/windows/desktop/Intl/digit-shapes).

The Unicode control characters and definitions, and their effects on [SCRIPT_STATE](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_state) members, are provided in the following table. For more information on Unicode control characters, see the [The Unicode Standard](https://www.unicode.org/standard/standard.html).

| Unicode control characters | Meaning | Effect on SCRIPT_STATE |
| --- | --- | --- |
| NADS | Override European digits (NODS) with national digit shapes. | Set **fDigitSubstitute**. |
| NODS | Use nominal digit shapes, otherwise known as European digits. See NADS. | Clear **fDigitSubstitute**. |
| ASS | Activate swapping of symmetric pairs, for example, parentheses. For these characters, left and right are interpreted as opening and closing. This is the default. See ISS. | Clear **fInhibitSymSwap**. |
| ISS | Inhibit swapping of symmetric pairs. See ASS. | Set **fInhibitSymSwap**. |
| AAFS | Activate Arabic form shaping for Arabic presentation forms. See IAFS. | Set **fCharShape**. |
| IAFS | Inhibit Arabic form shaping, that is, ligatures and cursive connections, for Arabic presentation forms. Nominal Arabic characters are not affected. This is the default. See AAFS. | Clear **fCharShape**. |

The **fArabicNumContext** member of [SCRIPT_STATE](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_state) supports the context-sensitive display of numerals in Arabic script text. It indicates if digits are rendered using native Arabic script digit shapes or European digits. At the beginning of a paragraph, this member should normally be initialized to **TRUE** for an Arabic locale, or **FALSE** for any other locale. The function updates the script state it as it processes strong text.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[Displaying Text with Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/displaying-text-with-uniscribe)

[SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis)

[SCRIPT_CONTROL](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_control)

[SCRIPT_ITEM](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_item)

[SCRIPT_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-script_properties)

[SCRIPT_STATE](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_state)

[ScriptItemizeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemizeopentype)

[ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)
# ScriptGetGlyphABCWidth function

## Description

Retrieves the [ABC width](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-glossary) of a given glyph.

## Parameters

### `hdc` [in]

Optional. Handle to the device context. For more information, see [Caching](https://learn.microsoft.com/windows/desktop/Intl/caching).

### `psc` [in, out]

Pointer to a [SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache) structure identifying the script cache.

### `wGlyph` [in]

Glyph to analyze.

### `pABC` [out]

Pointer to the ABC width of the specified glyph.

## Return value

Returns S_OK if the ABC width of the glyph is retrieved. The function returns a nonzero HRESULT value if it does not succeed.

The function returns E_HANDLE if the font or operating system does not support glyph indexes.

## Remarks

This function is limited in its usefulness. For example, it is useful for drawing glyph charts. It should not be used for ordinary complex script text formatting.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)
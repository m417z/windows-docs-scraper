# ScriptGetFontProperties function

## Description

Retrieves information from the font cache on the special glyphs used by a font.

## Parameters

### `hdc` [in]

Optional. Handle to the device context. For more information, see [Caching](https://learn.microsoft.com/windows/desktop/Intl/caching).

### `psc` [in, out]

Pointer to a [SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache) structure identifying the script cache.

### `sfp` [out]

Pointer to a [SCRIPT_FONTPROPERTIES](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-script_fontproperties) structure in which this function retrieves the information from the font cache.

## Return value

Returns 0 if successful. The function returns a nonzero HRESULT value if it does not succeed. The application can test the return value with the **SUCCEEDED** and **FAILED** macros.

## Remarks

The structure retrieved by this function identifies the glyphs that are used for blanks, missing glyphs, invalid combinations, and the smallest kashida.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache)

[SCRIPT_FONTPROPERTIES](https://learn.microsoft.com/windows/desktop/api/usp10/ns-usp10-script_fontproperties)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)
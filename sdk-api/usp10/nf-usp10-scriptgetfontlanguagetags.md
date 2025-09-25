# ScriptGetFontLanguageTags function

## Description

Retrieves a list of language tags that are available for the specified item and are supported by a specified script tag for OpenType processing. The tags comprising the list are retrieved from the font in the specified device context or cache.

## Parameters

### `hdc` [in, optional]

Handle to the device context. For more information, see [Caching](https://learn.microsoft.com/windows/desktop/Intl/caching).

### `psc` [in, out]

Pointer to a [SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache) structure identifying the script cache.

### `psa` [in, optional]

Pointer to a [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure obtained from a previous call to [ScriptItemizeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemizeopentype). This parameter identifies the shaping engine, so that the font language tags for the appropriate font and scripts can be retrieved.

Alternately, the application can set this parameter to **NULL** to retrieve unfiltered results.

### `tagScript` [in]

An [OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag) structure defining the script tag for which the list of associated language tags is requested.

### `cMaxTags` [in]

The length of the array specified by *pLangSysTags*.

### `pLangsysTags` [out]

Pointer to a buffer in which this function retrieves an array of [OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag) structures identifying the language tags matching input criteria.

### `pcTags` [out]

Pointer to the number of elements in the language tag array.

## Return value

Returns 0 if successful. The function returns a nonzero HRESULT value if it does not succeed. The application can test the return value with the **SUCCEEDED** and **FAILED** macros.

If the number of matching tags exceeds *cMaxTags*, the function fails with E_OUTOFMEMORY. The application can try calling again with larger buffers.

## Remarks

While formally declared as a ULONG type, the [OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag) structure contains a 4-byte array that contains four 8-bit ASCII values of space, A-Z, or a-z. For example, the language tags for Romanian, Urdu, and Persian are "ROM ", "URD ", and "FAR ", respectively. Note that each tag ends with a space.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[Caching](https://learn.microsoft.com/windows/desktop/Intl/caching)

[OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag)

[SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis)

[SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache)

[ScriptItemizeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemizeopentype)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)
# ScriptGetFontFeatureTags function

## Description

Retrieves a list of typographic features for the defined writing system for OpenType processing. The typographic feature tags comprising the list are retrieved from the font in the supplied device context or cache.

## Parameters

### `hdc` [in, optional]

Handle to the device context. For more information, see [Caching](https://learn.microsoft.com/windows/desktop/Intl/caching).

### `psc` [in, out]

Pointer to a [SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache) structure identifying the script cache.

### `psa` [in, optional]

Pointer to a [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure obtained from a previous call to [ScriptItemizeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemizeopentype). This parameter identifies the shaping engine, so that the font feature tags for the appropriate font and scripts can be retrieved.

Alternatively, the application can set this parameter to **NULL** to retrieve unfiltered results.

### `tagScript` [in]

An [OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag) structure defining the script tag associated with the specified feature tags.

### `tagLangSys` [in]

An **OPENTYPE_TAG** structure defining the language tag associated with the specified feature tags.

### `cMaxTags` [in]

The length of the array specified by *pFeatureTags*.

### `pFeatureTags` [out]

Pointer to a buffer in which this function retrieves an array of **OPENTYPE_TAG** structures defining the typographic feature tags supported by the font in the device context or cache for the defined writing system.

### `pcTags` [out]

Pointer to the number of elements in the feature tag array.

## Return value

Returns 0 if successful. The function returns a nonzero HRESULT value if it does not succeed. The application can test the return value with the **SUCCEEDED** and **FAILED** macros.

If the number of matching tags exceeds the value of *cMaxTags*, the function fails with E_OUTOFMEMORY. The application can try calling again with larger buffers.

## Remarks

While formally declared as a ULONG type, an [OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag) structure contains a 4-byte array that contains four 8-bit ASCII values of space, A-Z, or a-z. For example, the feature tag for the Ligature feature is "liga".

This function hides script-required or language-required features because the shaping engine controls these features. The application has no control over the shaping engine handling for language-required features. For example, **ScriptGetFontFeatureTags** hides the Arabic script features for initial, medial, and final forms.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[Caching](https://learn.microsoft.com/windows/desktop/Intl/caching)

[OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag)

[SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis)

[SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache)

[ScriptItemizeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemizeopentype)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)
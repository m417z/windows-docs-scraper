# ScriptGetFontScriptTags function

## Description

Retrieves a list of scripts available in the font for OpenType processing. Scripts comprising the list are retrieved from the font located in the supplied device context or from the script shaping engine that processes the font of the current run.

## Parameters

### `hdc` [in, optional]

Handle to the device context. For more information, see [Caching](https://learn.microsoft.com/windows/desktop/Intl/caching).

### `psc` [in, out]

Pointer to a [SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache) structure identifying the script cache.

### `psa` [in, optional]

Pointer to a [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure obtained from a previous call to [ScriptItemizeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemizeopentype). This parameter identifies the shaping engine, so that the appropriate font script tags can be retrieved. The application supplies a non-**NULL** value for this parameter to retrieve script tags appropriate for the current run.

Alternatively, the application can set this parameter to **NULL** to retrieve unfiltered results.

### `cMaxTags` [in]

The length of the array specified by *pScriptTags*.

### `pScriptTags` [out]

Pointer to a buffer in which this function retrieves an array of [OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag) structures defining script tags from the device context or the scripting engine associated with the current run. If the value of the **eScript** member of the [SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis) structure provided in the *psa* parameter has a definite script tag associated with it and the tag is present in the font, *pScriptTags* contains only this tag.

### `pcTags` [out]

Pointer to the number of elements in the script tag array indicated by *pScriptTags*.

## Return value

Returns 0 if successful. The function returns a nonzero HRESULT value if it does not succeed. The application can test the return value with the **SUCCEEDED** and **FAILED** macros.

If the number of matching tags exceeds the value of *cMaxTags*, the function fails with E_OUTOFMEMORY. The application can try calling again with larger buffers.

## Remarks

While formally declared as a ULONG type, [OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag) defines a 4-byte array that contains four 8-bit ASCII values of space, A-Z or a-z. For example, the script tags for Latin and Arabic scripts are "latn" and "arab", respectively.

This function retrieves a single tag from a font in the following cases:

* The *psa* value is associated with text for a single complex script.
* The *psa* parameter indicates **NULL** and the font supports a single script.

If **ScriptGetFontScriptTags** retrieves all tags from a font, the tags are usually for neutral items, such as digits. Note that more than one tag might be applicable because some text runs of neutral items are not script-specific.

If a tag corresponding to a particular script is present, a shaping engine might be unable to use the font to shape the given item because the engine lacks a needed item, such as a specific language system or a specific feature.

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[Caching](https://learn.microsoft.com/windows/desktop/Intl/caching)

[OPENTYPE_TAG](https://learn.microsoft.com/windows/desktop/Intl/opentype-tag)

[SCRIPT_ANALYSIS](https://learn.microsoft.com/windows/win32/api/usp10/ns-usp10-script_analysis)

[SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache)

[ScriptItemizeOpenType](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptitemizeopentype)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)
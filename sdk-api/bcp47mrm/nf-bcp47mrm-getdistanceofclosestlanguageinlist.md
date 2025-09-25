## Description

Determines the distance between the specified language tag and the closest match in a list of languages.

## Parameters

### `pszLanguage`

Type: **[PCWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A [BCP-47](https://tools.ietf.org/html/bcp47) language tag that represents the candidate language.

### `pszLanguagesList`

Type: **[PCWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A character delimited list of [BCP-47](https://tools.ietf.org/html/bcp47) language tags to compare to the candidate language. This is typically the list of user languages.

If the *wchListDelimiter* parameter is `L'\0'`, then the *pszLanguagesList* is a double null-terminated list of language tags.
Otherwise, the *pszLanguagesList* is a null-terminated string in which the language tags are separated by the provided delimiter.

### `wchListDelimiter`

Type: **[wchar_t](https://learn.microsoft.com/windows/win32/midl/wchar-t)**

The character used as a delimiter in the language list, or `L'\0'` to indicate that the language list is a double null-terminated list.
The function is slightly more efficient if this parameter is `L'\0'`.

### `pClosestDistance`

Type: **[double](https://learn.microsoft.com/windows/win32/midl/double)**

Receives the distance between the candidate language and the closest language in the list.
The value is in the range 0.0 to 1.0, where 1.0 is an exact match.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)**

If there is no match to any language in the list, the function returns `HRESULT_FROM_WIN32(ERROR_NO_MATCH)`
and a distance of 0.0.

## Remarks

You can use this function for localization to find the closest match to a candidate language in the list of user languages.

## See also

[IsWellFormedTag](https://learn.microsoft.com/windows/win32/api/bcp47mrm/nf-bcp47mrm-iswellformedtag), [BCP-47 language tags](https://tools.ietf.org/html/bcp47)
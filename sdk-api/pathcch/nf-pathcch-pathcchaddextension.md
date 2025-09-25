# PathCchAddExtension function

## Description

Adds a file name extension to a path string.

This function differs from [PathAddExtension](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathaddextensiona) in that it accepts paths with "\\", "\\?\" and "\\?\UNC\" prefixes.

**Note** This function should be used in place of [PathAddExtension](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathaddextensiona) to prevent the possibility of a buffer overrun.

## Parameters

### `pszPath` [in, out]

A pointer to the path string. When this function returns successfully, the buffer contains the string with the appended extension. This value should not be **NULL**.

**Note** If the original string already has a file name extension present, no new extension will be added and the original string will be unchanged.

### `cchPath` [in]

The size of the buffer pointed to by *pszPath*, in characters.

### `pszExt` [in]

A pointer to the file name extension string. This string can be given either with or without a preceding period (".ext" or "ext").

## Return value

This function returns an **HRESULT** code, including the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. Note that this also includes the case of an empty extension, such as a period with no characters following it. In that case, the original string is returned unaltered. |
| **E_INVALIDARG** | This value can be caused by several things, such as the *pszPath* param being set to **NULL**, the *cchPath* being set to 0 or a value greater than **PATHCCH_MAX_CCH**, or the extension string containing illegal characters or otherwise not being a valid extension. |
| **S_FALSE** | The original string already has an extension. |
| **PATHCCH_E_FILENAME_TOO_LONG** | The buffer is too small to hold the returned string. |
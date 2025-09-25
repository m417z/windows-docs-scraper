# PathMatchSpecExW function

## Description

Matches a file name from a path against one or more file name patterns.

## Parameters

### `pszFile` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string that contains the path from which the file name to be matched is taken.

### `pszSpec` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string that contains the file name pattern for which to search. This can be the exact name, or it can contain wildcard characters. If exactly one pattern is specified, set the **PMSF_NORMAL** flag in *dwFlags*. If more than one pattern is specified, separate them with semicolons and set the **PMSF_MULTIPLE** flag.

### `dwFlags` [in]

Type: **DWORD**

Modifies the search condition. The following are valid flags.

#### PMSF_NORMAL (0x00000000)

The *pszSpec* parameter points to a single file name pattern to be matched.

#### PMSF_MULTIPLE (0x00000001)

The *pszSpec* parameter points to a semicolon-delimited list of file name patterns to be matched.

#### PMSF_DONT_STRIP_SPACES (0x00010000)

If **PMSF_NORMAL** is used, don't ignore leading spaces in the string pointed to by *pszSpec*. If **PMSF_MULTIPLE** is used, don't ignore leading spaces in each file type contained in the string pointed to by *pszSpec*. This flag can be combined with **PMSF_NORMAL** and **PMSF_MULTIPLE**.

##### - dwFlags.PMSF_DONT_STRIP_SPACES (0x00010000)

If **PMSF_NORMAL** is used, don't ignore leading spaces in the string pointed to by *pszSpec*. If **PMSF_MULTIPLE** is used, don't ignore leading spaces in each file type contained in the string pointed to by *pszSpec*. This flag can be combined with **PMSF_NORMAL** and **PMSF_MULTIPLE**.

##### - dwFlags.PMSF_MULTIPLE (0x00000001)

The *pszSpec* parameter points to a semicolon-delimited list of file name patterns to be matched.

##### - dwFlags.PMSF_NORMAL (0x00000000)

The *pszSpec* parameter points to a single file name pattern to be matched.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | A file name pattern specified in *pszSpec* matched the file name found in the string pointed to by *pszFile*. |
| **S_FALSE** | No file name pattern specified in *pszSpec* matched the file name found in the string pointed to by *pszFile*. |

## See also

[PathMatchSpec](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathmatchspeca)

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathMatchSpecEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
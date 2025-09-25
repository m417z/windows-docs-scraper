# SHNAMEMAPPINGA structure

## Description

Contains the old and new path names for each file that was moved, copied, or renamed by the [SHFileOperation](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shfileoperationa) function.

## Members

### `pszOldPath`

Type: **LPTSTR**

The address of a character buffer that contains the old path name.

### `pszNewPath`

Type: **LPTSTR**

The address of a character buffer that contains the new path name.

### `cchOldPath`

Type: **int**

The number of characters in **pszOldPath**.

### `cchNewPath`

Type: **int**

The number of characters in **pszNewPath**.

## Remarks

There are two versions of this structure, an ANSI version (SHFILEOPSTRUCTA) and a Unicode version (SHFILEOPSTRUCTW). The Unicode version is identical to the ANSI version, except that wide character strings (**LPCWSTR**) are used in place of ANSI character strings (**LPCSTR**). On Windows 98 and earlier, only the ANSI version is supported. On Microsoft Windows NT 4.0 and later, both the ANSI and Unicode versions of this structure are supported. SHNAMEMAPPINGA and SHNAMEMAPPINGW should never be used directly; the appropriate structure is redefined as **SHNAMEMAPPING** by the precompiler depending on whether the application is compiled for ANSI or Unicode.

> [!NOTE]
> The shellapi.h header defines SHNAMEMAPPING as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SHFILEOPSTRUCT](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-shfileopstructa)
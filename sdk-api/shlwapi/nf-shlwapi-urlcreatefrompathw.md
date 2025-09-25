# UrlCreateFromPathW function

## Description

Converts a Microsoft MS-DOS path to a canonicalized URL.

## Parameters

### `pszPath` [in]

Type: **PCTSTR**

A null-terminated string of maximum length INTERNET_MAX_URL_LENGTH that contains the MS-DOS path.

### `pszUrl` [out]

Type: **PTSTR**

A pointer to a buffer that, when this function returns successfully, receives the URL.

### `pcchUrl` [in, out]

Type: **DWORD***

The number of characters in *pszUrl*.

### `dwFlags`

Type: **DWORD**

Reserved. Set this parameter to **NULL**.

## Return value

Type: **HRESULT**

Returns S_FALSE if *pszPath* is already in URL format. In this case, *pszPath* will simply be copied to *pszUrl*. Otherwise, it returns S_OK if successful or a standard COM error value if not.

## Remarks

**Note** **UrlCreateFromPath** does not support extended paths. These are paths that include the extended-length path prefix "\\?\".

> [!NOTE]
> The shlwapi.h header defines UrlCreateFromPath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
# PathCreateFromUrlW function

## Description

Converts a file URL to a Microsoft MS-DOS path.

## Parameters

### `pszUrl` [in]

Type: **PCTSTR**

A null-terminated string of maximum length INTERNET_MAX_URL_LENGTH that contains the URL.

### `pszPath` [out]

Type: **PTSTR**

A pointer to a buffer that, when this function returns successfully, receives the MS-DOS path. You must set the size of this buffer to MAX_PATH to ensure that it is large enough to hold the returned string.

### `pcchPath` [in, out]

Type: **DWORD***

The number of characters in the *pszPath* buffer.

### `dwFlags`

Type: **DWORD**

Reserved. Set this parameter to **NULL**.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathCreateFromUrl as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
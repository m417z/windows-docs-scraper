# UrlHashA function

## Description

Hashes a URL string.

## Parameters

### `pszUrl` [in]

Type: **PCTSTR**

A null-terminated string of maximum length INTERNET_MAX_URL_LENGTH that contains the URL.

### `pbHash` [out]

Type: **BYTE***

A pointer to a buffer that, when this function returns successfully, receives the hashed array.

### `cbHash`

Type: **DWORD**

The number of elements in the array at *pbHash*. It should be no larger than 256.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To hash a URL into a single byte, set *cbHash* = sizeof(BYTE) and *pbHash* = (LPBYTE)&bHashedValue, where bHashedValue is a one-byte buffer. To hash a URL into a **DWORD**, set *cbHash* = sizeof(DWORD) and *pbHash* = (LPBYTE)&dwHashedValue, where dwHashedValue is a **DWORD** buffer.

> [!NOTE]
> The shlwapi.h header defines UrlHash as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[HashData](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-hashdata)
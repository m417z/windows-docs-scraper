# UrlGetPartW function

## Description

Accepts a URL string and returns a specified part of that URL.

## Parameters

### `pszIn` [in]

Type: **PCTSTR**

A null-terminated string of maximum length INTERNET_MAX_URL_LENGTH that contains the URL.

### `pszOut` [out]

Type: **PTSTR**

A pointer to a buffer that, when this function returns successfully, receives a null-terminated string with the specified part of the URL.

### `pcchOut` [in, out]

Type: **DWORD***

A pointer to a value that, on entry, is set to the number of characters in the *pszOut* buffer. When this function returns successfully, the value depends on whether the function is successful or returns E_POINTER. For other return values, the value of this parameter is meaningless.

### `dwPart`

Type: **DWORD**

The flags that specify which part of the URL to retrieve. It can have one of the following values.

#### URL_PART_HOSTNAME

The host name.

#### URL_PART_PASSWORD

The password.

#### URL_PART_PORT

The port number.

#### URL_PART_QUERY

The query portion of the URL.

#### URL_PART_SCHEME

The URL scheme.

#### URL_PART_USERNAME

The username.

### `dwFlags`

Type: **DWORD**

A flag that can be set to keep the URL scheme, in addition to the part that is specified by *dwPart*.

#### URL_PARTFLAG_KEEPSCHEME

Keep the URL scheme.

##### - dwFlags.URL_PARTFLAG_KEEPSCHEME

Keep the URL scheme.

##### - dwPart.URL_PART_HOSTNAME

The host name.

##### - dwPart.URL_PART_PASSWORD

The password.

##### - dwPart.URL_PART_PORT

The port number.

##### - dwPart.URL_PART_QUERY

The query portion of the URL.

##### - dwPart.URL_PART_SCHEME

The URL scheme.

##### - dwPart.URL_PART_USERNAME

The username.

## Return value

Type: **HRESULT**

Returns S_OK if successful. The value pointed to by *pcchOut* will be set to the number of characters written to the output buffer, excluding the terminating **NULL**. If the buffer was too small, E_POINTER is returned, and the value pointed to by *pcchOut* will be set to the minimum number of characters that the buffer must be able to contain, including the terminating **NULL** character. Otherwise, a COM error value is returned.

## Remarks

> [!NOTE]
> The shlwapi.h header defines UrlGetPart as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
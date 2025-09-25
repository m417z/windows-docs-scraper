# UrlIsW function

## Description

Tests whether a URL is a specified type.

## Parameters

### `pszUrl` [in]

Type: **PCTSTR**

A null-terminated string of maximum length INTERNET_MAX_URL_LENGTH that contains the URL.

### `UrlIs`

Type: **URLIS**

The type of URL to be tested for. This parameter can take one of the following values.

#### URLIS_APPLIABLE

Attempt to determine a valid scheme for the URL.

#### URLIS_DIRECTORY

Does the URL string end with a directory?

#### URLIS_FILEURL

Is the URL a file URL?

#### URLIS_HASQUERY

Does the URL have an appended query string?

#### URLIS_NOHISTORY

Is the URL a URL that is not typically tracked in navigation history?

#### URLIS_OPAQUE

Is the URL [opaque](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-urlisopaquea)?

#### URLIS_URL

Is the URL valid?

##### - UrlIs.URLIS_APPLIABLE

Attempt to determine a valid scheme for the URL.

##### - UrlIs.URLIS_DIRECTORY

Does the URL string end with a directory?

##### - UrlIs.URLIS_FILEURL

Is the URL a file URL?

##### - UrlIs.URLIS_HASQUERY

Does the URL have an appended query string?

##### - UrlIs.URLIS_NOHISTORY

Is the URL a URL that is not typically tracked in navigation history?

##### - UrlIs.URLIS_OPAQUE

Is the URL [opaque](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-urlisopaquea)?

##### - UrlIs.URLIS_URL

Is the URL valid?

## Return value

Type: **BOOL**

For all but one of the URL types, **UrlIs** returns **TRUE** if the URL is the specified type, or **FALSE** if not.

If *UrlIs* is set to **URLIS_APPLIABLE**, **UrlIs** will attempt to determine the URL scheme. If the function is able to determine a scheme, it returns **TRUE**, or **FALSE** otherwise.

## See also

[UrlIsFileUrl](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-urlisfileurla)

[UrlIsNoHistory](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-urlisnohistorya)

[UrlIsOpaque](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-urlisopaquea)

## Remarks

> [!NOTE]
> The shlwapi.h header defines UrlIs as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
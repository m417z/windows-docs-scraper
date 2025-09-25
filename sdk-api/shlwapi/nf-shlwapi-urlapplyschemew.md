# UrlApplySchemeW function

## Description

Determines a scheme for a specified URL string, and returns a string with an appropriate prefix.

## Parameters

### `pszIn` [in]

Type: **PCTSTR**

A null-terminated string of maximum length INTERNET_MAX_URL_LENGTH that contains a URL.

### `pszOut` [out]

Type: **PTSTR**

A pointer to a buffer that, when this function returns successfully, receives a null-terminated string set to the URL specified by *pszIn* and converted to the standard *scheme*://*URL_string* format.

### `pcchOut` [in, out]

Type: **DWORD***

The address of a value set to the number of characters in the *pszOut* buffer. When the function returns, the value depends on whether the function is successful or returns E_POINTER. For other return values, the value of this parameter is meaningless.

### `dwFlags`

Type: **DWORD**

The flags that specify how to determine the scheme. The following flags can be combined.

#### URL_APPLY_DEFAULT

Apply the default scheme if **UrlApplyScheme** can't determine one. The default prefix is stored in the registry but is typically "http".

#### URL_APPLY_GUESSSCHEME

Attempt to determine the scheme by examining *pszIn*.

#### URL_APPLY_GUESSFILE

Attempt to determine a file URL from *pszIn*.

#### URL_APPLY_FORCEAPPLY

Force **UrlApplyScheme** to determine a scheme for pszIn.

##### - dwFlags.URL_APPLY_DEFAULT

Apply the default scheme if **UrlApplyScheme** can't determine one. The default prefix is stored in the registry but is typically "http".

##### - dwFlags.URL_APPLY_FORCEAPPLY

Force **UrlApplyScheme** to determine a scheme for pszIn.

##### - dwFlags.URL_APPLY_GUESSFILE

Attempt to determine a file URL from *pszIn*.

##### - dwFlags.URL_APPLY_GUESSSCHEME

Attempt to determine the scheme by examining *pszIn*.

## Return value

Type: **HRESULT**

Returns a standard COM return value, including the following.

| Return code | Description |
| --- | --- |
| **S_OK** | A scheme was determined. pszOut points to a string containing the URL with the scheme's prefix. The value of *pcchOut* is set to the number of characters in the string, not counting the terminating **NULL** character. |
| **S_FALSE** | There were no errors, but no prefix was prepended. |
| **E_POINTER** | The buffer was too small. The value of *pcchOut* is set to the minimum number of characters that the buffer must be able to contain, including the terminating **NULL** character. |

## Remarks

If the URL has a valid scheme, the string will not be modified. However, almost any combination of two or more characters followed by a colon will be parsed as a scheme. Valid characters include some common punctuation marks, such as ".". If your input string fits this description, **UrlApplyScheme** may treat it as valid and not apply a scheme. To force the function to apply a scheme to a URL, set the **URL_APPLY_FORCEAPPLY** and **URL_APPLY_DEFAULT** flags in *dwFlags*. This combination of flags forces the function to apply a scheme to the URL. Typically, the function will not be able to determine a valid scheme. The second flag guarantees that, if no valid scheme can be determined, the function will apply the default scheme to the URL.

> [!NOTE]
> The shlwapi.h header defines UrlApplyScheme as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
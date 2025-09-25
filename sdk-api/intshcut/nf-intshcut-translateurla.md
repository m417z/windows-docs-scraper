# TranslateURLA function

## Description

Applies common translations to a given URL string, creating a new URL string.

## Parameters

### `pcszURL`

Type: **PCTSTR**

The address of the URL string to be translated.

### `dwInFlags`

Type: **DWORD**

The bit flags that specify how the URL string is to be translated. This value can be a combination of the following:

#### TRANSLATEURL_FL_GUESS_PROTOCOL

If the protocol scheme is not specified in the *pcszURL* parameter to **TranslateURL**, the system automatically chooses a scheme and adds it to the URL.

#### TRANSLATEURL_FL_USE_DEFAULT_PROTOCOL

If the protocol scheme is not specified in the *pcszURL* parameter to
**TranslateURL**, the system adds the default protocol to the URL.

### `ppszTranslatedURL` [out]

Type: **PTSTR***

A pointer variable that receives the pointer to the newly created, translated URL string, if any. The *ppszTranslatedURL* parameter is valid only if the function returns S_OK.

## Return value

Type: **HRESULT**

Returns S_OK upon success, or S_FALSE if the URL did not require translation. If an error occurs, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_FLAGS** | The flag combination passed in *dwInFlags* is invalid. |
| **E_OUTOFMEMORY** | There was insufficient memory to complete the operation. |
| **E_POINTER** | One of the input pointers is invalid. |

## Remarks

This function does not validate the input URL string. A successful return value does not indicate that the URL strings are valid URLs.

> [!NOTE]
> The intshcut.h header defines TranslateURL as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
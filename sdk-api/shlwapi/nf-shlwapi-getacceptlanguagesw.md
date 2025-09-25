# GetAcceptLanguagesW function

## Description

Retrieves a string used with websites when specifying language preferences.

## Parameters

### `pszLanguages` [out]

Type: **LPTSTR**

A pointer to a string that, when this function returns successfully, receives the language preferences information. We recommend that this buffer be of size 2048 characters to ensure sufficient space to return the full string. You can also call this function with this parameter set to NULL to retrieve the size of the string that will be returned.

### `pcchLanguages` [in, out]

Type: **DWORD***

A pointer to the size, in characters, of the string at *pszLanguages*.

On entry, this value is the size of *pszLanguages*, including the terminating null character.

On exit, it is the actual size of *pszLanguages*, not including the terminating null character.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For those versions of Windows that do not include **GetAcceptLanguages** in Shlwapi.h, this function's individual ANSI or Unicode version must be called directly from Shlwapi.dll. **GetAcceptLanguagesA** is ordinal 14 and **GetAcceptLanguagesW** is ordinal 15.

Some websites offer content in multiple languages. You can specify your language preferences in the Internet Options item in Control Panel. **GetAcceptLanguages** retrieves a string that represents those preferences. That string is sent in an additional language header when negotiating HTTP connections.

**Note** If your app or service passes language tags from this function to any [National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support) functions, or to Microsoft .NET, it must first convert the tags through the [ResolveLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-resolvelocalename) function.

> [!NOTE]
> The shlwapi.h header defines GetAcceptLanguages as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
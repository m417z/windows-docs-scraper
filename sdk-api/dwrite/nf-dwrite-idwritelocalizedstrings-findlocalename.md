# IDWriteLocalizedStrings::FindLocaleName

## Description

 Gets the zero-based index of the locale name/string pair with the specified locale name.

## Parameters

### `localeName` [in]

Type: **const WCHAR***

A null-terminated array of characters containing the locale name to look for.

### `index` [out]

Type: **UINT32***

The zero-based index of the locale name/string pair. This method initializes *index* to **UINT_MAX**.

### `exists` [out]

Type: **BOOL***

When this method returns, contains **TRUE** if the locale name exists; otherwise, **FALSE**. This method initializes *exists* to **FALSE**.

## Return value

Type: **HRESULT**

If the specified locale name does not exist, the return value is **S_OK**,
but *index* is **UINT_MAX** and *exists* is **FALSE**.

## Remarks

Note that if the locale name does not exist, the return value is a success and the *exists* parameter is **FALSE**. If you are getting the font family name for a font and the specified locale name does not exist, one option is to set the index to 0 as shown below. There is always at least one locale for a font family.

```cpp
UINT32 index = 0;
BOOL exists = false;

wchar_t localeName[LOCALE_NAME_MAX_LENGTH];

if (SUCCEEDED(hr))
{
    // Get the default locale for this user.
    int defaultLocaleSuccess = GetUserDefaultLocaleName(localeName, LOCALE_NAME_MAX_LENGTH);

    // If the default locale is returned, find that locale name, otherwise use "en-us".
    if (defaultLocaleSuccess)
    {
        hr = pFamilyNames->FindLocaleName(localeName, &index, &exists);
    }
    if (SUCCEEDED(hr) && !exists) // if the above find did not find a match, retry with US English
    {
        hr = pFamilyNames->FindLocaleName(L"en-us", &index, &exists);
    }
}

// If the specified locale doesn't exist, select the first on the list.
if (!exists)
    index = 0;

```

## See also

[IDWriteLocalizedStrings](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritelocalizedstrings)
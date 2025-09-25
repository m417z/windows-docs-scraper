# IDWriteFontFamily::GetFamilyNames

## Description

 Creates a localized strings object that contains the family names for the font family, indexed by locale name.

## Parameters

### `names` [out]

Type: **[IDWriteLocalizedStrings](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritelocalizedstrings)****

The address of a pointer to the newly created [IDWriteLocalizedStrings](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritelocalizedstrings) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The following code example shows how to get the font family name from a [IDWriteFontFamily](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfamily) object.

```cpp
IDWriteLocalizedStrings* pFamilyNames = NULL;

// Get a list of localized strings for the family name.
if (SUCCEEDED(hr))
{
    hr = pFontFamily->GetFamilyNames(&pFamilyNames);
}

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

UINT32 length = 0;

// Get the string length.
if (SUCCEEDED(hr))
{
    hr = pFamilyNames->GetStringLength(index, &length);
}

// Allocate a string big enough to hold the name.
wchar_t* name = new (std::nothrow) wchar_t[length+1];
if (name == NULL)
{
    hr = E_OUTOFMEMORY;
}

// Get the family name.
if (SUCCEEDED(hr))
{
    hr = pFamilyNames->GetString(index, name, length+1);
}

```

## See also

[IDWriteFontFamily](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfamily)
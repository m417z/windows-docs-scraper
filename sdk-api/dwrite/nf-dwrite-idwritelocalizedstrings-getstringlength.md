# IDWriteLocalizedStrings::GetStringLength

## Description

 Gets the length in characters (not including the null terminator) of the string with the specified index.

## Parameters

### `index`

Type: **UINT32**

A zero-based index of the language/string pair.

### `length` [out]

Type: **UINT32***

The length in characters of the string, not including the null terminator, from the language/string pair.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Use **GetStringLength** to get the string length before calling the [IDWriteLocalizedStrings::GetString](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritelocalizedstrings-getstring) method, as shown in the following code.

```cpp
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

[IDWriteLocalizedStrings](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritelocalizedstrings)
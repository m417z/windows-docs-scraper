# IDWriteLocalizedStrings::GetString

## Description

 Copies the string with the specified index to the specified array.

## Parameters

### `index`

Type: **UINT32**

The zero-based index of the language/string pair to be examined.

### `stringBuffer` [out]

Type: **WCHAR***

The null terminated array of characters that receives the string from the language/string pair. The buffer allocated for this array should be at least the size of *size*. [GetStringLength](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritelocalizedstrings-getstringlength) can be used to get the size of the array before using this method.

### `size`

Type: **UINT32**

The size of the array in characters. The size must include space for the terminating
null character. [GetStringLength](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritelocalizedstrings-getstringlength) can be used to get the size of the array before using this method.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The string returned must be allocated by the caller. You can get the size of the string by using the [GetStringLength](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritelocalizedstrings-getstringlength) method prior to calling **GetString**, as shown in the following example.

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
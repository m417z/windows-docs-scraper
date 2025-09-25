# PSPropertyKeyFromString function

## Description

Converts a string to a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

## Parameters

### `pszString` [in]

Type: **LPCWSTR**

Pointer to a null-terminated, Unicode string to be converted.

### `pkey` [out]

Type: **[PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey)***

When this function returns, contains a pointer to a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The string to be converted must be formatted as `"{fmtid} pid"`. For instance, the string that corresponds to `PKEY_Title` is: `"{F29F85E0-4FF9-1068-AB91-08002B27B3D9} 2"`. [PSStringFromPropertyKey](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psstringfrompropertykey) outputs strings in this format.

This function succeeds for any valid property key string, even if the property does not exist in the property schema.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PSPropertyKeyFromString](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pspropertykeyfromstring).

```cpp
PROPERTYKEY key;

HRESULT hr = PSPropertyKeyFromString(L"{F29F85E0-4FF9-1068-AB91-08002B27B3D9} 2", &key);

if (SUCCEEDED(hr))
{
    // The key variable is now valid.
}
```

## See also

[PSGetPropertyKeyFromName](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertykeyfromname)

[PSStringFromPropertyKey](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psstringfrompropertykey)
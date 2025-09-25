# PSStringFromPropertyKey function

## Description

Creates a string that identifies a property from that property's key.

## Parameters

### `pkey` [in]

Type: **REFPROPERTYKEY**

Reference to a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure that identifies a property.

### `psz` [out]

Type: **LPWSTR**

Pointer to a buffer that receives the output string. The buffer should be large enough to contain PKEYSTR_MAX **WCHAR****s**.

### `cch` [in]

Type: **UINT**

The length of the buffer pointed to by *psz*, in **WCHAR****s**.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The string format retrieved is `"{propkey.fmtid} propkey.pid"`. For example, the output string for `PKEY_Title` is `"{F29F85E0-4FF9-1068-AB91-08002B27B3D9} 2"`.

#### Examples

The following example, to be included as part of a larger program, demonstrates the use of [PSPropertyKeyFromString](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pspropertykeyfromstring).

```cpp
WCHAR szKey[PKEYSTR_MAX]

HRESULT hr = PSStringFromPropertyKey(PKEY_Title, szKey, ARRAYSIZE(szKey));

if (SUCCEEDED(hr))
{
    // szKey is now valid.
}
```

## See also

[PSGetNameFromPropertyKey](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetnamefrompropertykey)

[PSPropertyKeyFromString](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pspropertykeyfromstring)
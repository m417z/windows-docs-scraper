# PSGetPropertyKeyFromName function

## Description

Gets the property key for a canonical property name.

## Parameters

### `pszName` [in]

Type: **PCWSTR**

Pointer to a property name as a null-terminated, Unicode string.

### `ppropkey` [out]

Type: **[PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey)***

When this function returns, contains the requested property key.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Property key structure was obtained. |
| **E_INVALIDARG** | The *pszName* parameter is **NULL**. |
| **TYPE_E_ELEMENTNOTFOUND** | The canonical property name does not exist in the schema subsystem cache. |

## Remarks

Property keys uniquely identify a property. For example, `PKEY_Keywords` corresponds to `System.Keywords`. This function succeeds only for properties registered as part of the property schema.

See [PSGetPropertyDescriptionByName](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertydescriptionbyname) for a list of legacy property names that are also supported by the function.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PSGetPropertyKeyFromName](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertykeyfromname) to obtain the property key for `System.Keywords`.

```cpp
PROPERTYKEY key;

HRESULT hr = PSGetPropertyKeyFromName(L"System.Keywords", &key);

if (SUCCEEDED(hr))
{
    // The property key is now valid.
}
```

## See also

[IPropertyDescription::GetPropertyKey](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertydescription-getpropertykey)

[PSGetNameFromPropertyKey](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetnamefrompropertykey)

[PSGetPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertydescription)

[PSPropertyKeyFromString](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pspropertykeyfromstring)
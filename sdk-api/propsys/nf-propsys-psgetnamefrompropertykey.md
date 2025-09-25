# PSGetNameFromPropertyKey function

## Description

Retrieves the canonical name of the property, given its [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey).

## Parameters

### `propkey` [in]

Type: **REFPROPERTYKEY**

Reference to a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure that identifies the requested property.

### `ppszCanonicalName` [out]

Type: **PWSTR***

When this function returns, contains a pointer to the property name as a null-terminated Unicode string.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The property's canonical name is obtained. |
| **TYPE_E_ELEMENTNOTFOUND** | Indicates that the [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) does not exist in the schema subsystem cache. |

## Remarks

Retrieves a canonical name for a specified property key. Like property keys, canonical names uniquely identify a property. For example, `System.Keywords` is the canonical name for `PKEY_Keywords`. This function succeeds only for properties registered as part of the property schema.

It is the responsibility of the calling application to use [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to release the string referred to by *ppszCanonicalName* when it is no longer needed.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PSGetNameFromPropertyKey](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetnamefrompropertykey) to read a value from serialized property storage.

```cpp
PWSTR pszName;

HRESULT hr = PSGetNameFromPropertyKey(PKEY_Keywords, &pszName);

if (SUCCEEDED(hr))
{
    // pszName now contains L"System.Keywords"

    CoTaskMemFree(pszName);
}
```

## See also

[IPropertyDescription::GetCanonicalName](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertydescription-getcanonicalname)

[PSGetPropertyDescriptionByName](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertydescriptionbyname)

[PSGetPropertyKeyFromName](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertykeyfromname)

[PSStringFromPropertyKey](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psstringfrompropertykey)
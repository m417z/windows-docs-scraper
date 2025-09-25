# IPropertyDescription::GetCanonicalName

## Description

Gets the case-sensitive name by which a property is known to the system, regardless of its localized name.

## Parameters

### `ppszName` [out]

Type: **LPWSTR***

When this method returns, contains the address of a pointer to the property's canonical name as a null-terminated Unicode string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The information retrieved by this method comes from the *name* attribute of the [propertyDescription](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-propertydescription) element in the property's .propdesc file.

It is the responsibility of the calling application to use [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to release the string referred to by *ppszName* when it is no longer needed.

## See also

[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)
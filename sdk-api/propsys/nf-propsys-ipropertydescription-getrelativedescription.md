# IPropertyDescription::GetRelativeDescription

## Description

Compares two property values in the manner specified by the property description. Returns two display strings that describe how the two properties compare.

## Parameters

### `propvar1` [in]

Type: **REFPROPVARIANT**

A reference to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure that contains the type and value of the first property.

### `propvar2` [in]

Type: **REFPROPVARIANT**

A reference to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure that contains the type and value of the second property.

### `ppszDesc1` [out]

Type: **LPWSTR***

When this method returns, contains the address of a pointer to the description string that compares the first property with the second property. The string is null-terminated.

### `ppszDesc2` [out]

Type: **LPWSTR***

When this method returns, contains the address of a pointer to the description string that compares the second property with the first property. The string is null-terminated.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is influenced by the *relativeDescriptionType* attribute of the [displayInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-displayinfo) element in the property's .propdesc file.

It is the responsibility of the calling application to release *ppszDesc1* and *ppszDesc2* through [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) when they are no longer needed.

## See also

[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)
# IPropertyDescription::GetDisplayName

## Description

Gets the display name of the property as it is shown in any UI.

## Parameters

### `ppszName` [out]

Type: **LPWSTR***

Contains the address of a pointer to the property's name as a null-terminated Unicode string.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Display name is obtained. |
| **E_INVALIDARG** | The *ppszDisplayName* parameter is **NULL**. |
| **E_OUTOFMEMORY** | Memory allocation failed. |

## Remarks

The information retrieved by this method comes from the *singularLabel* and *pluralLabel* attributes of the [labelInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-labelinfo) element in the property's .propdesc file.

It is the responsibility of the calling application to use [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to release the string referred to by *ppszDisplayName* when it is no longer needed.

## See also

[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)
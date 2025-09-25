# IPropertyDescription::GetEditInvitation

## Description

Gets the text used in edit controls hosted in various dialog boxes.

## Parameters

### `ppszInvite` [out]

Type: **LPWSTR***

When this method returns, contains the address of a pointer to a null-terminated Unicode buffer that holds the invitation text.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The information retrieved by this method comes from the *invitationText* attribute of the [labelInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-labelinfo) element in the property's .propdesc file.

It is the responsibility of the calling application to use [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to release the string referred to by *pszInvite* when it is no longer needed.

## See also

[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)
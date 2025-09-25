# MFGetAttributeDouble function

## Description

Returns a **double** value from an attribute store, or a default value if the attribute is not present.

## Parameters

### `pAttributes` [in]

Pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of the attribute store.

### `guidKey` [in]

GUID that identifies which value to retrieve.

### `fDefault` [in]

Default value to return if the attribute store does not contain the specified attribute.

## Return value

Returns a **double** value.

## Remarks

This helper function queries the attribute store for the attribute specified by *guidKey*. If the attribute is not present or does not have type **double**, the function returns *fDefault*.

This function is convenient because it never returns a failure code. However, if the attribute in question does not have a meaningful default value, you should call [IMFAttributes::GetDouble](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-getdouble) and check for MF_E_ATTRIBUTENOTFOUND.

## See also

[Attributes and Properties](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[IMFAttributes::GetDouble](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-getdouble)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)
# MFGetAttributeUINT32 function

## Description

Returns a **UINT32** value from an attribute store, or a default value if the attribute is not present.

## Parameters

### `pAttributes` [in]

Pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of the attribute store.

### `guidKey` [in]

GUID that identifies which value to retrieve.

### `unDefault` [in]

Default value to return if the attribute store does not contain the specified attribute.

## Return value

Returns a **UINT32** value.

## Remarks

This helper function queries the attribute store for the **UINT32** value specified by *guidKey*. If the value is not present or does not have type **UINT32**, the function returns *unDefault*.

This function is convenient because it never returns a failure code. However, if the attribute in question does not have a meaningful default value, you should call [IMFAttributes::GetUINT32](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-getuint32) and check for MF_E_ATTRIBUTENOTFOUND.

## See also

[Attributes and Properties](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[IMFAttributes::GetUINT32](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-getuint32)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)
# MF_ATTRIBUTE_SERIALIZE_OPTIONS enumeration

## Description

Defines flags for serializing and deserializing attribute stores.

## Constants

### `MF_ATTRIBUTE_SERIALIZE_UNKNOWN_BYREF:0x1`

If this flag is set, **IUnknown** pointers in the attribute store are marshaled to and from the stream. If this flag is absent, **IUnknown** pointers in the attribute store are not marshaled or serialized.

## See also

[IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes)

[MFDeserializeAttributesFromStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-mfdeserializeattributesfromstream)

[MFSerializeAttributesToStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-mfserializeattributestostream)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)
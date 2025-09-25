# MFDeserializeAttributesFromStream function

## Description

Loads attributes from a stream into an attribute store.

## Parameters

### `pAttr`

Pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of the attribute store.

### `dwOptions`

Bitwise **OR** of zero or more flags from the [MF_ATTRIBUTE_SERIALIZE_OPTIONS](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mf_attribute_serialize_options) enumeration.

### `pStm`

Pointer to the **IStream** interface of the stream from which to read the attributes.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Use this function to deserialize an attribute store that was serialized with the [MFSerializeAttributesToStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-mfserializeattributestostream) function.

If *dwOptions* contains the MF_ATTRIBUTE_SERIALIZE_UNKNOWN_BYREF flag, the function deserializes **IUnknown** pointers from the stream, as follows:

* If the **IStream** pointer exposes the [IMFObjectReferenceStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfobjectreferencestream) interface (through **QueryInterface**), the function calls [IMFObjectReferenceStream::LoadReference](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfobjectreferencestream-loadreference) to deserialize each pointer.
* Otherwise, the function calls **CoUnmarshalInterface** to deserialize a proxy for the object.

This function deletes any attributes that were previously stored in *pAttr*.

## See also

[Attributes and Properties](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes)

[MF_ATTRIBUTE_SERIALIZE_OPTIONS](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mf_attribute_serialize_options)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)
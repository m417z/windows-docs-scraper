# MFSerializeAttributesToStream function

## Description

Writes the contents of an attribute store to a stream.

## Parameters

### `pAttr`

Pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of the attribute store.

### `dwOptions`

Bitwise **OR** of zero or more flags from the [MF_ATTRIBUTE_SERIALIZE_OPTIONS](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mf_attribute_serialize_options) enumeration.

### `pStm`

Pointer to the **IStream** interface of the stream where the attributes are saved.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If *dwOptions* contains the MF_ATTRIBUTE_SERIALIZE_UNKNOWN_BYREF flag, the function serializes **IUnknown** pointers in the attribute store, as follows:

* If the **IStream** pointer exposes the [IMFObjectReferenceStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfobjectreferencestream) interface (through **QueryInterface**), the function calls [IMFObjectReferenceStream::SaveReference](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfobjectreferencestream-savereference) to serialize each pointer.
* Otherwise, the function calls **CoMarshalInterface** to serialize a proxy for the object.

If *dwOptions* does not include the MF_ATTRIBUTE_SERIALIZE_UNKNOWN_BYREF flag, the function skips **IUnknown** pointers in the attribute store.

To load the attributes from the stream, call [MFDeserializeAttributesFromStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-mfdeserializeattributesfromstream).

The main purpose of this function is to marshal attributes across process boundaries.

## See also

[Attributes and Properties](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)
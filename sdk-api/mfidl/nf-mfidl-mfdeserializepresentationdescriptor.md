# MFDeserializePresentationDescriptor function

## Description

Deserializes a presentation descriptor from a byte array.

## Parameters

### `cbData`

Size of the *pbData* array, in bytes.

### `pbData`

Pointer to an array of bytes that contains the serialized presentation descriptor.

### `ppPD`

Receives a pointer to the [IMFPresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationdescriptor) interface of the presentation descriptor. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## See also

[MFSerializePresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfserializepresentationdescriptor)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)
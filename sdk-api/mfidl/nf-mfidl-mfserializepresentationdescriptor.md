# MFSerializePresentationDescriptor function

## Description

Serializes a presentation descriptor to a byte array.

## Parameters

### `pPD`

Pointer to the [IMFPresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationdescriptor) interface of the presentation descriptor to serialize.

### `pcbData`

Receives the size of the *ppbData* array, in bytes.

### `ppbData`

Receives a pointer to an array of bytes containing the serialized presentation descriptor. The caller must free the memory for the array by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

To deserialize the presentation descriptor, pass the byte array to the [MFDeserializePresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfdeserializepresentationdescriptor) function.

## See also

[IMFPresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationdescriptor)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)
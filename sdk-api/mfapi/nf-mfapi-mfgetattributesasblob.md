# MFGetAttributesAsBlob function

## Description

Converts the contents of an attribute store to a byte array.

## Parameters

### `pAttributes` [in]

Pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of the attribute store.

### `pBuf` [out]

Pointer to an array that receives the attribute data.

### `cbBufSize` [in]

Size of the *pBuf* array, in bytes. To get the required size of the buffer, call [MFGetAttributesAsBlobSize](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfgetattributesasblobsize).

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **MF_E_BUFFERTOOSMALL** | The buffer given in *pBuf* is too small. |

## Remarks

The function skips any attributes with **IUnknown** pointer values (MF_ATTRIBUTE_IUNKNOWN); they are not stored in the array.

To convert the byte array back into an attribute store, call [MFInitAttributesFromBlob](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfinitattributesfromblob).

To write an attribute store to a stream, call the [MFSerializeAttributesToStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-mfserializeattributestostream) function.

## See also

[Attributes and Properties](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)
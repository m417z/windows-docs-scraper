# MFInitAttributesFromBlob function

## Description

Initializes the contents of an attribute store from a byte array.

## Parameters

### `pAttributes` [in]

Pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of the attribute store.

### `pBuf` [in]

Pointer to the array that contains the initialization data.

### `cbBufSize` [in]

Size of the *pBuf* array, in bytes.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **E_INVALIDARG** | The buffer is not valid. |

## Remarks

Use this function to deserialize an attribute store that was serialized with the [MFGetAttributesAsBlob](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfgetattributesasblob) function.

This function deletes any attributes that were previously stored in *pAttributes*.

## See also

[Attributes and Properties](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)
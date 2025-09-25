# MFGetAttributesAsBlobSize function

## Description

Retrieves the size of the buffer needed for the [MFGetAttributesAsBlob](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfgetattributesasblob) function.

## Parameters

### `pAttributes` [in]

Pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of the attribute store.

### `pcbBufSize` [out]

Receives the required size of the array, in bytes.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

Use this function to find the size of the array that is needed for the [MFGetAttributesAsBlob](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfgetattributesasblob) function.

## See also

[Attributes and Properties](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)
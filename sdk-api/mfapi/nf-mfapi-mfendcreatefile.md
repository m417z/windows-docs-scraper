# MFEndCreateFile function

## Description

Completes an asynchronous request to create a byte stream from a file.

## Parameters

### `pResult` [in]

Pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface. Pass in the same pointer that your callback object received in the [Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method.

### `ppFile` [out]

Receives a pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface of the byte stream. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

Call this function when the [MFBeginCreateFile](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfbegincreatefile) function completes asynchronously.

## See also

[MFBeginCreateFile](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfbegincreatefile)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)
# IMFFinalizableMediaSink::EndFinalize

## Description

Completes an asynchronous finalize operation.

## Parameters

### `pResult` [in]

Pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface. Pass in the same pointer that your callback object received in the [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Call this method after the [IMFFinalizableMediaSink::BeginFinalize](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imffinalizablemediasink-beginfinalize) method completes asynchronously.

## See also

[IMFFinalizableMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imffinalizablemediasink)
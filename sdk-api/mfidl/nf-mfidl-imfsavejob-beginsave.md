# IMFSaveJob::BeginSave

## Description

Begins saving a Windows Media file to the application's byte stream.

## Parameters

### `pStream` [in]

Pointer to the [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface of the application's byte stream. The data from the source byte stream is written to this byte stream.

### `pCallback` [in]

Pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object. The caller must implement this interface

### `pState` [in]

Pointer to the **IUnknown** interface of a state object, defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

When the operation completes, the callback object's [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method is called. At that point, the application should call [IMFSaveJob::EndSave](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsavejob-endsave) to complete the asynchronous request.

## See also

[IMFSaveJob](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsavejob)
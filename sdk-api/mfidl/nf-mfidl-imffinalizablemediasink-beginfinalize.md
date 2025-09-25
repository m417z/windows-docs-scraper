# IMFFinalizableMediaSink::BeginFinalize

## Description

Notifies the media sink to asynchronously take any steps it needs to finish its tasks.

## Parameters

### `pCallback` [in]

Pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of an asynchronous object. The caller must implement this interface.

### `punkState` [in]

Pointer to the **IUnknown** interface of a state object, defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Many archive media sinks have steps they need to do at the end of archiving to complete their file operations, such as updating the header (for some formats) or flushing all pending writes to disk. In some cases, this may include expensive operations such as indexing the content. **BeginFinalize** is an asynchronous way to initiate final tasks.

When the finalize operation is complete, the callback object's [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method is called. At that point, the application should call [IMFFinalizableMediaSink::EndFinalize](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imffinalizablemediasink-endfinalize) to complete the asynchronous request.

## See also

[IMFFinalizableMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imffinalizablemediasink)
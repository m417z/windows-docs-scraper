# IMFTrackedSample::SetAllocator

## Description

Sets the owner for the sample.

## Parameters

### `pSampleAllocator` [in]

Pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object. The caller must implement this interface.

### `pUnkState` [in]

Pointer to the **IUnknown** interface of a state object, defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_NOTACCEPTING** | The owner was already set. This method cannot be called twice on the sample. |

## Remarks

When this method is called, the sample holds an additional reference count on itself. When every other object releases its reference counts on the sample, the sample invokes the *pSampleAllocator* callback method. To get a pointer to the sample, call [IMFAsyncResult::GetObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasyncresult-getobject) on the asynchronous result object given to the callback's [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method.

After the callback is invoked, the sample clears the callback. To reinstate the callback, you must call **SetAllocator** again.

It is safe to pass in the sample's [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface pointer as the state object (*pUnkState*) for the callback. If *pUnkState* points to the sample, the **SetAllocator** method accounts for the additional reference count on *pUnkState*.

## See also

[IMFTrackedSample](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftrackedsample)
# MFInvokeCallback function

## Description

Invokes a callback method to complete an asynchronous operation.

## Parameters

### `pAsyncResult`

Pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface. To create this object, call [MFCreateAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreateasyncresult).

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **MF_E_INVALID_WORKQUEUE** | Invalid work queue. For more information, see [IMFAsyncCallback::GetParameters](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-getparameters). |
| **MF_E_SHUTDOWN** | The [MFShutdown](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfshutdown) function was called to shut down the Media Foundation platform. |

## Remarks

If you are implementing an asynchronous method, use this function to invoke the caller's [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method.

The callback is invoked from a Media Foundation work queue. For more information, see [Writing an Asynchronous Method](https://learn.microsoft.com/windows/desktop/medfound/writing-an-asynchronous-method).

The [MFShutdown](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfshutdown) function shuts down the work queue threads, so the callback is not guaranteed to be invoked after **MFShutdown** is called.

## See also

[Asynchronous Callback Methods](https://learn.microsoft.com/windows/desktop/medfound/asynchronous-callback-methods)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)
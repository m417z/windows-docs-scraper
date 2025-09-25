# MFCreateAsyncResult function

## Description

Creates an asynchronous result object. Use this function if you are implementing an asynchronous method.

## Parameters

### `punkObject`

Pointer to the object stored in the asynchronous result. This pointer is returned by the [IMFAsyncResult::GetObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasyncresult-getobject) method. This parameter can be **NULL**.

### `pCallback`

Pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface. This interface is implemented by the caller of the asynchronous method.

### `punkState`

Pointer to the **IUnknown** interface of a state object. This value is provided by the caller of the asynchronous method. This parameter can be **NULL**.

### `ppAsyncResult`

Receives a pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

To invoke the callback specified in *pCallback*, call the [MFInvokeCallback](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfinvokecallback) function.

## See also

[Asynchronous Callback Methods](https://learn.microsoft.com/windows/desktop/medfound/asynchronous-callback-methods)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)
# RtwqCreateAsyncResult function

## Description

Creates an asynchronous result object. Use this function if you are implementing an asynchronous method.

## Parameters

### `appObject` [in]

Pointer to the object stored in the asynchronous result. This pointer is returned by the [IRtwqAsyncResult::GetObject](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-irtwqasyncresult-getobject) method. This parameter can be **NULL**.

### `callback` [in]

Pointer to the [IRtwqAsyncCallback](https://learn.microsoft.com/windows/desktop/api/rtworkq/nn-rtworkq-irtwqasynccallback) interface. This interface is implemented by the caller of the asynchronous method.

### `appState` [in]

Pointer to the **IUnknown** interface of a state object. This value is provided by the caller of the asynchronous method. This parameter can be **NULL**.

### `asyncResult` [out]

Receives a pointer to the [IRtwqAsyncResult](https://learn.microsoft.com/windows/desktop/api/rtworkq/nn-rtworkq-irtwqasyncresult) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To invoke the callback specified in *pCallback*, call the [RtwqInvokeCallback](https://learn.microsoft.com/windows/desktop/api/rtworkq/nf-rtworkq-rtwqinvokecallback) function.
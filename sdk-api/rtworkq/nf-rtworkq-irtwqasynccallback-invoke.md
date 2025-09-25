# IRtwqAsyncCallback::Invoke

## Description

Called when an asynchronous operation is completed.

## Parameters

### `pAsyncResult` [in]

Pointer to the [IRtwqAsyncResult](https://learn.microsoft.com/windows/desktop/api/rtworkq/nn-rtworkq-irtwqasyncresult) interface. Pass this pointer to the asynchronous **End...** method to complete the asynchronous call.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Within your implementation of [Invoke](https://learn.microsoft.com/windows/desktop/DirectShow/cdeferredcommand-invoke), call the corresponding **End...** method.

## See also

[IRtwqAsyncCallback](https://learn.microsoft.com/windows/desktop/api/rtworkq/nn-rtworkq-irtwqasynccallback)
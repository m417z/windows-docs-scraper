# IWSDAsyncResult::SetCallback

## Description

Specifies a callback interface to call when the asynchronous operation has completed.

## Parameters

### `pCallback` [in]

Pointer to a [IWSDAsyncCallback](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasynccallback) object that contains the callback implemented by the user.

### `pAsyncState` [in]

User-defined state information to pass to the callback.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *pCallback* is **NULL**. |

## Remarks

The [IWSDAsyncCallback::AsyncOperationComplete](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsdasynccallback-asyncoperationcomplete) method is passed the result object associated with the completing message and the state.

*pCallback* is released when the [IWSDAsyncResult](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasyncresult) object is destroyed.

## See also

[IWSDAsyncResult](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasyncresult)
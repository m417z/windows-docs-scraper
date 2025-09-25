# IWSDAsyncCallback::AsyncOperationComplete

## Description

Indicates that the asynchronous operation has completed.

## Parameters

### `pAsyncResult` [in]

Pointer to an [IWSDAsyncResult](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasyncresult) object that contains the user-defined state information passed to [IWSDAsyncResult::SetCallback](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsdasyncresult-setcallback).

### `pAsyncState` [in]

The state of the asynchronous operation.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |

## Remarks

The value returned by **AsyncOperationComplete** is ignored.

## See also

[IWSDAsyncCallback](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasynccallback)
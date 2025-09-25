# IWSDAsyncResult::HasCompleted

## Description

Indicates whether the operation has completed.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation completed. |
| **S_FALSE** | The operation has not completed. |

## Remarks

A failed asynchronous operation is treated as a completed asynchronous operation. Error or fault information can be retrieved from the [IWSDAsyncCallback](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasynccallback) interface using the [IWSDAsyncCallback::AsyncOperationComplete](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsdasynccallback-asyncoperationcomplete) method.

## See also

[IWSDAsyncResult](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasyncresult)
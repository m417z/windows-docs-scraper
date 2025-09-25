# IWSDAsyncResult::Abort

## Description

Aborts the asynchronous operation.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |

## Remarks

**Abort** waits for all pending callbacks set with [SetCallback](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsdasyncresult-setcallback) to complete before returning to the caller.

## See also

[IWSDAsyncResult](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasyncresult)
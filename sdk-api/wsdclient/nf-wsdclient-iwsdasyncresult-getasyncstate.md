# IWSDAsyncResult::GetAsyncState

## Description

Gets the state of the asynchronous operation.

## Parameters

### `ppAsyncState` [out]

User-defined state information.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation completed successfully. |
| **E_POINTER** | *ppAsyncState* is **NULL**. |

## See also

[IWSDAsyncResult](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasyncresult)
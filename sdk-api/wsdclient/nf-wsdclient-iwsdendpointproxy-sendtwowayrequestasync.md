# IWSDEndpointProxy::SendTwoWayRequestAsync

## Description

Sends a two-way request message using an asynchronous call pattern.

## Parameters

### `pBody` [in]

The body of the message.

### `pOperation` [in]

Reference to a [WSD_OPERATION](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_operation) structure that specifies the operation to perform.

### `pAsyncState` [in]

Anonymous data passed to *pCallback* when the operation has completed. This data is used to associate a client object with the pending operation. This parameter may be optional.

### `pCallback` [in]

Reference to an [IWSDAsyncCallback](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasynccallback) object which performs the message status callback notification. This parameter may be optional.

### `pResult` [out]

Reference to an [IWSDAsyncResult](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasyncresult) object that specifies the results of the operation.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *pOperation* or *pResult* is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

This method is normally only called by generated proxy code.

## See also

[IWSDEndpointProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdendpointproxy)
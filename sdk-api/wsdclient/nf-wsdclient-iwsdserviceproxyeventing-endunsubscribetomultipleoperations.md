# IWSDServiceProxyEventing::EndUnsubscribeToMultipleOperations

## Description

Completes an asynchronous cancellation request for a subscription to a collection of notifications or solicit/response events.

## Parameters

### `pOperations` [in]

Pointer to an array of references to [WSD_OPERATION](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_operation) structures that specifies the operations from which to unsubscribe.

### `dwOperationCount` [in]

The number of elements in the array in *pOperations*.

### `pResult` [out]

Pointer to an [IWSDAsyncResult](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasyncresult) interface that will represent the result of the requests upon completion.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWSDServiceProxyEventing](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdserviceproxyeventing)
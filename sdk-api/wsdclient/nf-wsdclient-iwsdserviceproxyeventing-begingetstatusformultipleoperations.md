# IWSDServiceProxyEventing::BeginGetStatusForMultipleOperations

## Description

Begins an asynchronous operation that retrieves the current status for a collection of event subscriptions.

## Parameters

### `pOperations` [in]

Pointer to an array of references to [WSD_OPERATION](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_operation) structures that specify the operation subscriptions to get status on.

### `dwOperationCount` [in]

The number of elements in the array in *pOperations*.

### `pAny` [in]

Pointer to extensible data to be added to the body of the request. This parameter is optional.

### `pAsyncState` [in]

Anonymous data passed to *pAsyncCallback* when the callback is called. This data is used to associate a client object with the pending operation. This parameter is optional.

### `pAsyncCallback` [in]

Reference to an [IWSDAsyncCallback](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasynccallback) object that performs the message callback status notifications. This parameter is optional.

### `ppResult` [out]

Pointer to a pointer to an [IWSDAsyncResult](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasyncresult) interface that will represent the result of the requests upon completion.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWSDServiceProxyEventing](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdserviceproxyeventing)
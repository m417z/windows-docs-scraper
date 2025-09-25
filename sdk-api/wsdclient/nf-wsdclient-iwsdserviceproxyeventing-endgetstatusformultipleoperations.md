# IWSDServiceProxyEventing::EndGetStatusForMultipleOperations

## Description

Completes an asynchronous operation that retrieves the current status for a collection of event subscriptions.

## Parameters

### `pOperations` [in]

Pointer to an array of references to [WSD_OPERATION](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_operation) structures that specify the operation subscriptions to get status on.

### `dwOperationCount` [in]

The number of elements in the array in *pOperations*.

### `pResult` [in]

Pointer to an [IWSDAsyncResult](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasyncresult) interface that represents the result of the requests upon completion.

### `ppExpires` [out]

Pointer to a pointer to a [WSD_EVENTING_EXPIRES](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_eventing_expires) structure that specfies the duration of the subscription. Upon completion, call [WSDFreeLinkedMemory](https://learn.microsoft.com/windows/desktop/api/wsdutil/nf-wsdutil-wsdfreelinkedmemory) to free the memory. This parameter is optional.

### `ppAny` [out]

Extensible data that the remote device can add to the subscription response. This allows services to provide additional customization of getstatu requests. When done, call [WSDFreeLinkedMemory](https://learn.microsoft.com/windows/desktop/api/wsdutil/nf-wsdutil-wsdfreelinkedmemory) to free the memory. For details, see [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element). This parameter is optional.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWSDServiceProxyEventing](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdserviceproxyeventing)
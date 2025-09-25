# IWSDServiceProxyEventing::SubscribeToMultipleOperations

## Description

Subscribes to a collection of notifications or solicit/response events.

## Parameters

### `pOperations` [in]

Pointer to an array of references to [WSD_OPERATION](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_operation) structures that specify the operations of whiCh to subscribe.

### `dwOperationCount` [in]

The number of elements in the array in *pOperations*.

### `pUnknown` [in]

Anonymous data passed to a client eventing callback function. This data is used to associate a client object with the subscription.

### `pExpires` [in]

Pointer to a [WSD_EVENTING_EXPIRES](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_eventing_expires) structure that specifies requested duration for the subscription.

### `pAny` [in]

Pointer to extensible data to be added to the body of the request. This parameter is optional.

### `ppExpires` [out]

Pointer to a pointer to a [WSD_EVENTING_EXPIRES](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_eventing_expires) structure that specfies the duration of the subscription. Upon completion, call [WSDFreeLinkedMemory](https://learn.microsoft.com/windows/desktop/api/wsdutil/nf-wsdutil-wsdfreelinkedmemory) to free the memory. This parameter is optional.

### `ppAny` [out]

Extensible data that the remote device can add to the subscription response. This allows services to provide additional customization of event subscriptions. When done, call [WSDFreeLinkedMemory](https://learn.microsoft.com/windows/desktop/api/wsdutil/nf-wsdutil-wsdfreelinkedmemory) to free the memory. For details, see [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element). This parameter is optional.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | The proxy has already subscribed to the operation specified by *pOperation*. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_FAIL** | The method failed. |

## Remarks

This method is designed to be exclusively called by generated proxy code.

The method is synchronous and will return when the requests have completed or the expiration criteria have been satisfied.

## See also

[IWSDServiceProxyEventing](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdserviceproxyeventing)
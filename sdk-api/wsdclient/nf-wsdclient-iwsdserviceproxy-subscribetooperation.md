# IWSDServiceProxy::SubscribeToOperation

## Description

Subscribes to a notification or solicit/response event.

## Parameters

### `pOperation` [in]

 Reference to a [WSD_OPERATION](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_operation) structure that specifies the operation to subscribe to.

### `pUnknown` [in]

Anonymous data passed to a client eventing callback function. This data is used to associate a client object with the subscription.

### `pAny` [in]

Extensible data to be added to the body of the subscription request. You can use the IWSDXML* interfaces to build the data. For details, see [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element).

### `ppAny` [out]

Extensible data that the remote device can add to the subscription response. This allows services to provide additional customization of event subscriptions. When done, call [WSDFreeLinkedMemory](https://learn.microsoft.com/windows/desktop/api/wsdutil/nf-wsdutil-wsdfreelinkedmemory) to free the memory. For details, see [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element). Do not release this object.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | The proxy has already subscribed to the operation specified by *pOperation*. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **E_FAIL** | The method failed. |

## Remarks

This method is normally only called by generated proxy code.

## See also

[IWSDServiceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdserviceproxy)
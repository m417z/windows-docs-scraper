# IWSDServiceProxyEventing::UnsubscribeToMultipleOperations

## Description

Cancels a collection of subscriptions to notifications or solicit/response events.

## Parameters

### `pOperations` [in]

Pointer to an array of references to [WSD_OPERATION](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_operation) structures that specify the operations to unsubscribe from.

### `dwOperationCount` [in]

The number of elements in the array in *pOperations*.

### `pAny` [in]

Pointer to extensible data to be added to the body of the request.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | The proxy is not subscribed to the notification specified by *pOperation*. |
| **E_POINTER** | *pOperation* is NULL. |

## Remarks

This method is designed to be exclusively called by generated proxy code.

## See also

[IWSDServiceProxyEventing](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdserviceproxyeventing)
# IWSDServiceProxy::UnsubscribeToOperation

## Description

Cancels a subscription to a notification or solicit/response event.

## Parameters

### `pOperation` [in]

Reference to a [WSD_OPERATION](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_operation) structure that specifies the operation subscribed to.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | The proxy is not subscribed to the notification specified by *pOperation*. |
| **E_POINTER** | *pOperation* is **NULL**. |

## See also

[IWSDServiceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdserviceproxy)
# IFunctionDiscoveryProvider::EndQuery

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Terminates a query being executed by a provider.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | One of the parameters contains an invalid argument. |

## Remarks

This method is called by Function Discovery to indicate to a provider that no further query notifications will be sent to the [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) callback interface. Implementers should try to ensure that no further query notifications are sent to Function Discovery after the call to **EndQuery** returns. If a provider implementation sends a notification after **EndQuery** returns, Function Discovery returns an error to the provider and the notification is not forwarded to the client.

**EndQuery** is only called when a client passed an [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) interface passed to the provider's [Initialize](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nf-functiondiscoveryprovider-ifunctiondiscoveryprovider-initialize) method.

Any data structures associated with the query can be deleted in the implementation of **EndQuery**. Any private context memory allocated by the [Query](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nf-functiondiscoveryprovider-ifunctiondiscoveryprovider-query) method should also be deleted.

Note that [Query](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nf-functiondiscoveryprovider-ifunctiondiscoveryprovider-query) can be invoked again once **EndQuery** has returned.

## See also

[IFunctionDiscoveryProvider](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-ifunctiondiscoveryprovider)
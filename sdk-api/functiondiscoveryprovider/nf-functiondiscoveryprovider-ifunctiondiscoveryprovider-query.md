# IFunctionDiscoveryProvider::Query

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Retrieves a collection of function instances that meet the specified constraints.

## Parameters

### `pIFunctionDiscoveryProviderQuery` [in]

A pointer to an [IFunctionDiscoveryProviderQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-ifunctiondiscoveryproviderquery) interface that contains parameters that define the query criteria.

### `ppIFunctionInstanceCollection` [out]

A pointer to an [IFunctionInstanceCollection](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstancecollection) interface that the provider should use to return function instances synchronously in response to the given query.

When you implement the **Query** method, you can set this parameter to **NULL** if your provider supports notifications, that is, your provider returns results asynchronously. Asynchronous results should be returned using the [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) interface passed to the provider's [Initialize](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nf-functiondiscoveryprovider-ifunctiondiscoveryprovider-initialize) method.

If the client application has not implemented notifications, it may pass a **NULL** parameter.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully and the results are being returned synchronously. |
| **E_INVALIDARG** | The *pIFunctionDiscoveryProviderQuery* parameter is **NULL**. |
| **E_PENDING** | The method completed successfully and the results are being returned asynchronously. |

## Remarks

An active query is terminated by Function Discovery with a call to the [EndQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nf-functiondiscoveryprovider-ifunctiondiscoveryprovider-endquery) method. Note that **EndQuery** will only be called if the client specified a [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) interface for the query. If a **IFunctionDiscoveryNotification** was not provided, the query must be considered ended by the provider once the **Query** call is complete.

A client can re-execute a query at any time after the previous **Query** call has returned. The implementation of **Query** must be able to return an [IFunctionInstanceCollection](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstancecollection) for the new query. [EndQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nf-functiondiscoveryprovider-ifunctiondiscoveryprovider-endquery) will only be called before a subsequent **Query** call when a client passed an [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) interface passed to the provider's [Initialize](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nf-functiondiscoveryprovider-ifunctiondiscoveryprovider-initialize) method.

If **Query** returns **E_PENDING**, the provider must call the [OnEvent](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscoverynotification-onevent) method of the [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) interface with **FD_EVENTID_SEARCHCOMPLETE** to indicate that the enumeration of results is complete. Failure to send the **FD_EVENTID_SEARCHCOMPLETE** event can result in clients hanging indefinitely

## See also

[IFunctionDiscoveryProvider](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-ifunctiondiscoveryprovider)
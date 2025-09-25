# IFunctionInstanceCollectionQuery::Execute

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Performs the query defined by [IFunctionDiscovery::CreateInstanceCollectionQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscovery-createinstancecollectionquery).

## Parameters

### `ppIFunctionInstanceCollection` [out]

A pointer to an [IFunctionInstanceCollection](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstancecollection) interface pointer that receives the requested function instance collection.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. Results are returned synchronously in *ppIFunctonInstanceCollecton*. |
| **E_OUTOFMEMORY** | The method is unable to allocate the memory required to perform this operation. |
| **E_PENDING** | Some of the results will be returned by asynchronous notification. See the remarks for details. |

 A predefined query is a query of a layered [category](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/function-discovery-categories). When a predefined query is executed, each provider that returns a function instance also returns an HRESULT value. The provider HRESULT values are aggregated, and the value returned by the **Execute** method reflects these aggregate results. Results are aggregated as follows:

* If all providers return **S_OK**, **Execute** returns **S_OK**.
* If at least one provider returns **E_PENDING**, and all other providers return either **S_OK** or **E_PENDING**, **Execute** returns **E_PENDING**.
* If all providers return an error value (that is, a value other than **S_OK** or **E_PENDING**), **Execute** returns the error value returned by the network provider that was last queried. Also, if the client's [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) callback routine was provided to [IFunctionDiscovery::CreateInstanceCollectionQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscovery-createinstancecollectionquery), an [OnError](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscoverynotification-onerror) notification is sent for each provider. Each **OnError** notification contains the HRESULT returned by the provider.
* If at least one provider returns an error value, and all other providers return **S_OK**, **Execute** returns **S_OK**. [OnError](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscoverynotification-onerror) notifications are sent as described above.
* If at least one provider returns an error value, and at least one provider returns **E_PENDING**, **Execute** returns **E_PENDING**. [OnError](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscoverynotification-onerror) notifications are sent as described above.

When **Execute** returns **S_OK**, *ppIFunctionInstanceCollection* contains the results of the query. If an [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) interface is provided to the [CreateInstanceCollectionQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscovery-createinstancecollectionquery) method of [IFunctionDiscovery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscovery), then changes to the results will be communicated using that interface.

When **Execute** returns **E_PENDING**, the result set will be returned asynchronously through the [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) interface provided to the [CreateInstanceCollectionQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscovery-createinstancecollectionquery) method of [IFunctionDiscovery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscovery). *ppIFunctionInstanceCollection* may be **NULL** or may contain a partial result set. The enumeration is complete once the [OnEvent](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscoverynotification-onevent) method of **IFunctionDiscoveryNotification** is called with **FD_EVENTID_SEARCHCOMPLETE**. After the **FD_EVENTID_SEARCHCOMPLETE** event is received, additional notifications are updates to the results.

## Remarks

This method must be must be invoked by the client program before any data can be retrieved from the query object. When called, this method performs the following:

1. Retrieves the function instance collection object.
2. Queries the provider of the category that is passed into [IFunctionDiscovery::CreateInstanceCollectionQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscovery-createinstancecollectionquery).
3. Retrieves the category provider.
4. Queries the category provider using the subcategory data to generate the collection using query constraints.
5. Initiates the update notification mechanism if the address of the client program's [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) callback routine is provided to [IFunctionDiscovery::CreateInstanceCollectionQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscovery-createinstancecollectionquery).
6. Caches the collection data and returns.

Function Discovery network providers only return function instances through the [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) interface. They return no function instances directly when this method is invoked. Instead, [Execute](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstancequery-execute) simply initiates an entirely asynchronous retrieval operation and returns **E_PENDING** to indicate that the results will be returned asynchronously. Notifications must be used to retrieve function instances from Function Discovery network providers.

## See also

[Function Discovery Queries](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/function-discovery-queries)

[IFunctionInstanceCollectionQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstancecollectionquery)
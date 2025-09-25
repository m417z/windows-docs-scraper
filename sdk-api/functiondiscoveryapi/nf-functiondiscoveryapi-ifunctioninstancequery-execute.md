# IFunctionInstanceQuery::Execute

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Performs the query defined by [IFunctionDiscovery::CreateInstanceQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscovery-createinstancequery).

## Parameters

### `ppIFunctionInstance` [out]

A pointer to an [IFunctionInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstance) interface pointer that receives the requested function instance.

## Return value

Possible return values include, but are not limited to, the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | The *ppIFunctionInstance* parameter is **NULL**. |
| **E_OUTOFMEMORY** | The method is unable to allocate the memory required to perform this operation. |
| **E_PENDING** | The results to be returned by a provider will come through asynchronous notification. |
| **HRESULT_FROM_WIN32(ERROR_OBJECT_NOT_FOUND)**<br><br>0x800710d8 | The function instance represented by the specified ID does not exist on this computer. |
| **HRESULT_FROM_WIN32(ERROR_KEY_DELETED)**<br><br>0x800703fa | The function instance could not be returned because the key corresponding to the function instance was deleted by another process. This error is returned by the registry provider if a key is deleted while query processing is taking place. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)**<br><br>0x80070002 | The function instance could not be returned because the key corresponding to the function instance could not be found. This error is returned by the registry provider when the provider could not find matching instances for an instance query. |

A predefined query is a query of a layered [category](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/function-discovery-categories). When a predefined query is executed, each provider that returns a function instance also returns an HRESULT value. The provider HRESULT values are aggregated, and the value returned by the [Execute](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstancecollectionquery-execute) method reflects these aggregate results. Results are aggregated as follows:

* If all providers return S_OK, [Execute](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstancecollectionquery-execute) returns S_OK.
* If at least one provider returns E_PENDING, and all other providers return either S_OK or E_PENDING, [Execute](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstancecollectionquery-execute) returns E_PENDING.
* If all providers return an error value (that is, a value other than S_OK or E_PENDING), [Execute](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstancecollectionquery-execute) returns the error value returned by the network provider that was last queried. Also, if the client's [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) callback routine was provided to [IFunctionDiscovery::CreateInstanceCollectionQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscovery-createinstancecollectionquery), an [OnError](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscoverynotification-onerror) notification is sent for each provider. Each **OnError** notification contains the HRESULT returned by the provider.
* If at least one provider returns an error value, and all other providers return S_OK, [Execute](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstancecollectionquery-execute) returns S_OK. [OnError](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscoverynotification-onerror) notification(s) are sent as described above.
* If at least one provider returns an error value, and at least one provider returns E_PENDING, [Execute](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstancecollectionquery-execute) returns E_PENDING. [OnError](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscoverynotification-onerror) notification(s) are sent as described above.

## Remarks

This method must be must be invoked by the client program to retrieve data from the query object. When called, this method performs the following:

1. Retrieves the function instance.
2. Initiates the update notification mechanism if the address of the client program's [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) callback routine is provided to [IFunctionDiscovery::CreateInstanceQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscovery-createinstancequery).

Function Discovery network providers only return function instances through the [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) interface. They return no function instances directly when this method is invoked. Instead, **Execute** simply initiates an entirely asynchronous retrieval operation and returns E_PENDING to indicate that the results will be returned asynchronously. Notifications must be used to retrieve function instances from Function Discovery network providers.

If **Execute** is called twice on the same query object, the first query is terminated before the second query executes.

## See also

[Function Discovery Queries](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/function-discovery-queries)

[IFunctionInstanceQuery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstancequery)
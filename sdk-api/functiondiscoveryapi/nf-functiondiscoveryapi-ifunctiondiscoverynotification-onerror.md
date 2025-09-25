# IFunctionDiscoveryNotification::OnError

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Receives errors that occur during asynchronous query processing.

## Parameters

### `hr` [in]

The query error that is being reported.

### `fdqcQueryContext` [in]

The context registered for change notification. The type **FDQUERYCONTEXT** is defined as a DWORDLONG.

### `pszProvider` [in]

The name of the provider.

## Return value

The client program's implementation of the **OnError** method should return one of the following **HRESULT** values to the caller.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | The value of one of the input parameters is invalid. |

## Remarks

Typically, clients will expect that any asynchronous error is fatal and that the query will stop returning results, but custom provider documentation could indicate otherwise for specific error codes.

Do not call **Release** on the query object from this method. Doing so could cause a deadlock. If **Release** is called on a query object from another thread while a callback is in process, the object will not be released until the callback has finished.

All notifications passed to Function Discovery by providers are queued and returned to the client one by one. Callbacks are synchronized so that a client will only receive one notification at a time.

Because other [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) method calls may be made in other threads, any changes made to the thread state during the call must be restored before exiting the method.

## See also

[IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification)
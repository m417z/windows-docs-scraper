# IFunctionDiscoveryNotification::OnEvent

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Receives any add, remove, or update events during a notification.

## Parameters

### `dwEventID` [in]

The type of event.

| Value | Meaning |
| --- | --- |
| **FD_EVENTID_SEARCHCOMPLETE**<br><br>1000 | The search was completed by a provider. Typically, this notification is sent by network protocol providers where the protocol specifies a defined interval in which search results will be accepted. Both the WSD and [SSDP](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/ssdp-provider) providers use this event type. <br><br>Once this notification is sent, a query ignores all incoming responses to the initial search or probe request. However, the query will still monitor for Hello or Bye messages (used to indicate when a device is added or removed). The query will continue to monitor for these events until **Release** is called on the query object.<br><br>This notification will not be sent if a catastrophic error occurs.<br><br>For information about how this event is implemented or used by a specific provider, follow the link to the provider documentation from the [Built-in Providers](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/built-in-providers) topic. |
| **FD_EVENTID_ASYNCTHREADEXIT**<br><br>1001 | Not used by Function Discovery clients. |
| **FD_EVENTID_SEARCHSTART**<br><br>1002 | Not used by Function Discovery clients. |
| **FD_EVENTID_IPADDRESSCHANGE**<br><br>1003 | The IP address of the NIC changed. The WSD provider implements this notification. Events may be sent when a power event occurs (for example, when machine wakes from sleep) or when roaming with a laptop.<br><br>**Note** This value is not available for use on Windows Vista. It is available on Windows Vista with SP1, Windows Server 2008, and subsequent versions of the operating system. |

### `fdqcQueryContext` [in]

The context registered for change notification. The type **FDQUERYCONTEXT** is defined as a **DWORDLONG**. This parameter can be **NULL**.

### `pszProvider` [in]

The name of the provider.

## Return value

The client program's implementation of the **OnEvent** method should return one of the following **HRESULT** values to the caller.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | The value of one of the input parameters is invalid. |

## Remarks

Function Discovery providers (SSDP and WSD) use this method to implement notifications that a search pass is complete.

Do not call **Release** on the query object from this method. Doing so could cause a deadlock. If **Release** is called on a query object from another thread while a callback is in process, the object will not be released until the callback has finished.

All notifications passed to Function Discovery by providers are queued and returned to the client one by one. Callbacks are synchronized so that a client will only receive one notification at a time.

Because other [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) method calls may be made in other threads, any changes made to the thread state during the call must be restored before exiting the method.

#### Examples

The following example shows an OnEvent handler implementation. The **CMyNotificationListener** class is defined in the [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) topic.

```cpp
#include <windows.h>

HRESULT CMyNotificationListener::OnEvent(
                                         IN DWORD dwEventID,
                                         IN FDQUERYCONTEXT fdqcQueryContext,
                                         IN const WCHAR * pszProvider
                                         )
{
    HRESULT hr = S_OK;
    HANDLE hSearchComplete = INVALID_HANDLE_VALUE;
    hSearchComplete = OpenEventW( EVENT_ALL_ACCESS,
                                  FALSE,
                                  L"SearchComplete" );

    if( NULL == hSearchComplete )
    {
        return hr;
    }

    if( FD_EVENTID_SEARCHCOMPLETE == dwEventID )
    {
        SetEvent( hSearchComplete );
    }

    CloseHandle( hSearchComplete );

    return hr;
}

```

## See also

[IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification)
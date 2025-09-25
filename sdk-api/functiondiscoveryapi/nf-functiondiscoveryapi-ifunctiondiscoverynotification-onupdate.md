# IFunctionDiscoveryNotification::OnUpdate

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Indicates that a function instance has been added, removed, or changed. This method is implemented by the client program and is called by Function Discovery.

## Parameters

### `enumQueryUpdateAction` [in]

A [QueryUpdateAction](https://learn.microsoft.com/windows/win32/api/functiondiscoveryapi/ne-functiondiscoveryapi-queryupdateaction) value that specifies the type of action Function Discovery is performing on the specified function instance.

### `fdqcQueryContext` [in]

The context registered for change notification. The type **FDQUERYCONTEXT** is defined as a DWORDLONG. This parameter can be **NULL**.

### `pIFunctionInstance` [in]

An [IFunctionInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstance) interface pointer that represents the function instance being affected by the update.

## Return value

The client program's implementation of the **OnUpdate** method should return one of the following **HRESULT** values to the caller.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | The value of one of the input parameters is invalid. |

## Remarks

Do not call **Release** on the query object from this method. Doing so could cause a deadlock. If **Release** is called on a query object from another thread while a callback is in process, the object will not be released until the callback has finished.

All notifications passed to Function Discovery by providers are queued and returned to the client one by one. Callbacks are synchronized so that a client will only receive one notification at a time.

Because other [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) method calls may be made in other threads, any changes made to the thread state during the call must be restored before exiting the method.

#### Examples

The following code shows an OnUpdate handler implementation. The **CMyNotificationListener** class is defined in the [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) topic.

```cpp
#include <windows.h>

HRESULT STDMETHODCALLTYPE CMyNotificationListener::OnUpdate(
                                          IN QueryUpdateAction Action,
                                          IN FDQUERYCONTEXT fdqcQueryContext,
                                          IN IFunctionInstance *pInstance)
{
    HRESULT hr = S_OK;

    switch (Action) {
    case QUA_ADD:
        SetEvent( m_hAddEvent );
        break;
    case QUA_REMOVE:
        SetEvent( m_hRemoveEvent );
        break;
    case QUA_CHANGE:
        SetEvent( m_hChangeEvent );
        break;
    }
    return S_OK;
}

```

## See also

[IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification)
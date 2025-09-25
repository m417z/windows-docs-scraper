# IMMDeviceEnumerator::RegisterEndpointNotificationCallback

## Description

The **RegisterEndpointNotificationCallback** method registers a client's notification callback interface.

## Parameters

### `pClient` [in]

Pointer to the [IMMNotificationClient](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immnotificationclient) interface that the client is registering for notification callbacks.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pNotify* is **NULL**. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

This method registers an IMMNotificationClient interface to be called by the system when the roles, state, existence, or properties of an endpoint device change. The caller implements the IMMNotificationClient interface.

When notifications are no longer needed, the client can call the [IMMDeviceEnumerator::UnregisterEndpointNotificationCallback](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdeviceenumerator-unregisterendpointnotificationcallback) method to terminate the notifications.

The client must ensure that the [IMMNotificationClient](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immnotificationclient) object is not released after the **RegisterEndpointNotificationCallback** call and before calling [UnregisterEndpointNotificationCallback](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdeviceenumerator-unregisterendpointnotificationcallback). These methods do not call the client's **IMMNotificationClient::AddRef** and **IMMNotificationClient::Release** implementations. The client is responsible for maintaining the reference count of the **IMMNotificationClient** object. The client must increment the count if the **RegisterEndpointNotificationCallback** call succeeds and release the final reference only after calling **UnregisterEndpointNotificationCallback** or implement some other mechanism to ensure that the object is not deleted before **UnregisterEndpointNotificationCallback** is called. Otherwise, the application leaks the resources held by the **IMMNotificationClient** and any other object that is implemented in the same container.

For more information about the **AddRef** and **Release** methods, see the discussion of the **IUnknown** interface in the Windows SDK documentation.

## See also

[IMMDeviceEnumerator Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdeviceenumerator)

[IMMDeviceEnumerator::UnregisterEndpointNotificationCallback](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdeviceenumerator-unregisterendpointnotificationcallback)

[IMMNotificationClient Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immnotificationclient)
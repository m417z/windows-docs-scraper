# IMMDeviceEnumerator::UnregisterEndpointNotificationCallback

## Description

The **UnregisterEndpointNotificationCallback** method deletes the registration of a notification interface that the client registered in a previous call to the [IMMDeviceEnumerator::RegisterEndpointNotificationCallback](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdeviceenumerator-registerendpointnotificationcallback) method.

## Parameters

### `pClient` [in]

Pointer to the client's [IMMNotificationClient](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immnotificationclient) interface. The client passed this same interface pointer to the device enumerator in a previous call to the [IMMDeviceEnumerator::RegisterEndpointNotificationCallback](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdeviceenumerator-registerendpointnotificationcallback) method. For more information, see Remarks.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pNotify* is **NULL**. |
| **E_NOTFOUND** | The specified notification interface was not found. |

## Remarks

The client must ensure that the [IMMNotificationClient](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immnotificationclient) object is not released after the [RegisterEndpointNotificationCallback](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdeviceenumerator-registerendpointnotificationcallback) call and before calling **UnregisterEndpointNotificationCallback**. These methods do not call the client's **IMMNotificationClient::AddRef** and **IMMNotificationClient::Release** implementations. The client is responsible for maintaining the reference count of the **IMMNotificationClient** object. The client must increment the count if the **RegisterEndpointNotificationCallback** call succeeds and release the final reference only after calling **UnregisterEndpointNotificationCallback** or implement some other mechanism to ensure that the object is not deleted before **UnregisterEndpointNotificationCallback** is called. Otherwise, the application leaks the resources held by the **IMMNotificationClient** and any other object that is implemented in the same container.

For more information about the **AddRef** and **Release** methods, see the discussion of the **IUnknown** interface in the Windows SDK documentation.

## See also

[IMMDeviceEnumerator Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdeviceenumerator)

[IMMDeviceEnumerator::RegisterEndpointNotificationCallback](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdeviceenumerator-registerendpointnotificationcallback)

[IMMNotificationClient Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immnotificationclient)
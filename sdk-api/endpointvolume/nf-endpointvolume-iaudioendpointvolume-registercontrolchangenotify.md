# IAudioEndpointVolume::RegisterControlChangeNotify

## Description

The **RegisterControlChangeNotify** method registers a client's notification callback interface.

## Parameters

### `pNotify` [in]

Pointer to the [IAudioEndpointVolumeCallback](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolumecallback) interface that the client is registering for notification callbacks. If the **RegisterControlChangeNotify** method succeeds, it calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the client's **IAudioEndpointVolumeCallback** interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pNotify* is **NULL**. |

## Remarks

This method registers an [IAudioEndpointVolumeCallback](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolumecallback) interface to be called by the system when the volume level or muting state of an endpoint changes. The caller implements the **IAudioEndpointVolumeCallback** interface.

When notifications are no longer needed, the client can call the [IAudioEndpointVolume::UnregisterControlChangeNotify](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-unregistercontrolchangenotify) method to terminate the notifications.

Before the client releases its final reference to the [IAudioEndpointVolumeCallback](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolumecallback) interface, it should call [UnregisterControlChangeNotify](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-unregistercontrolchangenotify) to unregister the interface. Otherwise, the application leaks the resources held by the **IAudioEndpointVolumeCallback** and [IAudioEndpointVolume](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume) objects. Note that **RegisterControlChangeNotify** calls the client's [IAudioEndpointVolumeCallback::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method, and **UnregisterControlChangeNotify** calls the [IAudioEndpointVolumeCallback::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method. If the client errs by releasing its reference to the **IAudioEndpointVolumeCallback** interface before calling **UnregisterControlChangeNotify**, the **IAudioEndpointVolume** object never releases its reference to the **IAudioEndpointVolumeCallback** interface. For example, a poorly designed **IAudioEndpointVolumeCallback** implementation might call **UnregisterControlChangeNotify** from the destructor for the **IAudioEndpointVolumeCallback** object. In this case, the client will not call **UnregisterControlChangeNotify** until the **IAudioEndpointVolume** object releases its reference to the **IAudioEndpointVolumeCallback** interface, and the **IAudioEndpointVolume** object will not release its reference to the **IAudioEndpointVolumeCallback** interface until the client calls **UnregisterControlChangeNotify**. For more information about the **AddRef** and **Release** methods, see the discussion of the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface in the Windows SDK documentation.

In addition, the client should call [UnregisterControlChangeNotify](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-unregistercontrolchangenotify) before releasing the final reference to the [IAudioEndpointVolume](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume) object. Otherwise, the object leaks the storage that it allocated to hold the registration information. After registering a notification interface, the client continues to receive notifications for only as long as the **IAudioEndpointVolume** object exists.

For a code example that calls **RegisterControlChangeNotify**, see [Endpoint Volume Controls](https://learn.microsoft.com/windows/desktop/CoreAudio/endpoint-volume-controls).

## See also

[IAudioEndpointVolume Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume)

[IAudioEndpointVolume::UnregisterControlChangeNotify](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-unregistercontrolchangenotify)

[IAudioEndpointVolumeCallback Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolumecallback)
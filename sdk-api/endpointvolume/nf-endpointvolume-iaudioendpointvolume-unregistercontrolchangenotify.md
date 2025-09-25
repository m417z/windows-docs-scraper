# IAudioEndpointVolume::UnregisterControlChangeNotify

## Description

The **UnregisterControlChangeNotify** method deletes the registration of a client's notification callback interface that the client registered in a previous call to the [IAudioEndpointVolume::RegisterControlChangeNotify](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-registercontrolchangenotify) method.

## Parameters

### `pNotify` [in]

Pointer to the client's [IAudioEndpointVolumeCallback](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolumecallback) interface. The client passed this same interface pointer to the endpoint volume object in a previous call to the [IAudioEndpointVolume::RegisterControlChangeNotify](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-registercontrolchangenotify) method. If the **UnregisterControlChangeNotify** method succeeds, it calls the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the client's **IAudioEndpointVolumeCallback** interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pNotify* is **NULL**. |

## Remarks

Before the client releases its final reference to the [IAudioEndpointVolumeCallback](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolumecallback) interface, it should call **UnregisterControlChangeNotify** to unregister the interface. Otherwise, the application leaks the resources held by the **IAudioEndpointVolumeCallback** and [IAudioEndpointVolume](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume) objects. Note that the [IAudioEndpointVolume::RegisterControlChangeNotify](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-registercontrolchangenotify) method calls the client's [IAudioEndpointVolumeCallback::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method, and **UnregisterControlChangeNotify** calls the [IAudioEndpointVolumeCallback::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method. If the client errs by releasing its reference to the **IAudioEndpointVolumeCallback** interface before calling **UnregisterControlChangeNotify**, the **IAudioEndpointVolume** object never releases its reference to the **IAudioEndpointVolumeCallback** interface. For example, a poorly designed **IAudioEndpointVolumeCallback** implementation might call **UnregisterControlChangeNotify** from the destructor for the **IAudioEndpointVolumeCallback** object. In this case, the client will not call **UnregisterControlChangeNotify** until the **IAudioEndpointVolume** object releases its reference to the **IAudioEndpointVolumeCallback** interface, and the **IAudioEndpointVolume** object will not release its reference to the **IAudioEndpointVolumeCallback** interface until the client calls **UnregisterControlChangeNotify**. For more information about the **AddRef** and **Release** methods, see the discussion of the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface in the Windows SDK documentation.

For a code example that calls **UnregisterControlChangeNotify**, see [Endpoint Volume Controls](https://learn.microsoft.com/windows/desktop/CoreAudio/endpoint-volume-controls).

## See also

[IAudioEndpointVolume Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume)

[IAudioEndpointVolume::RegisterControlChangeNotify](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-registercontrolchangenotify)

[IAudioEndpointVolumeCallback Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolumecallback)
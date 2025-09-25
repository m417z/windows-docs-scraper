# ID3D11Device4::RegisterDeviceRemovedEvent

## Description

Registers the "device removed" event and indicates when a Direct3D device has become removed for any reason, using an asynchronous notification mechanism.

## Parameters

### `hEvent` [in]

Type: **HANDLE**

The handle to the "device removed" event.

### `pdwCookie` [out]

Type: **DWORD***

A pointer to information about the "device removed" event, which can be used in [UnregisterDeviceRemoved](https://learn.microsoft.com/windows/desktop/api/d3d11_4/nf-d3d11_4-id3d11device4-unregisterdeviceremoved) to unregister the event.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

See [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

Indicates when a Direct3D device has become removed for any reason, using an asynchronous notification mechanism, rather than as an HRESULT from [Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present). The reason for device removal can be retrieved using [ID3D11Device::GetDeviceRemovedReason](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-getdeviceremovedreason) after being notified of the occurrence.

Applications register and un-register a Win32 event handle with a particular device.
That event handle will be signaled when the device becomes removed.
A poll into the device's **ID3D11Device::GetDeviceRemovedReason** method indicates that the device is removed.

[ISignalableNotifier](https://learn.microsoft.com/uwp/api/Windows.System.Threading.Core) or [SetThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolwait) can be used by UWP apps.

When the graphics device is lost, the app or title will receive the graphics event, so that the app or title knows that its graphics device is no longer valid and it is safe for the app or title to re-create its DirectX devices.
In response to this event, the app or title needs to re-create its rendering device
and pass it into a SetRenderingDevice call on the composition graphics device objects.

After setting this new rendering device, the app or title needs to redraw content of all the pre-existing surfaces
after the composition graphics device's **OnRenderingDeviceReplaced** event is fired.

This method supports Composition for device loss.

The event is not signaled when it is most ideal to re-create.
So, instead, we recommend iterating through the adapter ordinals and creating the first ordinal that will succeed.

The application can register an event with the device.
The application will be signaled when the device becomes removed.

If the device is already removed, calls to **RegisterDeviceRemovedEvent** will signal the event immediately.
No device-removed error code will be returned from **RegisterDeviceRemovedEvent**.

Each "device removed" event is never signaled, or is signaled only once.
These events are not signaled during device destruction.
These events are unregistered during destruction.

The semantics of **RegisterDeviceRemovedEvent** are similar to
[IDXGIFactory2::RegisterOcclusionStatusEvent](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-registerocclusionstatusevent).

## See also

[ID3D11Device4](https://learn.microsoft.com/windows/desktop/api/d3d11_4/nn-d3d11_4-id3d11device4)

[UnregisterDeviceRemoved](https://learn.microsoft.com/windows/desktop/api/d3d11_4/nf-d3d11_4-id3d11device4-unregisterdeviceremoved)
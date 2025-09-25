# IDXGIFactory2::RegisterStereoStatusEvent

## Description

Registers to receive notification of changes in stereo status by using event signaling.

## Parameters

### `hEvent` [in]

A handle to the event object that the operating system sets when notification of stereo status change occurs. The [CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) or [OpenEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-openeventa) function returns this handle.

### `pdwCookie` [out]

A pointer to a key value that an application can pass to the [IDXGIFactory2::UnregisterStereoStatus](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-unregisterstereostatus) method to unregister the notification event that *hEvent* specifies.

## Return value

**RegisterStereoStatusEvent** returns:

* S_OK if it successfully registered the event.
* E_OUTOFMEMORY if memory is unavailable to complete the operation.
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

**Platform Update for Windows 7:** On Windows 7 or Windows Server 2008 R2 with the [Platform Update for Windows 7](https://support.microsoft.com/help/2670838) installed, **RegisterStereoStatusEvent** fails with E_NOTIMPL. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7).

## See also

[IDXGIFactory2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgifactory2)
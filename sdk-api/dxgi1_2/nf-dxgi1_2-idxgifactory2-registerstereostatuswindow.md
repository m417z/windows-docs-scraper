# IDXGIFactory2::RegisterStereoStatusWindow

## Description

Registers an application window to receive notification messages of changes of stereo status.

## Parameters

### `WindowHandle` [in]

The handle of the window to send a notification message to when stereo status change occurs.

### `wMsg` [in]

Identifies the notification message to send.

### `pdwCookie` [out]

A pointer to a key value that an application can pass to the [IDXGIFactory2::UnregisterStereoStatus](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-unregisterstereostatus) method to unregister the notification message that *wMsg* specifies.

## Return value

**RegisterStereoStatusWindow** returns:

* S_OK if it successfully registered the window.
* E_OUTOFMEMORY if memory is unavailable to complete the operation.
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

**Platform Update for Windows 7:** On Windows 7 or Windows Server 2008 R2 with the [Platform Update for Windows 7](https://support.microsoft.com/help/2670838) installed, **RegisterStereoStatusWindow** fails with E_NOTIMPL. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7).

## See also

[IDXGIFactory2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgifactory2)
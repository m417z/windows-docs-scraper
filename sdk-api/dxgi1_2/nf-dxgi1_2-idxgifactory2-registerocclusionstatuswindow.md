# IDXGIFactory2::RegisterOcclusionStatusWindow

## Description

Registers an application window to receive notification messages of changes of occlusion status.

## Parameters

### `WindowHandle` [in]

The handle of the window to send a notification message to when occlusion status change occurs.

### `wMsg` [in]

Identifies the notification message to send.

### `pdwCookie` [out]

A pointer to a key value that an application can pass to the [IDXGIFactory2::UnregisterOcclusionStatus](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-unregisterocclusionstatus) method to unregister the notification message that *wMsg* specifies.

## Return value

**RegisterOcclusionStatusWindow** returns:

* S_OK if it successfully registered the window.
* E_OUTOFMEMORY if memory is unavailable to complete the operation.
* [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) if *WindowHandle* is not a valid window handle or not the window handle that the current process owns.
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

**Platform Update for Windows 7:** On Windows 7 or Windows Server 2008 R2 with the [Platform Update for Windows 7](https://support.microsoft.com/help/2670838) installed, **RegisterOcclusionStatusWindow** fails with E_NOTIMPL. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7).

## Remarks

Apps choose the Windows message that Windows sends when occlusion status changes.

## See also

[IDXGIFactory2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgifactory2)
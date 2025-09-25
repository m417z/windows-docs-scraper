# IDXGIFactory2::RegisterOcclusionStatusEvent

## Description

Registers to receive notification of changes in occlusion status by using event signaling.

## Parameters

### `hEvent` [in]

A handle to the event object that the operating system sets when notification of occlusion status change occurs. The [CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) or [OpenEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-openeventa) function returns this handle.

### `pdwCookie` [out]

A pointer to a key value that an application can pass to the [IDXGIFactory2::UnregisterOcclusionStatus](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-unregisterocclusionstatus) method to unregister the notification event that *hEvent* specifies.

## Return value

**RegisterOcclusionStatusEvent** returns:

* S_OK if the method successfully registered the event.
* E_OUTOFMEMORY if memory is unavailable to complete the operation.
* [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) if *hEvent* is not a valid handle or not an event handle.
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

**Platform Update for Windows 7:** On Windows 7 or Windows Server 2008 R2 with the [Platform Update for Windows 7](https://support.microsoft.com/help/2670838) installed, **RegisterOcclusionStatusEvent** fails with E_NOTIMPL. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7).

## Remarks

If you call **RegisterOcclusionStatusEvent** multiple times with the same event handle, **RegisterOcclusionStatusEvent** fails with [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

If you call **RegisterOcclusionStatusEvent** multiple times with the different event handles, **RegisterOcclusionStatusEvent** properly registers the events.

## See also

[IDXGIFactory2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgifactory2)
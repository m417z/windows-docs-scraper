# IDXGIFactory2::UnregisterOcclusionStatus

## Description

Unregisters a window or an event to stop it from receiving notification when occlusion status changes.

## Parameters

### `dwCookie` [in]

A key value for the window or event to unregister. The [IDXGIFactory2::RegisterOcclusionStatusWindow](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-registerocclusionstatuswindow) or [IDXGIFactory2::RegisterOcclusionStatusEvent](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-registerocclusionstatusevent) method returns this value.

## Remarks

**Platform Update for Windows 7:** On Windows 7 or Windows Server 2008 R2 with the [Platform Update for Windows 7](https://support.microsoft.com/help/2670838) installed, **UnregisterOcclusionStatus** has no effect. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7).

## See also

[IDXGIFactory2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgifactory2)
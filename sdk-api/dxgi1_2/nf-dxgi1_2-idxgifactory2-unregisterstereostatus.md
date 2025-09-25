# IDXGIFactory2::UnregisterStereoStatus

## Description

Unregisters a window or an event to stop it from receiving notification when stereo status changes.

## Parameters

### `dwCookie` [in]

A key value for the window or event to unregister. The [IDXGIFactory2::RegisterStereoStatusWindow](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-registerstereostatuswindow) or [IDXGIFactory2::RegisterStereoStatusEvent](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-registerstereostatusevent) method returns this value.

## Remarks

**Platform Update for Windows 7:** On Windows 7 or Windows Server 2008 R2 with the [Platform Update for Windows 7](https://support.microsoft.com/help/2670838) installed, **UnregisterStereoStatus** has no effect. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7).

## See also

[IDXGIFactory2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgifactory2)
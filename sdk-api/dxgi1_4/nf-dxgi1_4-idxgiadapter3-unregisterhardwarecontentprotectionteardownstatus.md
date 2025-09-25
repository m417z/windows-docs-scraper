# IDXGIAdapter3::UnregisterHardwareContentProtectionTeardownStatus

## Description

Unregisters an event to stop it from receiving notification of hardware content protection teardown events.

## Parameters

### `dwCookie` [in]

Type: **DWORD**

A key value for the window or event to unregister. The [IDXGIAdapter3::RegisterHardwareContentProtectionTeardownStatusEvent](https://learn.microsoft.com/windows/desktop/api/dxgi1_4/nf-dxgi1_4-idxgiadapter3-registerhardwarecontentprotectionteardownstatusevent) method returns this value.

## See also

[IDXGIAdapter3](https://learn.microsoft.com/windows/desktop/api/dxgi1_4/nn-dxgi1_4-idxgiadapter3)
# IDXGIAdapter3::RegisterHardwareContentProtectionTeardownStatusEvent

## Description

Registers to receive notification of hardware content protection teardown events.

## Parameters

### `hEvent` [in]

Type: **HANDLE**

A handle to the event object that the operating system sets when hardware content protection teardown occurs. The [CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) or [OpenEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-openeventa) function returns this handle.

### `pdwCookie` [out]

Type: **DWORD***

A pointer to a key value that an application can pass to the [IDXGIAdapter3::UnregisterHardwareContentProtectionTeardownStatus](https://learn.microsoft.com/windows/desktop/api/dxgi1_4/nf-dxgi1_4-idxgiadapter3-unregisterhardwarecontentprotectionteardownstatus) method to unregister the notification event that *hEvent* specifies.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call [ID3D11VideoDevice::GetContentProtectionCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-getcontentprotectioncaps)() to check for the presence of the [D3D11_CONTENT_PROTECTION_CAPS_HARDWARE_TEARDOWN](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_content_protection_caps) capability to know whether the hardware contains an automatic teardown mechanism.

After the event is signaled, the application can call [ID3D11VideoContext1::CheckCryptoSessionStatus](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11videocontext1-checkcryptosessionstatus) to determine the impact of the hardware teardown for a specific [ID3D11CryptoSession](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11cryptosession) interface.

## See also

[IDXGIAdapter3](https://learn.microsoft.com/windows/desktop/api/dxgi1_4/nn-dxgi1_4-idxgiadapter3)
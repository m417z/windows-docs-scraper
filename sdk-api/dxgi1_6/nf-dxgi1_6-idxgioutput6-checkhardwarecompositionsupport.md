# IDXGIOutput6::CheckHardwareCompositionSupport

## Description

Notifies applications that hardware stretching is supported.

## Parameters

### `pFlags` [out]

Type: **UINT***

A bitfield of [DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS](https://learn.microsoft.com/windows/desktop/api/dxgi1_6/ne-dxgi1_6-dxgi_hardware_composition_support_flags) enumeration values describing which types of hardware composition are supported. The values are bitwise OR'd together.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns a code that indicates success or failure.

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[DXGI_HARDWARE_COMPOSITION_SUPPORT_FLAGS enumeration](https://learn.microsoft.com/windows/desktop/api/dxgi1_6/ne-dxgi1_6-dxgi_hardware_composition_support_flags)

[IDXGIOutput6 interface](https://learn.microsoft.com/windows/desktop/api/dxgi1_6/nn-dxgi1_6-idxgioutput6)
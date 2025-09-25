# IDXGIOutput3::CheckOverlaySupport

## Description

Checks for overlay support.

## Parameters

### `EnumFormat` [in]

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value for the color format.

### `pConcernedDevice` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the Direct3D device interface. **CheckOverlaySupport** returns only support info about this scan-out device.

### `pFlags` [out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a variable that receives a combination of [DXGI_OVERLAY_SUPPORT_FLAG](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/ne-dxgi1_3-dxgi_overlay_support_flag)-typed values that are combined by using a bitwise OR operation. The resulting value specifies options for overlay support.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the error codes described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## See also

[IDXGIOutput3](https://learn.microsoft.com/windows/desktop/api/dxgi1_3/nn-dxgi1_3-idxgioutput3)
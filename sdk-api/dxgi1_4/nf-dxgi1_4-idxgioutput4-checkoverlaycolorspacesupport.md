# IDXGIOutput4::CheckOverlayColorSpaceSupport

## Description

Checks for overlay color space support.

## Parameters

### `Format` [in]

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value for the color format.

### `ColorSpace` [in]

Type: **[DXGI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ne-dxgicommon-dxgi_color_space_type)**

A [DXGI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ne-dxgicommon-dxgi_color_space_type)-typed value that specifies color space type to check overlay support for.

### `pConcernedDevice` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the Direct3D device interface. **CheckOverlayColorSpaceSupport** returns only support info about this scan-out device.

### `pFlags` [out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a variable that receives a combination of [DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG](https://learn.microsoft.com/windows/desktop/api/dxgi1_4/ne-dxgi1_4-dxgi_overlay_color_space_support_flag)-typed values that are combined by using a bitwise OR operation. The resulting value specifies options for overlay color space support.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns **S_OK** on success, or it returns one of the error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## See also

[IDXGIOutput4](https://learn.microsoft.com/windows/desktop/api/dxgi1_4/nn-dxgi1_4-idxgioutput4)
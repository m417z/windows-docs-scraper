# IDXGIOutput::GetDesc

## Description

Get a description of the output.

## Parameters

### `pDesc` [out]

Type: **[DXGI_OUTPUT_DESC](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_output_desc)***

A pointer to the output description (see [DXGI_OUTPUT_DESC](https://learn.microsoft.com/windows/desktop/api/dxgi/ns-dxgi-dxgi_output_desc)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns a code that indicates success or failure. S_OK if successful, [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) if *pDesc* is passed in as **NULL**.

## Remarks

 On a high DPI desktop, **GetDesc** returns the visualized screen size unless the app is marked high DPI aware. For info about writing DPI-aware Win32 apps, see [High DPI](https://learn.microsoft.com/windows/desktop/hidpi/high-dpi-desktop-application-development-on-windows).

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIOutput](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgioutput)
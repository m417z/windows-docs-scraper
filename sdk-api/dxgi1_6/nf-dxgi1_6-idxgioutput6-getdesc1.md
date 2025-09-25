# IDXGIOutput6::GetDesc1

## Description

Get an extended description of the output that includes color characteristics and connection type.

## Parameters

### `pDesc` [out]

Type: **[DXGI_OUTPUT_DESC1](https://learn.microsoft.com/windows/desktop/api/dxgi1_6/ns-dxgi1_6-dxgi_output_desc1)***

A pointer to the output description (see [DXGI_OUTPUT_DESC1](https://learn.microsoft.com/windows/win32/api/dxgi1_6/ns-dxgi1_6-dxgi_output_desc1)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns a code that indicates success or failure. S_OK if successful, [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) if *pDesc* is passed in as **NULL**.

## Remarks

Some scenarios do not have well-defined values for all fields in this struct. For example, if this IDXGIOutput represents a clone/duplicate set, or if the EDID has missing or invalid data. In these cases, the OS will provide some default values that correspond to a standard SDR display.

An output's reported color and luminance characteristics can adjust dynamically while the system is running due to user action or changing ambient conditions. Therefore, apps should periodically query **IDXGIFactory::IsCurrent** and re-create their **IDXGIFactory** if it returns **FALSE**. Then re-query **GetDesc1** from the new factory's equivalent output to retrieve the newest color information.

For more details on how to write apps that react dynamically to monitor capabilities, see [Using DirectX with high dynamic range displays and Advanced Color](https://learn.microsoft.com/windows/win32/direct3darticles/high-dynamic-range).

On a high DPI desktop, **GetDesc1** returns the visualized screen size unless the app is marked high DPI aware. For info about writing DPI-aware Win32 apps, see [High DPI](https://learn.microsoft.com/windows/desktop/hidpi/high-dpi-desktop-application-development-on-windows).

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIOutput6](https://learn.microsoft.com/windows/desktop/api/dxgi1_6/nn-dxgi1_6-idxgioutput6)
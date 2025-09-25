# ID3D11TracingDevice::SetShaderTrackingOptions

## Description

Sets the reference rasterizer's race-condition tracking options for a specific shader.

## Parameters

### `pShader` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of a shader.

### `Options` [in]

A combination of [D3D11_SHADER_TRACKING_OPTIONS](https://learn.microsoft.com/windows/win32/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_shader_tracking_options)-typed flags that are combined by using a bitwise **OR** operation. The resulting value identifies tracking options. If a flag is present, the tracking option that the flag represents is set to "on"; otherwise the tracking option is set to "off."

## Return value

This method returns one of the [Direct3D 11 return codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

[D3D11_SHADER_TRACKING_OPTION_UAV_SPECIFIC_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_shader_tracking_options)) in the *Options* parameter for a compute shader, **SetShaderTrackingOptions** ignores it.

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[ID3D11TracingDevice](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nn-d3d11sdklayers-id3d11tracingdevice)
# ID3D11RefTrackingOptions::SetTrackingOptions

## Description

Sets graphics processing unit (GPU) debug reference tracking options.

## Parameters

### `uOptions`

A combination of [D3D11_SHADER_TRACKING_OPTIONS](https://learn.microsoft.com/windows/win32/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_shader_tracking_options)-typed flags that are combined by using a bitwise **OR** operation. The resulting value identifies tracking options. If a flag is present, the tracking option that the flag represents is set to "on"; otherwise the tracking option is set to "off."

## Return value

This method returns one of the [Direct3D 11 return codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[ID3D11RefTrackingOptions](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nn-d3d11sdklayers-id3d11reftrackingoptions)
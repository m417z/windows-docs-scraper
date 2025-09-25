# ID3D12DebugDevice::GetFeatureMask

## Description

Gets a bit field of flags that indicates which debug features are on or off.

## Return value

Type: **[D3D12_DEBUG_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_debug_feature)**

Mask of feature-mask flags,
as a bitwise OR'ed combination of [D3D12_DEBUG_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_debug_feature) enumeration constants.
If a flag is present, then that feature will be set to on, otherwise the feature will be set to off.

## See also

[ID3D12DebugDevice](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12debugdevice)

[ID3D12DebugDevice::SetFeatureMask](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12debugdevice-setfeaturemask)
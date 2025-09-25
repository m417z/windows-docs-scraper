# ID3D12DebugDevice::SetFeatureMask

## Description

Set a bit field of flags that will turn debug features on and off.

## Parameters

### `Mask`

Type: **[D3D12_DEBUG_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_debug_feature)**

Feature-mask flags, as a bitwise-OR'd combination of [D3D12_DEBUG_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_debug_feature) enumeration constants.
If a flag is present, that feature will be set to on; otherwise, the feature will be set to off.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).
[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)

## See also

[GetFeatureMask](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12debugdevice-getfeaturemask)

[ID3D12DebugDevice](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12debugdevice)
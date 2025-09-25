# ID3D12DebugCommandList::SetFeatureMask

## Description

Turns the debug features for a command list on or off.

## Parameters

### `Mask`

Type: **[D3D12_DEBUG_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_debug_feature)**

A combination of feature-mask flags that are combined by using a bitwise OR operation. If a flag is present, that feature will be set to on, otherwise the feature will be set to off.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## See also

[ID3D12DebugCommandList](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12debugcommandlist)
# D3D12_DEBUG_FEATURE enumeration

## Description

Flags for optional D3D12 Debug Layer features.

## Constants

### `D3D12_DEBUG_FEATURE_NONE:0`

The default. No optional Debug Layer features.

### `D3D12_DEBUG_FEATURE_ALLOW_BEHAVIOR_CHANGING_DEBUG_AIDS:0x1`

The Debug Layer is allowed to deliberately change functional behavior of an application in order to help identify potential errors. By default, the Debug Layer allows most invalid API usage to run the natural course.

### `D3D12_DEBUG_FEATURE_CONSERVATIVE_RESOURCE_STATE_TRACKING:0x2`

Performs additional resource state validation of resources set in descriptors at the time [ID3D12CommandQueue::ExecuteCommandLists](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12commandqueue-executecommandlists) is called. By design descriptors can be changed even after submitting command lists assuming proper synchronization. Conservative resource state tracking ignores this allowance and validates all resources used in descriptor tables when **ExecuteCommandLists** is called. The result may be false validation errors.

### `D3D12_DEBUG_FEATURE_DISABLE_VIRTUALIZED_BUNDLES_VALIDATION:0x4`

Disables validation of bundle commands by virtually injecting checks into the calling command list validation paths.

### `D3D12_DEBUG_FEATURE_VALID_MASK`

Internal use only.

## Remarks

This enum is used by [ID3D12DebugDevice1::SetDebugParameter](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12debugdevice1-setdebugparameter) and [ID3D12DebugDevice1::GetDebugParameter](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12debugdevice1-getdebugparameter).

## See also

[Debug Layer Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-sdklayers-enumerations)
# D3D12DDI_STATE_OBJECT_FLAGS enumeration

## Description

**D3D12DDI_STATE_OBJECT_FLAGS** specify constraints for state objects.

## Constants

### `D3D12DDI_STATE_OBJECT_FLAG_NONE:0x0`

There are no state object constraints.

### `D3D12DDI_STATE_OBJECT_FLAG_ALLOW_LOCAL_DEPENDENCIES_ON_EXTERNAL_DEFINITIONS:0x1`

Allows local dependencies on external definitions.

### `D3D12DDI_STATE_OBJECT_FLAG_ALLOW_EXTERNAL_DEPENDENCIES_ON_LOCAL_DEFINITIONS:0x2`

Allows external dependencies on local definitions.

### `D3D12DDI_STATE_OBJECT_FLAG_ALLOW_STATE_OBJECT_ADDITIONS:0x4`

Allows additions to state objects. Available starting with Windows 10, version 2004.

## Remarks

See the [DirectX Raytracing (DXR) functional specification](https://microsoft.github.io/DirectX-Specs/d3d/Raytracing.html) for more information.

## See also

[**D3D12_STATE_OBJECT_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_state_object_config_0054)

[**PFND3D12DDI_ADD_TO_STATE_OBJECT_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_add_to_state_object_0072)
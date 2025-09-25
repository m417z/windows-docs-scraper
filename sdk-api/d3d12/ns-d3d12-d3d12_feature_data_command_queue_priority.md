# D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY structure

## Description

Details the adapter's support for prioritization of different command queue types.

## Members

### `CommandListType`

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-structs-and-classes): `_In_`

The type of the command list you're interested in.

### `Priority`

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-structs-and-classes): `_In_`

The priority level you're interested in.

### `PriorityForTypeIsSupported`

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-structs-and-classes): `_Out_`

On return, contains true if the specfied command list type supports the specified priority level; otherwise, false.

## Remarks

Use this structure with [CheckFeatureSupport](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-checkfeaturesupport) to determine the priority levels supported by various command queue types.

See the enumeration constant **D3D12_FEATURE_COMMAND_QUEUE_PRIORITY** in the [D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature) enumeration.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature)
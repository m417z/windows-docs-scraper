## Description

The type of a state subobject. Use with [D3D12_STATE_SUBOBJECT](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_state_subobject).

## Constants

### `D3D12_STATE_SUBOBJECT_TYPE_STATE_OBJECT_CONFIG:0`

Subobject type is [D3D12_STATE_OBJECT_CONFIG](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_state_object_config).

### `D3D12_STATE_SUBOBJECT_TYPE_GLOBAL_ROOT_SIGNATURE:1`

Subobject type is [D3D12_GLOBAL_ROOT_SIGNATURE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_global_root_signature).

### `D3D12_STATE_SUBOBJECT_TYPE_LOCAL_ROOT_SIGNATURE:2`

Subobject type is [D3D12_LOCAL_ROOT_SIGNATURE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_local_root_signature).

### `D3D12_STATE_SUBOBJECT_TYPE_NODE_MASK:3`

Subobject type is [D3D12_NODE_MASK](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_node_mask).

> [!IMPORTANT]
> On some versions of the DirectX Runtime, specifying a node via [**D3D12_NODE_MASK**](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_node_mask) in a [**D3D12_STATE_SUBOBJECT**](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_state_subobject) with type **D3D12_STATE_SUBOBJECT_TYPE_NODE_MASK**, the runtime will incorrectly handle a node mask value of `0`, which should use node #1, which will lead to errors when attempting to use the state object later. Specify an explicit node value of 1, or omit the [**D3D12_NODE_MASK**](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_node_mask) subobject to avoid this issue.

### `D3D12_STATE_SUBOBJECT_TYPE_DXIL_LIBRARY:5`

Subobject type is [D3D12_DXIL_LIBRARY_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_dxil_library_desc).

### `D3D12_STATE_SUBOBJECT_TYPE_EXISTING_COLLECTION:6`

Subobject type is [D3D12_EXISTING_COLLECTION_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_existing_collection_desc).

### `D3D12_STATE_SUBOBJECT_TYPE_SUBOBJECT_TO_EXPORTS_ASSOCIATION:7`

Subobject type is [D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_subobject_to_exports_association).

### `D3D12_STATE_SUBOBJECT_TYPE_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION:8`

Subobject type is [D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_dxil_subobject_to_exports_association).

### `D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_SHADER_CONFIG:9`

Subobject type is [D3D12_RAYTRACING_SHADER_CONFIG](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_raytracing_shader_config).

### `D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG:10`

Subobject type is [D3D12_RAYTRACING_PIPELINE_CONFIG](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_raytracing_pipeline_config).

### `D3D12_STATE_SUBOBJECT_TYPE_HIT_GROUP:11`

Subobject type is [D3D12_HIT_GROUP_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_hit_group_desc)

### `D3D12_STATE_SUBOBJECT_TYPE_MAX_VALID`

The maximum valid subobject type value.
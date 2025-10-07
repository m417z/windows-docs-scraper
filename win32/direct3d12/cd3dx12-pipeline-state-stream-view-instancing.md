# CD3DX12_PIPELINE_STATE_STREAM_VIEW_INSTANCING structure

A helper structure used to wrap a [CD3DX12_VIEW_INSTANCING_DESC](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-view-instancing-desc) structure. Allows shaders to render to multiple views with a single draw call; useful for stereo vision or cubemap generation.

**CD3DX12_PIPELINE_STATE_STREAM_VIEW_INSTANCING** is a `typedef` specialization of the [CD3DX12_PIPELINE_STATE_STREAM_SUBOBJECT](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-subobject) template.

## Members

See [CD3DX12_PIPELINE_STATE_STREAM_SUBOBJECT](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-subobject) and [CD3DX12_VIEW_INSTANCING_DESC](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-view-instancing-desc).

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header | [D3dx12.h](https://github.com/microsoft/DirectX-Headers/blob/main/include/directx/d3dx12.h) |

## See also

* [Helper structures for Direct3D 12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)
* [CD3DX12_PIPELINE_STATE_STREAM_SUBOBJECT](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-subobject)
* [D3D12_PIPELINE_STATE_SUBOBJECT_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_pipeline_state_subobject_type)
* [D3DX12_VIEW_INSTANCING_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_versioned_root_signature_desc)
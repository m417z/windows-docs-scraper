# ID3D12GraphicsCommandList4::SetPipelineState1

## Description

Sets a state object on the command list.

## Parameters

### `pStateObject`

The state object to set on the command list. In the current release, this can only be of type [D3D12_STATE_OBJECT_TYPE_RAYTRACING_PIPELINE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_state_object_type).

## Remarks

This method can be called from graphics or compute command lists and bundles.

This method is an alternative to [ID3D12GraphicsCommandList::SetPipelineState](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-setpipelinestate), which is only defined for graphics and compute shaders. There is only one pipeline state active on a command list at a time, so either call sets the current pipeline state. The distinction between the calls is that each sets particular types of pipeline state only. In the current release, **SetPipelineState1** is only used for setting raytracing pipeline state.

## See also

[ID3D12GraphicsCommandList4](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12graphicscommandlist4)
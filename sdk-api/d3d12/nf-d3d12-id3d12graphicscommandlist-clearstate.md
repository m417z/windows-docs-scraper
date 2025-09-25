# ID3D12GraphicsCommandList::ClearState

## Description

Resets the state of a direct command list back to the state it was in when the command list was created.

## Parameters

### `pPipelineState` [in, optional]

Type: **[ID3D12PipelineState](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12pipelinestate)***

A pointer to the [ID3D12PipelineState](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12pipelinestate) object that contains the initial pipeline state for the command list.

## Remarks

It is invalid to call **ClearState** on a bundle. If an app calls **ClearState** on a bundle, the call to [Close](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-close) will return **E_FAIL**.

When **ClearState** is called, all currently bound resources are unbound. The primitive topology is set to [D3D_PRIMITIVE_TOPOLOGY_UNDEFINED](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_primitive_topology). Viewports, scissor rectangles, stencil reference value, and the blend factor are set to empty values (all zeros). Predication is disabled.

The app-provided pipeline state object becomes bound as the currently set pipeline state object.

## See also

[ID3D12GraphicsCommandList](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist)
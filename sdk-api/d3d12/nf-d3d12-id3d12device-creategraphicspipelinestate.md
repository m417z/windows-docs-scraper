# ID3D12Device::CreateGraphicsPipelineState

## Description

Creates a graphics pipeline state object.

## Parameters

### `pDesc` [in]

Type: **const [D3D12_GRAPHICS_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_graphics_pipeline_state_desc)***

A pointer to a [D3D12_GRAPHICS_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_graphics_pipeline_state_desc) structure that describes graphics pipeline state.

### `riid`

Type: **REFIID**

The globally unique identifier (**GUID**) for the pipeline state interface ([ID3D12PipelineState](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12pipelinestate)).
The **REFIID**, or **GUID**, of the interface to the pipeline state can be obtained by using the __uuidof() macro.
For example, __uuidof(ID3D12PipelineState) will get the **GUID** of the interface to a pipeline state.

### `ppPipelineState` [out]

Type: **void****

A pointer to a memory block that receives a pointer to the [ID3D12PipelineState](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12pipelinestate) interface for the pipeline state object.
The pipeline state object is an immutable state object. It contains no methods.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns **E_OUTOFMEMORY** if there is insufficient memory to create the pipeline state object.
See [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues) for other possible return values.

## See also

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)
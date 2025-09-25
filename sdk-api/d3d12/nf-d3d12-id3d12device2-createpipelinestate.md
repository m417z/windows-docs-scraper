# ID3D12Device2::CreatePipelineState

## Description

Creates a pipeline state object from a pipeline state stream description.

## Parameters

### `pDesc`

Type: **const [D3D12_PIPELINE_STATE_STREAM_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_pipeline_state_stream_desc)***

The address of a [D3D12_PIPELINE_STATE_STREAM_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_pipeline_state_stream_desc) structure that describes the pipeline state.

### `riid`

Type: **REFIID**

The globally unique identifier (**GUID**) for the pipeline state interface ([ID3D12PipelineState](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12pipelinestate)).

The **REFIID**, or **GUID**, of the interface to the pipeline state can be obtained by using the __uuidof() macro. For example, __uuidof(ID3D12PipelineState) will get the **GUID** of the interface to a pipeline state.

### `ppPipelineState` [out]

Type: **void****

[SAL](https://learn.microsoft.com/cpp/code-quality/annotating-function-parameters-and-return-values): `_COM_Outptr_`

A pointer to a memory block that receives a pointer to the [ID3D12PipelineState](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12pipelinestate) interface for the pipeline state object.

The pipeline state object is an immutable state object. It contains no methods.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns **E_OUTOFMEMORY** if there is insufficient memory to create the pipeline state object. See [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-graphics-reference-returnvalues) for other possible return values.

## Remarks

This function takes the pipeline description as a [D3D12_PIPELINE_STATE_STREAM_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_pipeline_state_stream_desc) and combines the functionality of the [ID3D12Device::CreateGraphicsPipelineState](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-creategraphicspipelinestate) and [ID3D12Device::CreateComputePipelineState](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createcomputepipelinestate) functions, which take their pipeline description as the less-flexible [D3D12_GRAPHICS_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_graphics_pipeline_state_desc) and [D3D12_COMPUTE_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_compute_pipeline_state_desc) structs, respectively.

## See also

See [**D3D12_PIPELINE_STATE_STREAM_DESC**](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_pipeline_state_stream_desc) for a description of the layout and behavior of a streaming pipeline desc.

[ID3D12Device2](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device2)
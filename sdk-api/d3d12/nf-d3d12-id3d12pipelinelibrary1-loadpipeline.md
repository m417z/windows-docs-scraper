## Description

Retrieves the requested PSO from the library. The pipeline stream description is matched against the library database, and remembered in order to prevent duplication of PSO contents.

## Parameters

### `pName` [in]

Type: **LPCWSTR**

[SAL](https://learn.microsoft.com/cpp/code-quality/annotating-function-parameters-and-return-values): `_In_`

The unique name of the PSO.

### `pDesc` [in]

Type: **const [D3D12_PIPELINE_STATE_STREAM_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_pipeline_state_stream_desc)***

[SAL](https://learn.microsoft.com/cpp/code-quality/annotating-function-parameters-and-return-values): `_In_`

Describes the required PSO using a [D3D12_PIPELINE_STATE_STREAM_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_pipeline_state_stream_desc) structure. This description is matched against the library database, and stored in order to prevent duplication of PSO contents.

### `riid`

Type: **REFIID**

Specifies a REFIID for the [ID3D12PipelineState](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12pipelinestate) object.

Your app should typically set this argument and the following argument, *ppPipelineState*, by using the macro IID_PPV_ARGS(&PSO1), where PSO1 is the name of the object.

### `ppPipelineState` [out]

Type: **void****

[SAL](https://learn.microsoft.com/cpp/code-quality/annotating-function-parameters-and-return-values): `_COM_Outptr_`

Specifies the pointer that will reference the PSO after the function successfully returns.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code, which can include E_INVALIDARG if the name doesn't exist or the stream description doesn't match the data in the library, and E_OUTOFMEMORY if the function is unable to allocate the resulting PSO.

## Remarks

This function takes the pipeline description as a [D3D12_PIPELINE_STATE_STREAM_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_pipeline_state_stream_desc) and is a replacement for the [ID3D12PipelineLibrary::LoadGraphicsPipeline](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12pipelinelibrary-loadgraphicspipeline) and [ID3D12PipelineLibrary::LoadComputePipeline](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12pipelinelibrary-loadcomputepipeline) functions, which take their pipeline description as the less-flexible [D3D12_GRAPHICS_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_graphics_pipeline_state_desc) and [D3D12_COMPUTE_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_compute_pipeline_state_desc) structs, respectively.

## See also

See [**D3D12_PIPELINE_STATE_STREAM_DESC**](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_pipeline_state_stream_desc) for a description of the layout and behavior of a streaming pipeline desc.

[ID3D12PipelineLibrary1](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12pipelinelibrary1)